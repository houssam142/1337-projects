#include "/usr/include/minilibx-linux/mlx.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#define WIN_W 640
#define WIN_H 480

// Simple 8x8 map
int worldMap[8][8] =
{
  {1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1}
};

typedef struct s_game {
    void    *mlx;
    void    *win;
    void    *img;
	void	*player;
    char    *addr;
    int     bpp;
    int     line_len;
    int     endian;
    void    *tex;
    char    *tex_addr;
    char    *play_addr;
    int     tex_w, tex_h;
    int     tex_bpp, tex_line, tex_end;
    int     pla_bpp, pla_line, pla_end;
    double  posX, posY;  // player position
    double  dirX, dirY;  // direction
    double  planeX, planeY; // camera plane
}   t_game;

void    my_pixel_put(t_game *g, int x, int y, int color)
{
    if (x < 0 || x >= WIN_W || y < 0 || y >= WIN_H) return;
    char *dst = g->addr + (y * g->line_len + x * (g->bpp / 8));
    *(unsigned int*)dst = color;
}

int get_tex_pixel(t_game *g, int x, int y)
{
    char *dst = g->tex_addr + (y * g->tex_line + x * (g->tex_bpp / 8));
    return (*(unsigned int*)dst);
}

void    render(t_game *g)
{
    g->img = mlx_new_image(g->mlx, WIN_W, WIN_H);
    g->addr = mlx_get_data_addr(g->img, &g->bpp, &g->line_len, &g->endian);

    for (int x = 0; x < WIN_W; x++)
    {
        double cameraX = 2 * x / (double)WIN_W - 1;
        double rayDirX = g->dirX + g->planeX * cameraX;
        double rayDirY = g->dirY + g->planeY * cameraX;

        int mapX = (int)g->posX;
        int mapY = (int)g->posY;

        double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
        double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);

        int stepX, stepY;
        double sideDistX, sideDistY;

        if (rayDirX < 0) { stepX = -1; sideDistX = (g->posX - mapX) * deltaDistX; }
        else { stepX = 1; sideDistX = (mapX + 1.0 - g->posX) * deltaDistX; }
        if (rayDirY < 0) { stepY = -1; sideDistY = (g->posY - mapY) * deltaDistY; }
        else { stepY = 1; sideDistY = (mapY + 1.0 - g->posY) * deltaDistY; }

        int hit = 0, side;
        while (hit == 0)
        {
            if (sideDistX < sideDistY) {
                sideDistX += deltaDistX; mapX += stepX; side = 0;
            } else {
                sideDistY += deltaDistY; mapY += stepY; side = 1;
            }
            if (worldMap[mapX][mapY] > 0) hit = 1;
        }

        double perpWallDist;
        if (side == 0) perpWallDist = (mapX - g->posX + (1 - stepX) / 2) / rayDirX;
        else           perpWallDist = (mapY - g->posY + (1 - stepY) / 2) / rayDirY;

        int lineHeight = (int)(WIN_H / perpWallDist);
        int drawStart = -lineHeight / 2 + WIN_H / 2;
        if (drawStart < 0) drawStart = 0;
        int drawEnd = lineHeight / 2 + WIN_H / 2;
        if (drawEnd >= WIN_H) drawEnd = WIN_H - 1;

        double wallX;
        if (side == 0) wallX = g->posY + perpWallDist * rayDirY;
        else           wallX = g->posX + perpWallDist * rayDirX;
        wallX -= floor(wallX);

        int texX = (int)(wallX * (double)g->tex_w);
        if (side == 0 && rayDirX > 0) texX = g->tex_w - texX - 1;
        if (side == 1 && rayDirY < 0) texX = g->tex_w - texX - 1;

        double step = 1.0 * g->tex_h / lineHeight;
        double texPos = (drawStart - WIN_H / 2 + lineHeight / 2) * step;

        for (int y = drawStart; y < drawEnd; y++)
        {
            int texY = (int)texPos & (g->tex_h - 1);
            texPos += step;
            int color = get_tex_pixel(g, texX, texY);
            if (side == 1) color = (color >> 1) & 8355711; // darken Y sides
            my_pixel_put(g, x, y, color);
        }
    }

    mlx_put_image_to_window(g->mlx, g->win, g->img, 0, 0);
    mlx_destroy_image(g->mlx, g->img);
}

int loop_hook(t_game *g)
{
    render(g);
    return (0);
}

int	close_win(int key, t_game *w)
{
	if (key == 0xff1b)
	{
		if (w->win)
			mlx_destroy_window(w->mlx, w->win);
		if (w->mlx)
		{
			mlx_destroy_display(w->mlx);
			free(w->mlx);
		}
		exit(0);
	}
}

int main(void)
{
    t_game g;

    g.mlx = mlx_init();
    g.win = mlx_new_window(g.mlx, WIN_W, WIN_H, "Mini Raycaster");

    g.posX = 3.5; g.posY = 3.5;
    g.dirX = -1; g.dirY = 0;
    g.planeX = 0; g.planeY = 0.66;

    // load a wall texture (must be power-of-2 size, e.g. 64x64 XPM)
    g.tex = mlx_xpm_file_to_image(g.mlx, "grey_stone.xpm", &g.tex_w, &g.tex_h);
    g.tex_addr = mlx_get_data_addr(g.tex, &g.tex_bpp, &g.tex_line, &g.tex_end);

    mlx_loop_hook(g.mlx, loop_hook, &g);
	// mlx_hook(g.win, 2, 1L << 0, key_press, &w);
	mlx_key_hook(g.win, close_win, &g);
    mlx_loop(g.mlx);
}
