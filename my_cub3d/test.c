/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssam <houssam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 15:53:14 by houssam           #+#    #+#             */
/*   Updated: 2025/08/23 20:10:14 by houssam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/usr/include/minilibx-linux/mlx.h"
#include <stdlib.h>

float x, y = 0.00;

typedef struct s_win
{
    void    *mlx;
    void    *win;
	void	*player_img;
}t_win;

void    init(t_win *w)
{
    w->mlx = NULL;
    w->win = NULL;
	w->player_img = NULL;
}

void	draw_player(t_win *w)
{
	mlx_put_image_to_window(w->mlx, w->win, w->player_img, x, y);
}

int	move_player(int key, t_win *w)
{
	mlx_clear_window(w->mlx, w->win);
	if (key == 65361) // Left arrow
        x -= 5.5;
    else if (key == 65362) // Up arrow
        y -= 5.5;
    else if (key == 65363) // Right arrow
        x += 5.5;
    else if (key == 65364) // Down arrow
        y += 5.5;
	draw_player(w);
	return 0;
}

int close_win(t_win *w)
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

int press(int key, t_win *w)
{
    if (key == 0xff1b)
        close_win(w);
	else
		move_player(key, w);
    return (0);
}

int main()
{
	int	img_w = 0;
	int	img_h = 0;
    t_win w;
    init(&w);
    w.mlx = mlx_init();
    if (!w.mlx)
        exit(1);
    w.win = mlx_new_window(w.mlx, 800, 800, "test");
    if (!w.win)
        exit(1);
    w.player_img = mlx_xpm_file_to_image(w.mlx, "walkDown_01.xpm", &img_w, &img_h);
	x = 800 / 2;
	y = 800 / 2;x
	draw_player(&w);
	mlx_put_image_to_window(w.mlx, w.win, w.player_img, 100, 100);
    mlx_hook(w.win, 2, 1L << 0, press, &w);
    mlx_hook(w.win, 17, 0, close_win, &w);
    mlx_loop(w.mlx);
}
