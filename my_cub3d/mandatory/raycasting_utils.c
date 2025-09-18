/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 18:40:39 by hounejja          #+#    #+#             */
/*   Updated: 2025/09/18 18:12:12 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	calculate_raydir_fow(t_data *data, int i)
{
	data->camera_x = 2.0 * i / (double)WIDTH - 1.0;
	data->ray_dir_x = data->dir_x + data->plane_x * data->camera_x;
	data->ray_dir_y = data->dir_y + data->plane_y * data->camera_x;
}

void	calculate_perp_and_drawing(t_data *data, int pos_x, int pos_y, int side)
{
	if (!side)
	{
		data->perp_dist = fabs(((double)pos_x - data->x_player + (1 - data->step_x)
					/ 2.0) / data->ray_dir_x);
	}
	else
	{
		data->perp_dist = fabs(((double)pos_y - data->y_player + (1 - data->step_y)
					/ 2.0) / data->ray_dir_y);
	}
	if (data->perp_dist < 0)
		data->perp_dist = -data->perp_dist;
	if (data->perp_dist < 0.001)
		data->perp_dist = 0.001;
	data->line_height = (int)(HEIGHT / data->perp_dist);
	data->draw_start = -data->line_height / 2 + HEIGHT / 2;
	data->draw_end = data->line_height / 2 + HEIGHT / 2;
	if (data->draw_start < 0)
		data->draw_start = 0;
	if (data->draw_end >= HEIGHT)
		data->draw_end = HEIGHT - 1;
}

void	calculate_side_dist(t_data *data, int pos_x, int pos_y)
{
	if (data->ray_dir_x < 0)
	{
		data->step_x = -1;
		data->side_dist_x = (data->x_player - pos_x) * data->delta_dist_x;
	}
	else
	{
		data->step_x = 1;
		data->side_dist_x = (pos_x + 1.0 - data->x_player) * data->delta_dist_x;
	}
	if (data->ray_dir_y < 0)
	{
		data->step_y = -1;
		data->side_dist_y = (data->y_player - pos_y) * data->delta_dist_y;
	}
	else
	{
		data->step_y = 1;
		data->side_dist_y = (pos_y + 1.0 - data->y_player) * data->delta_dist_y;
	}
}
