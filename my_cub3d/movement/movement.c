/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 19:17:17 by hounejja          #+#    #+#             */
/*   Updated: 2025/09/07 15:04:22 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	is_passable(t_data *data, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)x;
	map_y = (int)y;
	if (map_x < 0 || map_x >= data->map_width
		|| map_y < 0 || map_y >= data->map_height)
		return (0);
	return (data->parse->map[(int)y][(int)x] == '0');
}

void	ft_movewasd_2(t_data *data)
{
	double	strafe_speed;
	double	new_x;
	double	new_y;

	strafe_speed = 0.02;
	if (data->move_right == 1)
	{
		new_x = data->x_player + data->plane_x * strafe_speed;
		new_y = data->y_player + data->plane_y * strafe_speed;
		if (is_passable(data, new_x, data->y_player))
			data->x_player = new_x;
		if (is_passable(data, data->x_player, new_y))
			data->y_player = new_y;
	}
	if (data->move_left == 1)
	{
		new_x = data->x_player - data->plane_x * strafe_speed;
		new_y = data->y_player - data->plane_y * strafe_speed;
		if (is_passable(data, new_x, data->y_player))
			data->x_player = new_x;
		if (is_passable(data, data->x_player, new_y))
			data->y_player = new_y;
	}
}

void	ft_move_wasd(t_data *data)
{
	double	move_speed;
	double	new_x;
	double	new_y;

	move_speed = 0.02;
	if (data->move_forward == 1)
	{
		new_x = data->x_player + data->dir_x * move_speed;
		new_y = data->y_player + data->dir_y * move_speed;
		if (is_passable(data, new_x, data->y_player))
			data->x_player = new_x;
		if (is_passable(data, data->x_player, new_y))
			data->y_player = new_y;
	}
	if (data->move_backward == 1)
	{
		new_x = data->x_player - data->dir_x * move_speed;
		new_y = data->y_player - data->dir_y * move_speed;
		if (is_passable(data, new_x, data->y_player))
			data->x_player = new_x;
		if (is_passable(data, data->x_player, new_y))
			data->y_player = new_y;
	}
	ft_movewasd_2(data);
}
