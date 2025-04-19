/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:06:04 by hounejja          #+#    #+#             */
/*   Updated: 2025/02/15 20:06:38 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_close(t_win *win)
{
	if (win->img_ptr)
		mlx_destroy_image(win->mlx, win->img_ptr);
	if (win->window)
		mlx_destroy_window(win->mlx, win->window);
	if (win->mlx)
	{
		mlx_destroy_display(win->mlx);
		free(win->mlx);
	}
	exit(0);
}

int	mouse_keys(t_win *win)
{
	if (win->img_ptr)
		mlx_destroy_image(win->mlx, win->img_ptr);
	if (win->window)
		mlx_destroy_window(win->mlx, win->window);
	if (win->mlx)
	{
		mlx_destroy_display(win->mlx);
		free(win->mlx);
	}
	exit(1);
}

int	key_pressed(int key, void *param)
{
	t_win	*win;

	win = (t_win *)param;
	if (key == XK_Escape)
		ft_close(win);
	return (1);
}

void	new_image(t_win *inf)
{
	inf->img_ptr = mlx_new_image(inf->mlx, inf->width, inf->height);
}

void	new_windows(t_win *win, t_struct **head)
{
	win->mlx = mlx_init();
	win->window = mlx_new_window(win->mlx, win->width, win->height,
			win->map_name);
	new_image(win);
	draw_lines(win, head);
	mlx_put_image_to_window(win->mlx, win->window, win->img_ptr, 0, 0);
	mlx_hook(win->window, 2, 1, key_pressed, win);
	mlx_hook(win->window, 17, 1, mouse_keys, win);
	free_list(head);
	mlx_loop(win->mlx);
}
