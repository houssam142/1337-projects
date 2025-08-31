/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 18:04:09 by hounejja          #+#    #+#             */
/*   Updated: 2025/08/31 19:14:04 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	load_north_texture(t_data *data, t_parse *parse)
{
	char	*addr;
	int		bpp;
	int		line_size;

	load_texture_img((void **)&data->imgs->tex_img_n, data, parse->path_n, 0);
	get_texture_addr(data->imgs->tex_img_n, &addr, &bpp, &line_size);
	data->imgs->tex_addr_n = addr;
	store_texture_params(data, 0, bpp, line_size);
}

static void	load_south_texture(t_data *data, t_parse *parse)
{
	char	*addr;
	int		bpp;
	int		line_size;

	load_texture_img((void **)&data->imgs->tex_img_s, data, parse->path_s, 1);
	get_texture_addr(data->imgs->tex_img_s, &addr, &bpp, &line_size);
	data->imgs->tex_addr_s = addr;
	store_texture_params(data, 1, bpp, line_size);
}

static void	load_east_texture(t_data *data, t_parse *parse)
{
	char	*addr;
	int		bpp;
	int		line_size;

	load_texture_img((void **)&data->imgs->tex_img_e, data, parse->path_e, 2);
	get_texture_addr(data->imgs->tex_img_e, &addr, &bpp, &line_size);
	data->imgs->tex_addr_e = addr;
	store_texture_params(data, 2, bpp, line_size);
}

static void	load_west_texture(t_data *data, t_parse *parse)
{
	char	*addr;
	int		bpp;
	int		line_size;

	load_texture_img((void **)&data->imgs->tex_img_w, data, parse->path_w, 3);
	get_texture_addr(data->imgs->tex_img_w, &addr, &bpp, &line_size);
	data->imgs->tex_addr_w = addr;
	store_texture_params(data, 3, bpp, line_size);
}

void	load_all_textures(t_data *data, t_parse *parse)
{
	load_north_texture(data, parse);
	load_south_texture(data, parse);
	load_east_texture(data, parse);
	load_west_texture(data, parse);
}
