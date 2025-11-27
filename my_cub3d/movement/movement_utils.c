/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 22:44:06 by hounejja          #+#    #+#             */
/*   Updated: 2025/11/27 23:17:38 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

double	get_check_pos(double pos, double dir, double buffer)
{
	if (dir > 0)
		return (pos + buffer);
	if (dir < 0)
		return (pos - buffer);
	return (pos);
}

int	is_passable(t_data *data, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)x;
	map_y = (int)y;
	if (map_x < 0 || map_x >= data->map_width || map_y < 0
		|| map_y >= data->map_height)
		return (0);
	return (data->parse->map[map_y][map_x] == '0');
}

static void	ft_movewasd_2(t_data *data)
{
	double	strafe_speed;
	double	buffer;

	strafe_speed = 0.026;
	buffer = 0.2;
	if (data->move_right == 1)
		move_strafe_right(data, strafe_speed, buffer);
	if (data->move_left == 1)
		move_strafe_left(data, strafe_speed, buffer);
}

void	ft_move_wasd(t_data *data)
{
	double	move_speed;
	double	buffer;

	move_speed = 0.03;
	buffer = 0.11;
	if (data->move_forward == 1)
		move_forward(data, move_speed, buffer);
	if (data->move_backward == 1)
		move_backward(data, move_speed, buffer);
	ft_movewasd_2(data);
}
