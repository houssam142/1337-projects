/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 18:29:55 by hounejja          #+#    #+#             */
/*   Updated: 2025/08/31 18:30:14 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	load_texture_img(void **img_ptr, t_data *data, char *path, int dir)
{
	int	width;
	int	height;

	*img_ptr = mlx_xpm_file_to_image(data->mlx, path, &width, &height);
	if (!*img_ptr)
	{
		ft_putstr_fd("Failed to load texture: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd("\n", 2);
		exit(1);
	}
	if (dir == 0)
	{
		data->imgs->tex_width_n = width;
		data->imgs->tex_height_n = height;
	}
	else if (dir == 1)
	{
		data->imgs->tex_width_s = width;
		data->imgs->tex_height_s = height;
	}
	else if (dir == 2)
	{
		data->imgs->tex_width_e = width;
		data->imgs->tex_height_e = height;
	}
	else if (dir == 3)
	{
		data->imgs->tex_width_w = width;
		data->imgs->tex_height_w = height;
	}
}

void	get_texture_addr(void *img, char **addr_ptr, t_data *data, int direction)
{
	char	*addr;
	int		bpp;
	int		line_size;
	int		endian;

	addr = mlx_get_data_addr(img, &bpp, &line_size, &endian);
	if (!addr)
	{
		ft_putstr_fd("Failed to get texture data address\n", 2);
		exit(1);
	}
	*addr_ptr = addr;
	if (direction == 0)
	{
		data->imgs->tex_bpp_n = bpp;
		data->imgs->tex_line_size_n = line_size;
		data->imgs->tex_endian_n = endian;
	}
	else if (direction == 1)
	{
		data->imgs->tex_bpp_s = bpp;
		data->imgs->tex_line_size_s = line_size;
		data->imgs->tex_endian_s = endian;
	}
	else if (direction == 2)
	{
		data->imgs->tex_bpp_e = bpp;
		data->imgs->tex_line_size_e = line_size;
		data->imgs->tex_endian_e = endian;
	}
	else if (direction == 3)
	{
		data->imgs->tex_bpp_w = bpp;
		data->imgs->tex_line_size_w = line_size;
		data->imgs->tex_endian_w = endian;
	}
}
