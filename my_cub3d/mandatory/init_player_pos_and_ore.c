/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_pos_and_ore.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 16:09:44 by hounejja          #+#    #+#             */
/*   Updated: 2025/09/01 11:00:41 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	function_helper(t_data *data, char c)
{
	if (c == 'E')
	{
		data->dir_x = 1;
		data->dir_y = 0;
		data->plane_x = 0;
		data->plane_y = 0.66;
	}
	else if (c == 'W')
	{
		data->dir_x = -1;
		data->dir_y = 0;
		data->plane_x = 0;
		data->plane_y = -0.66;
	}
}

void	init_dir_and_fov(t_data *data, int col, int row, char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		data->x_player = col + 0.5;
		data->y_player = row + 0.5;
		if (c == 'N')
		{
			data->dir_x = 0;
			data->dir_y = -1;
			data->plane_x = 0.66;
			data->plane_y = 0;
		}
		else if (c == 'S')
		{
			data->dir_x = 0;
			data->dir_y = 1;
			data->plane_x = -0.66;
			data->plane_y = 0;
		}
		else if (c == 'E')
			function_helper(data, 'E');
		else if (c == 'W')
			function_helper(data, 'W');
	}
}

void	init_play_pos_and_oreat(t_data *data)
{
	int		row;
	int		col;
	int		len;
	char	c;

	row = 0;
	while (row < data->map_height)
	{
		col = 0;
		len = ft_strlen(data->parse->map[row]);
		while (col < data->map_width && col < len)
		{
			c = data->parse->map[row][col];
			init_dir_and_fov(data, col, row, c);
			col++;
		}
		row++;
	}
}
