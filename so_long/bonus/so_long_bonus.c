/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 17:53:03 by hounejja          #+#    #+#             */
/*   Updated: 2025/03/24 03:40:04 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	check_valid_bonus(char **new_map, char **map)
{
	int (i), j;
	i = 0;
	while (new_map[i])
	{
		j = 0;
		while (new_map[i][j])
		{
			if (new_map[i][j] != '1' && new_map[i][j] != 'X'
				&& map[i][j] != '0' && map[i][j] != 'B')
			{
				ft_free(new_map);
				ft_free(map);
				write(2, "Error\nMap is invalid\n", 22);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

int	check_file_b(char *file)
{
	int		len;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Error\nmap doesn't exist\n", 25);
		exit(1);
	}
	len = ft_strlen(file);
	if (ft_strncmp_bonus(file + len - 4, ".ber", 4) || file[len - 5] == '/'
		|| len == 4)
		exit((write(2, "Error\nINVALID MAP\n", 19), close(fd), 1));
	return (fd);
}

int	main(int ac, char **av)
{
	t_game	w;
	char	**new_map;

	new_map = NULL;
	if (ac != 2)
		exit((write(2, "Error\nInvalid arguments\n", 25), 1));
	init_param(&w);
	w.map = check_map(av[1], &w);
	if (!w.map)
		return (1);
	w.sum_of_collec = count_collectibles(&w);
	size_of_win(&w);
	get_position(&w, &w.x_player, &w.y_player, 'P');
	get_position(&w, &w.x_ext, &w.y_ext, 'E');
	get_position(&w, &w.enemy_x, &w.enemy_y, 'B');
	new_map = ft_split_bonus(*w.map, '\n');
	if (!new_map)
		return (1);
	flood_fill_bonus(new_map, w.y_player, w.x_player, &w);
	check_valid_bonus(new_map, w.map);
	ft_free(new_map);
	new_window_bonus(&w);
	return (0);
}
