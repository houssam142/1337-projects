/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 18:29:55 by hounejja          #+#    #+#             */
/*   Updated: 2025/09/21 21:26:04 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	store_texture_dim(t_data *data, int dir, int width, int height)
{
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
    free_garbage();
		exit(1);
	}
	store_texture_dim(data, dir, width, height);
}

void	store_texture_params(t_data *data, int direction, int bpp,
		int line_size)
{
	if (direction == 0)
	{
		data->imgs->tex_bpp_n = bpp;
		data->imgs->tex_line_size_n = line_size;
	}
	else if (direction == 1)
	{
		data->imgs->tex_bpp_s = bpp;
		data->imgs->tex_line_size_s = line_size;
	}
	else if (direction == 2)
	{
		data->imgs->tex_bpp_e = bpp;
		data->imgs->tex_line_size_e = line_size;
	}
	else if (direction == 3)
	{
		data->imgs->tex_bpp_w = bpp;
		data->imgs->tex_line_size_w = line_size;
	}
}

void	get_texture_addr(void *img, char **addr_ptr, int *bpp_ptr,
	int *line_size_ptr)
{
	char	*addr;
	int		bpp;
	int		line_size;
	int		endian;

	addr = mlx_get_data_addr(img, &bpp, &line_size, &endian);
	if (!addr)
	{
		ft_putstr_fd("Failed to get texture data address\n", 2);
    free_garbage();
		exit(1);
	}
	*addr_ptr = addr;
	*bpp_ptr = bpp;
	*line_size_ptr = line_size;
}
