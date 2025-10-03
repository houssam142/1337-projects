/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 02:59:48 by hounejja          #+#    #+#             */
/*   Updated: 2025/10/03 11:36:47 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

void	adjust_starting_cell(t_data *data)
{
	int	y;
	int	x;

	y = (int)data->y_player;
	x = (int)data->x_player;
	if (data->parse->map[y][x] == 'N' || data->parse->map[y][x] == 'S' ||
		data->parse->map[y][x] == 'E' || data->parse->map[y][x] == 'W')
		data->parse->map[y][x] = '0';
}

static void	init_data(t_data *data, t_parse *arg, t_img *img)
{
	data->mlx = NULL;
	data->win = NULL;
	data->img = NULL;
	data->parse = arg;
	data->move_forward = -1;
	data->move_right = -1;
	data->move_left = -1;
	data->move_backward = -1;
	data->rotate_left = -1;
	data->rotate_right = -1;
	data->direction = -1;
	data->mouse_x = 0;
	data->offset_x = 0;
	data->offset_y = 0;
	data->center_x = MM_SIZE / 2;
	data->center_y = MM_SIZE / 2;
	data->img = img;
	data->frames = 0;
}

int	parse_args(char **av, t_parse *data)
{
	char	**map;
	char	**sec_map;
	int		i;

	i = 0;
	check_extensions(av[1], data);
	map = ft_return_map_game(av[1]);
	sec_map = only_2d_map(map);
	check_map(sec_map);
	data->map = final_map(sec_map);
	if (!data->map)
		print_error(MAP);
	return (0);
}

int	main(int ac, char **av)
{
	t_parse	arg;
	t_data	data;
	t_img	img;

	if (ac != 2)
		return (ft_putstr_fd("Error\ninvalid arguments\n", 2), 1);
	ft_bzero(&arg, sizeof(t_parse));
	ft_bzero(&img, sizeof(t_img));
	if (parse_args(av, &arg))
		return (1);
	init_data(&data, &arg, &img);
	get_player_pos(&data);
	get_map_dimension(&data);
	start_game(&data, &arg);
	return (0);
}
