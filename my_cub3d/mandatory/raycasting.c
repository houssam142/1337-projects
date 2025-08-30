/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 21:24:17 by hounejja          #+#    #+#             */
/*   Updated: 2025/08/30 18:51:21 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	compute_distance(t_data *data, int pos_x, int pos_y)
{
	if (data->ray_dir_x == 0)
		data->delta_dist_x = 1e30;
	else
		data->delta_dist_x = fabs(1.0 / data->ray_dir_x);
	if (data->ray_dir_y == 0)
		data->delta_dist_y = 1e30;
	else
		data->delta_dist_y = fabs(1.0 / data->ray_dir_y);
	calculate_side_dist(data, pos_x, pos_y);
}

void	wall_pos(t_data *data, int side)
{
	double	wall_x;

	if (!side)
		wall_x = data->y_player + data->perp_dist * data->ray_dir_y;
	else
		wall_x = data->x_player + data->perp_dist * data->ray_dir_x;
	wall_x -= floor(wall_x);
	data->wall_x = wall_x;
}

void	pick_texture(t_data *data, int side)
{
	if (!side && data->step_x > 0)
		data->tex_addr = data->imgs->tex_addr_e;
	else if (!side && data->step_x < 0)
		data->tex_addr = data->imgs->tex_addr_w;
	else if (side && data->step_y > 0)
		data->tex_addr = data->imgs->tex_addr_s;
	else
		data->tex_addr = data->imgs->tex_addr_n;
}

void	calculate_tex_coor(t_data *data, int side)
{
	data->tex_x = (int)(data->wall_x * (double)TEX_WIDTH);
	if (data->tex_x >= TEX_WIDTH)
		data->tex_x = TEX_WIDTH - 1;
	if ((!side && data->ray_dir_x < 0) || (side == 1 && data->ray_dir_y > 0))
		data->tex_x = TEX_WIDTH - data->tex_x - 1;
}

void	compute_camera_x(t_data *data)
{
	int (i), (side), (pos_x), (pos_y);
	i = 0;
	init_play_pos_and_oreat(data);
	while (i < WIDTH)
	{
		side = 0;
		data->camera_x = 2.0 * i / (double)WIDTH - 1.0;
		data->ray_dir_x = data->dir_x + data->plane_x * data->camera_x;
		data->ray_dir_y = data->dir_y + data->plane_y * data->camera_x;
		pos_x = (int)data->x_player;
		pos_y = (int)data->y_player;
		compute_distance(data, pos_x, pos_y);
		while (pos_x >= 0 && pos_x < data->map_width
			&& pos_y >= 0 && pos_y < data->map_height
			&& data->parse->map[pos_y][pos_x] != '1')
			perform_dda(data, &pos_x, &pos_y, &side);
		calculate_perp_and_drawing(data, pos_x, pos_y, side);
		wall_pos(data, side);
		pick_texture(data, side);
		calculate_tex_coor(data, side);
		ft_draw(data, i, side);
		i++;
	}
}
