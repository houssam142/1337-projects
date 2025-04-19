/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 23:30:49 by hounejja          #+#    #+#             */
/*   Updated: 2025/03/24 06:22:06 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	close_win_1_bonus(t_game *win)
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
	if (win->bkg)
		mlx_destroy_image(win->mlx, win->bkg);
	if (win->enemy)
		mlx_destroy_image(win->mlx, win->enemy);
	destroy_anim(win);
	if (win->mlx)
	{
		mlx_destroy_display(win->mlx);
		free(win->mlx);
	}
	ft_free(win->map);
	exit(1);
}

void	declare_sprites(t_game *w)
{
	w->sprite[0] = mlx_xpm_file_to_image(w->mlx,
			"texture/imgs/idle_00.xpm", &w->img_width,
			&w->img_height);
	w->sprite[1] = mlx_xpm_file_to_image(w->mlx,
			"texture/imgs/idle_04.xpm", &w->img_width,
			&w->img_height);
	w->sprite[2] = mlx_xpm_file_to_image(w->mlx,
			"texture/imgs/idle_05.xpm", &w->img_width,
			&w->img_height);
}

void	destroy_anim(t_game *w)
{
	if (w->sprite[0])
		mlx_destroy_image(w->mlx, w->sprite[0]);
	if (w->sprite[1])
		mlx_destroy_image(w->mlx, w->sprite[1]);
	if (w->sprite[2])
		mlx_destroy_image(w->mlx, w->sprite[2]);
}

int	update_anim(t_game *w)
{
	w->frame_count++;
	if (w->frame_count >= 2500)
	{
		w->curr_frame = (w->curr_frame + 1) % 3;
		w->frame_count = 0;
		draw_img(w, w->x_player, w->y_player, w->player);
	}
	draw_img(w, w->x_player, w->y_player, w->sprite[w->curr_frame]);
	return (0);
}
