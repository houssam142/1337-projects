/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 01:28:23 by hounejja          #+#    #+#             */
/*   Updated: 2025/03/22 00:37:34 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_param(t_win *w)
{
	w->map = NULL;
	w->player = NULL;
	w->door = NULL;
	w->collec = NULL;
	w->wall = NULL;
	w->floor = NULL;
	w->e = 0;
	w->p = 0;
	w->c = 0;
	w->moves = 0;
	w->x_player = 0;
	w->y_player = 0;
	w->collected = 0;
	w->y_ext = 0;
	w->x_ext = 0;
}

void	ft_close(t_win *win)
{
	if (win->win)
		mlx_destroy_window(win->mlx, win->win);
	if (win->floor)
		mlx_destroy_image(win->mlx, win->floor);
	if (win->wall)
		mlx_destroy_image(win->mlx, win->wall);
	if (win->collec)
		mlx_destroy_image(win->mlx, win->collec);
	if (win->player)
		mlx_destroy_image(win->mlx, win->player);
	if (win->door)
		mlx_destroy_image(win->mlx, win->door);
	if (win->mlx)
	{
		mlx_destroy_display(win->mlx);
		free(win->mlx);
	}
	ft_free(win->map);
	exit(0);
}

static int	close_win(t_win *win)
{
	if (win->win)
		mlx_destroy_window(win->mlx, win->win);
	if (win->floor)
		mlx_destroy_image(win->mlx, win->floor);
	if (win->wall)
		mlx_destroy_image(win->mlx, win->wall);
	if (win->collec)
		mlx_destroy_image(win->mlx, win->collec);
	if (win->player)
		mlx_destroy_image(win->mlx, win->player);
	if (win->door)
		mlx_destroy_image(win->mlx, win->door);
	if (win->mlx)
	{
		mlx_destroy_display(win->mlx);
		free(win->mlx);
	}
	ft_free(win->map);
	exit(0);
}

static int	key_pressed(int key, t_win *win)
{
	collecting(win);
	if (key == 65307)
		ft_close(win);
	if (win->x_player == win->x_ext && win->y_player == win->y_ext
		&& win->collected != win->sum_of_collec)
		plays(key, win, win->door);
	else
		plays(key, win, win->floor);
	return (0);
}

void	new_window(t_win *w)
{
	w->mlx = mlx_init();
	if (!w->mlx)
	{
		write(2, "Error\nThe connection has failed\n", 33);
		free(w->mlx);
		ft_free(w->map);
		exit(1);
	}
	render(w);
	size_of_win(w);
	w->win = mlx_new_window(w->mlx, w->width * 32, w->height * 32, "./so_long");
	if (!w->win)
	{
		write(2, "Error\nCreation of window failed\n", 33);
		close_win_1(w);
	}
	render_images(w);
	mlx_hook(w->win, 2, 1L << 0, key_pressed, w);
	mlx_hook(w->win, 17, 0, close_win, w);
	mlx_loop(w->mlx);
	ft_free(w->map);
}
