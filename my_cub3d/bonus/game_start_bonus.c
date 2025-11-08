/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 20:42:30 by hounejja          #+#    #+#             */
/*   Updated: 2025/11/08 21:51:20 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	close_win(t_data *data)
{
	if (data->imgs->tex_img_e)
		mlx_destroy_image(data->mlx, data->imgs->tex_img_e);
	if (data->imgs->tex_img_n)
		mlx_destroy_image(data->mlx, data->imgs->tex_img_n);
	if (data->imgs->tex_img_s)
		mlx_destroy_image(data->mlx, data->imgs->tex_img_s);
	if (data->imgs->tex_img_w)
		mlx_destroy_image(data->mlx, data->imgs->tex_img_w);
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	free_garbage();
	exit(0);
}

int	key_press(int key, t_data *data)
{
	if (key == 0xff1b)
		close_win(data);
	if (key == W_KEY)
		data->move_forward = 1;
	if (key == S_KEY)
		data->move_backward = 1;
	if (key == A_KEY)
		data->move_left = 1;
	if (key == D_KEY)
		data->move_right = 1;
	if (key == LEFT_ARROW)
		data->rotate_left = 1;
	if (key == RIGHT_ARROW)
		data->rotate_right = 1;
	return (0);
}

int	key_release(int key, t_data *data)
{
	if (key == W_KEY)
		data->move_forward = 0;
	if (key == S_KEY)
		data->move_backward = 0;
	if (key == A_KEY)
		data->move_left = 0;
	if (key == D_KEY)
		data->move_right = 0;
	if (key == LEFT_ARROW)
		data->rotate_left = 0;
	if (key == RIGHT_ARROW)
		data->rotate_right = 0;
	return (0);
}

int	game_loop(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	ft_move_wasd(data);
	rotate_l_or_r(data);
	compute_camera_x(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	draw_minimap(data);
	draw_player(data);
	return (0);
}

void	start_game(t_data *data, t_parse *parse)
{
	init_window(data, parse);
	mlx_hook(data->win, 17, 0, close_win, data);
	mlx_hook(data->win, 6, 64, mouse_motion, data);
	mlx_hook(data->win, 2, 1, key_press, data);
	mlx_hook(data->win, 3, 2, key_release, data);
	mlx_loop_hook(data->mlx, game_loop, data);
	mlx_loop(data->mlx);
}
