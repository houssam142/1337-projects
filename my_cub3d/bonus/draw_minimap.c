/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 23:15:11 by hounejja          #+#    #+#             */
/*   Updated: 2025/09/07 13:26:15 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	draw_player(t_data *data)
{
	int	px;
	int	py;
	int	x;
	int	y;
	int	size;

	size = 9;
	px = (int)(data->x_player * data->scale_x) - size - 1;
	py = (int)(data->y_player * data->scale_y) - size - 1;
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			ft_mlx_put_pixel(data, px + y, py + x, 0xFF0000);
			x++;
		}
		y++;
	}
}

static void	draw_tile(t_data *data, int i, int j)
{
	int	x;
	int	y;
	int	tile_width;
	int	tile_height;
	int	color;

	if (data->parse->map[i][j] == '1')
		color = 0xFFFFFF;
	else
		color = 0x000000;
	tile_width = (int)data->scale_x;
	tile_height = (int)data->scale_y;
	y = 0;
	while (y < tile_height)
	{
		x = 0;
		while (x < tile_width)
		{
			ft_mlx_put_pixel(data, j * tile_width + x, i * tile_height + y,
				color);
			x++;
		}
		y++;
	}
}

void	draw_minimap(t_data *data)
{
	int	i;
	int	j;

	data->scale_x = (double)170 / (data->map_width + 1);
	data->scale_y = (double)170 / (data->map_height + 1);
	i = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_width)
		{
			draw_tile(data, i, j);
			j++;
		}
		i++;
	}
	draw_player(data);
}
