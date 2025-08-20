/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 02:59:48 by hounejja          #+#    #+#             */
/*   Updated: 2025/08/20 16:00:04 by hounejja         ###   ########.fr       */
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
	ft_free(data->map);
}

static void	init_parse(t_parse *data)
{
	data->count_identifiers = 0;
	data->flag = 0;
	data->path_e = NULL;
	data->path_n = NULL;
	data->path_s = NULL;
	data->path_w = NULL;
	data->celing_color = NULL;
	data->floor_color = NULL;
	data->map = NULL;
}

int	parse_args(char **av, t_parse *data)
{
	int	i;

	check_extensions(av[1], data);
	data->map = ft_return_map_game(av[1]);
	check_map(data);
	if (!data->map)
		print_error(MAP);
	i = 0;
	while (data->map[i] != NULL)
	{
		printf("%s", data->map[i]);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_parse	data;

	if (ac != 2)
		return (ft_putstr_fd("Error: invalid arguments\n", 2), 1);
	init_parse(&data);
	if (parse_args(av, &data))
		return (1);
	struct_free(&data);
	return (0);
}
