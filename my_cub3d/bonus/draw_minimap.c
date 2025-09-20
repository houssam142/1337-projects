/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 23:15:11 by hounejja          #+#    #+#             */
/*   Updated: 2025/09/19 20:19:10 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	draw_player(t_data *data)
{
	int	x;
	int	y;
	int	size;

	size = 6;
	y = -size / 2;
	while (y < size / 2)
	{
		x = -size / 2;
		while (x < size / 2)
		{
			ft_mlx_put_pixel(data, data->center_x + x, data->center_y + y,
				0xFF0000);
			x++;
		}
		y++;
	}
}

static void	draw_tile(t_data *data, int offset_x, int offset_y, int color)
{
	int	x;
	int	y;
	int	screen_x;
	int	screen_y;

	y = -1;
	while (++y < MM_TILE)
	{
		x = -1;
		while (++x < MM_TILE)
		{
			screen_x = offset_x + x;
			screen_y = offset_y + y;
			if (screen_x >= 0 && screen_x < MM_SIZE
				&& screen_y >= 0 && screen_y < MM_SIZE)
				ft_mlx_put_pixel(data, screen_x, screen_y, color);
		}
	}
}

void	draw_minimap(t_data *data)
{
	int (i), (screen_x), (screen_y), (color), (j);
	data->offset_x = data->x_player * MM_TILE - data->center_x;
	data->offset_y = data->y_player * MM_TILE - data->center_y;
	i = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_width - 1)
		{
			screen_x = j * MM_TILE - data->offset_x;
			screen_y = i * MM_TILE - data->offset_y;
			if (data->parse->map[i][j] == '1')
				color = 0xFFFFFF;
			else
				color = 0x000000;
			if (screen_x + MM_TILE >= 0 && screen_x < MM_SIZE
				&& screen_y + MM_TILE >= 0 && screen_y < MM_SIZE)
				draw_tile(data, screen_x, screen_y, color);
			j++;
		}
		i++;
	}
	draw_player(data);
}
