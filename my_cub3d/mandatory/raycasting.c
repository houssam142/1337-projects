/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 21:24:17 by hounejja          #+#    #+#             */
/*   Updated: 2025/10/01 18:19:11 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	compute_distance(t_data *data, int pos_x, int pos_y)
{
	data->delta_dist_x = fabs(1.0 / data->ray_dir_x);
	data->delta_dist_y = fabs(1.0 / data->ray_dir_y);
	calculate_side_dist(data, pos_x, pos_y);
}

static void	wall_pos(t_data *data, int side)
{
	double	wall_x;

	if (!side)
		wall_x = data->y_player + data->perp_dist * data->ray_dir_y;
	else
		wall_x = data->x_player + data->perp_dist * data->ray_dir_x;
	wall_x -= floor(wall_x);
	data->wall_x = wall_x;
}

static void	pick_texture(t_data *data, int side)
{
	if (side && data->step_x > -1)
		data->tex_addr = data->imgs->tex_addr_e;
	else if (!side && data->step_x < -1)
		data->tex_addr = data->imgs->tex_addr_w;
	else if (!side && data->step_y > -1)
		data->tex_addr = data->imgs->tex_addr_s;
	else
		data->tex_addr = data->imgs->tex_addr_n;
}

void	calculate_tex_coor(t_data *data, int side)
{
	data->tex_x = (int)(data->wall_x * TEX_WIDTH);
	if ((!side && data->ray_dir_x < 0) || (side == 1 && data->ray_dir_y > 0))
		data->tex_x = TEX_WIDTH - data->tex_x - 1;
}

void	compute_camera_x(t_data *data)
{
	int (side), (pos_x), (pos_y), (hit), (i) = -1;
	while (++i < WIDTH - 1)
	{
		side = 0;
		hit = 0;
		calculate_raydir_fow(data, i);
		pos_x = (int)data->x_player;
		pos_y = (int)data->y_player;
		compute_distance(data, pos_x, pos_y);
		while (!hit)
		{
			if (perform_dda(data, &pos_x, &pos_y, &side))
			{
				hit = 1;
				break ;
			}
			if (data->parse->map[pos_y][pos_x] == '1')
				hit = 1;
		}
		calculate_perp_and_drawing(data, side);
		wall_pos(data, side);
		pick_texture(data, side);
		calculate_tex_coor(data, side);
		ft_draw(data, i, side);
	}
}
