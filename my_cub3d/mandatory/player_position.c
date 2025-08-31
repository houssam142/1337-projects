/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 20:23:05 by hounejja          #+#    #+#             */
/*   Updated: 2025/08/31 20:16:55 by hounejja         ###   ########.fr       */
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
		data->dir_x = 0;
		data->dir_y = -1;
	}
	else if (orientation == 'S')
	{
		data->dir_x = 0;
		data->dir_y = 1;
	}
	else if (orientation == 'E')
	{
		data->dir_x = 1;
		data->dir_y = 0;
	}
	else if (orientation == 'W')
	{
		data->dir_x = -1;
		data->dir_y = 0;
	}
	data->plane_x = -data->dir_y * 0.66;
	data->plane_y = data->dir_x * 0.66;
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
				data->x_player = j + 0.5;
				data->y_player = i + 0.5;
				set_player_direction(data, data->parse->map[i][j]);
				data->parse->map[i][j] = '0';
				count++;
			}
			else if (ft_strchr("NSWE", data->parse->map[i][j]) && count)
				print_error(PLAYER, data->parse);
			j++;
		}
		i++;
	}
	if (!data->parse->map[i] && !count)
		print_error(MAP, data->parse);
}
