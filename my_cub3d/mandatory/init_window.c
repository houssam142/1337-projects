/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 18:36:57 by hounejja          #+#    #+#             */
/*   Updated: 2025/09/21 21:08:10 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_window(t_data *data, t_parse *parse)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		print_error(ERROR);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "./cub3D");
	if (!data->win)
		print_error(ERROR);
	data->imgs = ft_malloc(sizeof(t_img));
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	load_all_textures(data, parse);
	if (!data->img)
		print_error(ERROR);
	data->addr = mlx_get_data_addr(data->img, &data->bpp, &data->line_size,
			&data->endian);
	printf("%d\n", data->line_size);
	exit(1);
	if (!data->addr)
		print_error(ERROR);
}
