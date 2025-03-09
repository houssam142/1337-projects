/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 17:53:03 by hounejja          #+#    #+#             */
/*   Updated: 2025/03/09 15:38:26 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_valid(char **new_map, char **map)
{
	int (i), j;
	i = 0;
	while (new_map[i])
	{
		j = 0;
		while (new_map[i][j])
		{
			if (new_map[i][j] != '1' && new_map[i][j] != 'X')
			{
				ft_free(new_map);
				ft_free(map);
				write(2, "Map is invalid\n", 16);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	check_file(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (ft_strncmp(file + len - 4, ".ber", 4))
		exit((ft_printf("INVALID MAP\n")));
}

int	main(int ac, char **av)
{
	t_win	w;

	char **(new_map) = NULL;
	if (ac != 2)
		exit((ft_printf("INVALID ARGUMENTS")));
	init_param(&w);
	w.map = check_map(av[1], &w);
	w.sum_of_collec = count_collectibles(&w);
	size_of_win(&w);
	get_position(&w, &w.x_player, &w.y_player, 'P');
	get_position(&w, &w.x_ext, &w.y_ext, 'E');
	new_map = ft_split(*w.map, '\n');
	flood_fill(new_map, w.y_player, w.x_player, &w);
	check_valid(new_map, w.map);
	ft_free(new_map);
	new_window(av[1], &w);
}
