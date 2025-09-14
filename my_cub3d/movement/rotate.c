/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 09:30:19 by hounejja          #+#    #+#             */
/*   Updated: 2025/09/13 09:37:17 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	rotate_l_or_r(t_data *data)
{
	double	rot_speed;
	double	old_dir_x;
	double	old_dir_y;
	double	old_plane_x;
	double	old_plane_y;

	rot_speed = 0.015;
	if (data->rotate_left == 1)
		rot_speed *= -1;
	else if (data->rotate_right == 1)
		rot_speed *= 1;
	else
		return ;
	old_dir_x = data->dir_x;
	old_dir_y = data->dir_y;
	old_plane_x = data->plane_x;
	old_plane_y = data->plane_y;
	data->dir_x = old_dir_x * cos(rot_speed) - old_dir_y * sin(rot_speed);
	data->dir_y = old_dir_x * sin(rot_speed) + old_dir_y * cos(rot_speed);
	data->plane_x = old_plane_x * cos(rot_speed) - old_plane_y * sin(rot_speed);
	data->plane_y = old_plane_x * sin(rot_speed) + old_plane_y * cos(rot_speed);
}
