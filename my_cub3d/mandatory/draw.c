/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 16:02:08 by hounejja          #+#    #+#             */
/*   Updated: 2025/10/07 11:04:43 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_mlx_put_pixel(t_data *data, int x, int y, unsigned int color)
{
	char	*dst;

	if (x < 0 || x > WIDTH || y < 0 || y > HEIGHT)
		return ;
	dst = data->addr + (y * data->line_size + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

char	*get_tex_addr(t_data *data, int side, int *tex_bpp, int *tex_line_size)
{
	if (side == 0)
	{
		if (data->ray_dir_x > 0)
			return (*tex_bpp = data->imgs->tex_bpp_e,
				*tex_line_size = data->imgs->tex_line_size_e,
				data->imgs->tex_addr_e);
		else
			return (*tex_bpp = data->imgs->tex_bpp_w,
				*tex_line_size = data->imgs->tex_line_size_w,
				data->imgs->tex_addr_w);
	}
	else
	{
		if (data->ray_dir_y > 0)
			return (*tex_bpp = data->imgs->tex_bpp_s,
				*tex_line_size = data->imgs->tex_line_size_s,
				data->imgs->tex_addr_s);
		else
			return (*tex_bpp = data->imgs->tex_bpp_n,
				*tex_line_size = data->imgs->tex_line_size_n,
				data->imgs->tex_addr_n);
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
	pixel = tex_addr + (tex_y * tex_line_size + data->tex_x * (tex_bpp / 8));
	color = *(unsigned int *)pixel;
	return (color);
}

void	ft_draw(t_data *data, int x, int side)
{
	unsigned int	color;

	int (tex_y), (y) = -1;
	double (step), (tex_pos);
	data->ceiling_color = rgb_string_to_int(data, 'C');
	step = (double)TEX_HEIGHT / data->line_height;
	tex_pos = (data->draw_start - HEIGHT / 2 + data->line_height / 2) * step;
	data->floor_color = rgb_string_to_int(data, 'F');
	while (++y < HEIGHT)
	{
		tex_y = (int)tex_pos;
		if (y < data->draw_start)
			ft_mlx_put_pixel(data, x, y, data->ceiling_color);
		if (y > data->draw_start && y < data->draw_end)
		{
			color = get_texture_pixel(data, tex_y, side);
			ft_mlx_put_pixel(data, x, y, color);
			tex_pos += step;
		}
		if (y > data->draw_end)
			ft_mlx_put_pixel(data, x, y, data->floor_color);
	}
}
