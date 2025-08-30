/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 02:59:48 by hounejja          #+#    #+#             */
/*   Updated: 2025/08/30 16:54:12 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

void	struct_free(t_parse *data)
{
	free(data->path_e);
	free(data->path_n);
	free(data->path_s);
	free(data->path_w);
	free(data->celing_color);
	free(data->floor_color);
}

static void	init_data(t_data *data, t_parse *arg, t_img *img)
{
	data->mlx = NULL;
	data->win = NULL;
	data->img = NULL;
	data->parse = arg;
	data->img = img;
}

int	parse_args(char **av, t_parse *data)
{
	char	**map;

	check_extensions(av[1], data);
	map = ft_return_map_game(av[1], data);
	check_map(map, data);
	data->map = only_2d_map(map);
	if (!data->map)
		print_error(MAP, data);
	return (0);
}

int	main(int ac, char **av)
{
	t_parse	arg;
	t_data	data;
	t_img	img;

	if (ac != 2)
		return (ft_putstr_fd("Error: invalid arguments\n", 2), 1);
	bzero(&arg, sizeof(t_parse));
	bzero(&img, sizeof(t_img));
	if (parse_args(av, &arg))
		return (1);
	init_data(&data, &arg, &img);
	get_player_pos(&data);
	get_map_dimension(&data);
	start_game(&data, &arg);
	ft_free(arg.map);
	return (0);
}
