/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-mou <zael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 20:23:05 by hounejja          #+#    #+#             */
/*   Updated: 2025/10/27 16:16:22 by zael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	get_map_dimension(t_data *data)
{
	int	map_width;
	int	map_height;
	int	curr_width;

	map_height = 0;
	map_width = 0;
	while (data->parse->map[map_height])
	{
		curr_width = 0;
		while (data->parse->map[map_height][curr_width] != '\0')
			curr_width++;
		if (curr_width > map_width)
			map_width = curr_width;
		map_height++;
	}
	data->map_height = map_height;
	data->map_width = map_width;
}

void	set_player_direction(t_data *data, char orientation)
{
	if (orientation == 'N')
	{
		data->dir_x = 0.0;
		data->dir_y = -1.0;
	}
	else if (orientation == 'S')
	{
		data->dir_x = 0.0;
		data->dir_y = 1.0;
	}
	else if (orientation == 'E')
	{
		data->dir_x = 1.0;
		data->dir_y = 0.0;
	}
	else if (orientation == 'W')
	{
		data->dir_x = -1.0;
		data->dir_y = 0.0;
	}
	data->plane_x = -data->dir_y * 0.90;
	data->plane_y = data->dir_x * 0.90;
}

void	get_player_pos(t_data *data)
{
	int (i), (j), (count);
	i = 0;
	count = 0;
	while (data->parse->map[i])
	{
		j = 0;
		while (data->parse->map[i][j])
		{
			if (ft_strchr("NSWE", data->parse->map[i][j]) && !count)
			{
				data->x_player = (double)j + 0.1;
				data->y_player = (double)i + 0.1;
				set_player_direction(data, data->parse->map[i][j]);
				data->parse->map[i][j] = '0';
				count++;
			}
			else if (ft_strchr("NSWE", data->parse->map[i][j]) && count)
				print_error(PLAYER);
			j++;
		}
		i++;
	}
	if (!data->parse->map[i] && !count)
		print_error(MAP);
}
