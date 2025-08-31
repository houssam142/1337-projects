/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 18:04:09 by hounejja          #+#    #+#             */
/*   Updated: 2025/08/31 18:26:44 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	load_north_texture(t_data *data, t_parse *parse)
{
	load_texture_img((void **)&data->imgs->tex_img_n, data, parse->path_n, 0);
	get_texture_addr(data->imgs->tex_img_n, &data->imgs->tex_addr_n, data, 0);
}

static void	load_south_texture(t_data *data, t_parse *parse)
{
	load_texture_img((void **)&data->imgs->tex_img_s, data, parse->path_s, 1);
	get_texture_addr(data->imgs->tex_img_s, &data->imgs->tex_addr_s, data, 1);
}

static void	load_east_texture(t_data *data, t_parse *parse)
{
	load_texture_img((void **)&data->imgs->tex_img_e, data, parse->path_e, 2);
	get_texture_addr(data->imgs->tex_img_e, &data->imgs->tex_addr_e, data, 2);
}

static void	load_west_texture(t_data *data, t_parse *parse)
{
	load_texture_img((void **)&data->imgs->tex_img_w, data, parse->path_w, 3);
	get_texture_addr(data->imgs->tex_img_w, &data->imgs->tex_addr_w, data, 3);
}

void	load_all_textures(t_data *data, t_parse *parse)
{
	load_north_texture(data, parse);
	load_south_texture(data, parse);
	load_east_texture(data, parse);
	load_west_texture(data, parse);
}
