/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 20:43:59 by hounejja          #+#    #+#             */
/*   Updated: 2025/09/01 16:36:23 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	set_dir(char orientation, t_data *data)
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
	else if (orientation == 'W')
	{
		data->dir_x = -1;
		data->dir_y = 0;
	}
	else if (orientation == 'E')
	{
		data->dir_x = 1;
		data->dir_y = 0;
	}
	data->plane_x = -data->dir_x * 0.66;
	data->plane_y = data->dir_y * 0.66;
}

void	player_dir_setup(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->parse->map[i])
	{
		j = 0;
		while (data->parse->map[i][j])
		{
			if (data->parse->map[i][j] == 'N')
				set_dir('N', data);
			else if (data->parse->map[i][j] == 'S')
				set_dir('S', data);
			else if (data->parse->map[i][j] == 'W')
				set_dir('W', data);
			else if (data->parse->map[i][j] == 'E')
				set_dir('E', data);
		}
		i++;
	}
}
