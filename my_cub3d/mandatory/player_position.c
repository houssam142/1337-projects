/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 20:23:05 by hounejja          #+#    #+#             */
/*   Updated: 2025/08/30 15:30:29 by hounejja         ###   ########.fr       */
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

void	get_player_pos(t_data *data)
{
	int	i;
	int	j;
	int	count;

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
