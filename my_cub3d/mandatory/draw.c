/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 16:02:08 by hounejja          #+#    #+#             */
/*   Updated: 2025/08/30 18:28:41 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_mlx_put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = data->addr + (y * data->line_size + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

char	*get_tex_addr(t_data *data, int side, int *tex_bpp, int *tex_line_size)
{
	if (side == 0)
	{
		if (data->ray_dir_x > 0)
		{
			*tex_bpp = data->imgs->tex_bpp_e;
			*tex_line_size = data->imgs->tex_line_size_e;
			return (data->imgs->tex_addr_e);
		}
		else
		{
			*tex_bpp = data->imgs->tex_bpp_w;
			*tex_line_size = data->imgs->tex_line_size_w;
			return (data->imgs->tex_addr_w);
		}
	}
	else
	{
		if (data->ray_dir_y > 0)
		{
			*tex_bpp = data->imgs->tex_bpp_s;
			*tex_line_size = data->imgs->tex_line_size_s;
			return (data->imgs->tex_addr_s);
		}
		else
		{
			*tex_bpp = data->imgs->tex_bpp_n;
			*tex_line_size = data->imgs->tex_line_size_n;
			return (data->imgs->tex_addr_n);
		}
	}
}

int	get_texture_pixel(t_data *data, int tex_y, int side)
{
	char	*tex_addr;
	char	*pixel;
	int		color;
	int		tex_bpp;
	int		tex_line_size;

	tex_addr = get_tex_addr(data, side, &tex_bpp, &tex_line_size);
	if (data->tex_x < 0)
		data->tex_x = 0;
	if (data->tex_x >= TEX_WIDTH)
		data->tex_x = TEX_WIDTH - 1;
	if (tex_y < 0)
		tex_y = 0;
	if (tex_y >= TEX_HEIGHT)
		tex_y = TEX_HEIGHT - 1;
	pixel = tex_addr + (tex_y * tex_line_size + data->tex_x * (tex_bpp / 8));
	color = *(unsigned int *)pixel;
	return (color);
}

void	ft_draw(t_data *data, int x, int side)
{
	double	step;
	int		y;
	int		tex_y;
	int		color;
	double	tex_pos;

	y = 0;
	data->ceiling_color = rgb_string_to_int(data, 'C');
	step = (double)TEX_HEIGHT / data->line_height;
	tex_pos = (data->draw_start - HEIGHT / 2 + data->line_height / 2) * step;
	data->floor_color = rgb_string_to_int(data, 'F');
	while (y < data->draw_start)
	{
		ft_mlx_put_pixel(data, x, y, data->ceiling_color);
		y++;
	}
	y = data->draw_start;
	while (y < data->draw_end)
	{
		tex_y = (int)tex_pos;
		if (tex_y >= TEX_HEIGHT)
			tex_y = TEX_HEIGHT - 1;
		color = get_texture_pixel(data, tex_y, side);
		ft_mlx_put_pixel(data, x, y, color);
		tex_pos += step;
		y++;
	}
	y = data->draw_end;
	while (y < HEIGHT)
	{
		ft_mlx_put_pixel(data, x, y, data->floor_color);
		y++;
	}
}
