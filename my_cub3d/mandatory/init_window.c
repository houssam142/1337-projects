/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 18:36:57 by hounejja          #+#    #+#             */
/*   Updated: 2025/09/21 20:17:42 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_window(t_data *data, t_parse *parse)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		ft_putstr_fd("Error\nthe connection has failed\n", 2);
		ft_free(data->parse->map);
		exit(1);
	}
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "./cub3D");
	if (!data->win)
		exit(1);
	data->imgs = ft_malloc(sizeof(t_img));
	if (!data->imgs)
		exit(1);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	load_all_textures(data, parse);
	if (!data->img)
	{
		ft_putstr_fd("Error\nthe image can't be created", 2);
		exit(1);
	}
	data->addr = mlx_get_data_addr(data->img, &data->bpp, &data->line_size,
			&data->endian);
	if (!data->addr)
		exit(1);
}
