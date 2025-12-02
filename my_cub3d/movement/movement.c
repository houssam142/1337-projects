/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 19:17:17 by hounejja          #+#    #+#             */
/*   Updated: 2025/11/28 18:58:41 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	move_strafe_right(t_data *data, double strafe_speed, double buffer)
{
	double	new_x;
	double	new_y;
	double	check_x;
	double	check_y;

	new_x = data->x_player + data->plane_x * strafe_speed;
	new_y = data->y_player + data->plane_y * strafe_speed;
	check_x = get_check_pos(new_x, data->plane_x, buffer);
	check_y = get_check_pos(new_y, data->plane_y, buffer);
	if (is_passable(data, check_x, data->y_player))
		data->x_player = new_x;
	if (is_passable(data, data->x_player, check_y))
		data->y_player = new_y;
}

void	move_strafe_left(t_data *data, double strafe_speed, double buffer)
{
	double	new_x;
	double	new_y;
	double	check_x;
	double	check_y;

	new_x = data->x_player - data->plane_x * strafe_speed;
	new_y = data->y_player - data->plane_y * strafe_speed;
	check_x = get_check_pos(new_x, -data->plane_x, buffer);
	check_y = get_check_pos(new_y, -data->plane_y, buffer);
	if (is_passable(data, check_x, data->y_player))
		data->x_player = new_x;
	if (is_passable(data, data->x_player, check_y))
		data->y_player = new_y;
}

void	move_forward(t_data *data, double move_speed, double buffer)
{
	double	new_x;
	double	new_y;
	double	check_x;
	double	check_y;

	new_x = data->x_player + data->dir_x * move_speed;
	new_y = data->y_player + data->dir_y * move_speed;
	check_x = get_check_pos(new_x, data->dir_x, buffer);
	check_y = get_check_pos(new_y, data->dir_y, buffer);
	if (is_passable(data, check_x, data->y_player))
		data->x_player = new_x;
	if (is_passable(data, data->x_player, check_y))
		data->y_player = new_y;
}

void	move_backward(t_data *data, double move_speed, double buffer)
{
	double	new_x;
	double	new_y;
	double	check_x;
	double	check_y;

	new_x = data->x_player - data->dir_x * move_speed;
	new_y = data->y_player - data->dir_y * move_speed;
	check_x = get_check_pos(new_x, -data->dir_x, buffer);
	check_y = get_check_pos(new_y, -data->dir_y, buffer);
	if (is_passable(data, check_x, data->y_player))
		data->x_player = new_x;
	if (is_passable(data, data->x_player, check_y))
		data->y_player = new_y;
}
