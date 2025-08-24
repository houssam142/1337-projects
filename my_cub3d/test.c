/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 15:53:14 by houssam           #+#    #+#             */
/*   Updated: 2025/08/24 17:49:37 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include <stdlib.h>

float x, y = 0.00;

typedef struct s_win
{
	void	*mlx;
	void	*win;
	void	*player_img;
	void	*img;
	char	*addr;
	int     bits_per_pixel;
    int     line_length;
    int     endian;
}			t_win;

void	init(t_win *w)
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
	if (key == 0x61) // Left arrow
		x -= 5.5;
	else if (key == 0x77) // Up arrow
		y -= 5.5;
	else if (key == 0x64)
		x += 5.5;
	else if (key == 0x73) // Down arrow
		y += 5.5;
	draw_player(w);
	return (0);
}

int	close_win(t_win *w)
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

int	press(int key, t_win *w)
{
	if (key == 0xff1b)
		close_win(w);
	// else
	// 	move_player(key, w);
	return (0);
}

void	my_mlx_pixel_put(t_win *w, int x, int y, int color)
{
	char	*dst;

	dst = w->addr + (y * w->line_length + x * (w->bits_per_pixel * 8));
	*(unsigned int *)dst = color;
}

int	main(void)
{
	int		img_w;
	int		img_h;
	t_win	w;

	img_w = 0;
	img_h = 0;
	init(&w);
	w.mlx = mlx_init();
	if (!w.mlx)
		exit(1);
	w.win = mlx_new_window(w.mlx, 800, 800, "test");
	if (!w.win)
		exit(1);
	w.img = mlx_new_image(w.mlx, 800, 800);
	w.addr = mlx_get_data_addr(w.img, &w.bits_per_pixel, &w.line_length, &w.endian);
	// w.player_img = mlx_xpm_file_to_image(w.mlx, "walkDown_01.xpm", &img_w,
	// 		&img_h);
	for (int x = 0; x < 786; x++)
	{
		for (int y = 0; y < 770; y++)
			my_mlx_pixel_put(&w, x, y, 0x00FFF0);
	}
	// x = 800 / 2;
	// y = 800 / 2;
	mlx_put_image_to_window(w.mlx, w.win, w.img, 0, 0);
	// draw_player(&w);
	mlx_hook(w.win, 2, 1L << 0, press, &w);
	mlx_hook(w.win, 17, 0, close_win, &w);
	mlx_loop(w.mlx);
}
