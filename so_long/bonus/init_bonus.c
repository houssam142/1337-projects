/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 01:28:23 by hounejja          #+#    #+#             */
/*   Updated: 2025/03/20 17:27:15 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_param(t_game *w)
{
	w->map = NULL;
	w->enemy = NULL;
	w->player = NULL;
	w->bkg = NULL;
	w->str = NULL;
	w->door = NULL;
	w->collec = NULL;
	w->wall = NULL;
	w->floor = NULL;
	w->e = 0;
	w->p = 0;
	w->c = 0;
	w->moves = 0;
	w->enemy_x = 0;
	w->enemy_y = 0;
	w->x_player = 0;
	w->y_player = 0;
	w->collected = 0;
	w->y_ext = 0;
	w->x_ext = 0;
}

void	ft_close(t_game *win)
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
	if (win->enemy)
		mlx_destroy_image(win->mlx, win->enemy);
	if (win->bkg)
		mlx_destroy_image(win->mlx, win->bkg);
	if (win->mlx)
	{
		mlx_destroy_display(win->mlx);
		free(win->mlx);
	}
	ft_free(win->map);
	exit(0);
}

static int	close_win(t_game *win)
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
	if (win->enemy)
		mlx_destroy_image(win->mlx, win->enemy);
	if (win->bkg)
		mlx_destroy_image(win->mlx, win->bkg);
	if (win->mlx)
	{
		mlx_destroy_display(win->mlx);
		free(win->mlx);
	}
	ft_free(win->map);
	exit(0);
}

static int	key_pressed(int key, t_game *win)
{
	collecting(win);
	if (key == 65307)
	{
		free(win->str);
		ft_close(win);
	}
	if (win->x_player == win->x_ext && win->y_player == win->y_ext
		&& win->collected != win->sum_of_collec)
		plays(key, win, win->door);
	else
		plays(key, win, win->floor);
	return (0);
}

void	new_window_bonus(t_game *w)
{
	w->mlx = mlx_init();
	if (!w->mlx)
	{
		free(w->mlx);
		ft_free(w->map);
		exit(1);
	}
	render_bonus(w);
	size_of_win(w);
	w->win = mlx_new_window(w->mlx, w->width * 32, w->height * 32,
			"./so_long_bonus");
	if (!w->win)
	{
		mlx_destroy_display(w->mlx);
		free(w->mlx);
		ft_free(w->map);
		exit(1);
	}
	render_images(w);
	put(w);
	mlx_hook(w->win, 2, 1, key_pressed, w);
	mlx_hook(w->win, 17, 0, close_win, w);
	mlx_loop(w->mlx);
	ft_free(w->map);
}
