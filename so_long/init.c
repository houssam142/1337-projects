/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 01:28:23 by hounejja          #+#    #+#             */
/*   Updated: 2025/03/09 14:19:52 by hounejja         ###   ########.fr       */
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
	if (win->collected == win->sum_of_collec)
		ft_printf("We have a winner\n");
	ft_free(win->map);
	exit(0);
}

int	close_win(t_win *win)
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

int	key_pressed(int key, t_win *win)
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

void	new_window(char *file, t_win *w)
{
	w->mlx = mlx_init();
	w->win = mlx_new_window(w->mlx, w->width * 32, w->height * 32, file);
	render(w);
	render_images(w);
	mlx_hook(w->win, 2, 1, key_pressed, w);
	mlx_hook(w->win, 17, 0, close_win, w);
	mlx_loop(w->mlx);
	ft_free(w->map);
}
