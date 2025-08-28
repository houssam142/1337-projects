/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start->c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student->42->fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 09:41:16 by houssam           #+#    #+#             */
/*   Updated: 2025/08/28 13:54:36 by hounejja         ###   ########->fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int  close_win(t_data *data)
{
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		// free(data->mlx);
	}
	exit(0);
}

// static int  key_press(int key, t_data *data)
// {
//     if (key == 0xff1b)
// 	{
// 		if (data->img)
// 			mlx_destroy_image(data->mlx, data->img)
// 		if (data->win)
// 			mlx_destroy_window(data->mlx, data->win);
// 		if (data->mlx)
// 		{
// 			mlx_destroy_display(data->mlx);
// 			free(data->mlx);
// 		}
// 		exit(0);
// 	}
//     return (0);
// }

void    start_game(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		ft_putstr_fd("Error\nthe connection has failed\n", 2);
		exit(1);
	}
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "./cub3D");
	if (!data->win)
	{
		ft_putstr_fd("Error\nthe window can't open\n", 2);
		exit(1);
	}
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img)
	{
		ft_putstr_fd("Error\nthe image can't be created", 2);
		exit(1);
	}
	data->addr = mlx_get_data_addr(data->img, &data->bpp, &data->line_size, &data->endian);
	if (!data->addr)
	    exit(1);
}
