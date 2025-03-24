/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 17:53:03 by hounejja          #+#    #+#             */
/*   Updated: 2025/03/24 03:31:38 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_valid(char **new_map, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (new_map[i])
	{
		j = 0;
		while (new_map[i][j])
		{
			if (new_map[i][j] != '1' && new_map[i][j] != 'X'
				&& map[i][j] != '0')
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

int	check_file(char *file)
{
	int	len;
	int	fd_map;

	fd_map = open(file, O_RDONLY);
	if (fd_map == -1)
	{
		write(2, "Error\nmap doesn't exist\n", 25);
		exit(1);
	}
	len = ft_strlen(file);
	if (ft_strncmp(file + len - 4, ".ber", 4) || file[len - 5] == '/'
		|| len == 4)
		exit((write(2, "Error\nINVALID MAP\n", 19), close(fd_map), 1));
	return (fd_map);
}

int	main(int ac, char **av)
{
	t_win	w;
	char	**new_map;

	new_map = NULL;
	if (ac != 2)
		exit((write(2, "Error\nINVALID ARGUMENTS\n", 25), 1));
	init_param(&w);
	w.map = check_map(av[1], &w);
	if (!w.map)
		return (1);
	w.sum_of_collec = count_collectibles(&w);
	size_of_win(&w);
	get_position(&w, &w.x_player, &w.y_player, 'P');
	get_position(&w, &w.x_ext, &w.y_ext, 'E');
	new_map = ft_split(*w.map, '\n');
	if (!new_map)
		return (0);
	flood_fill(new_map, w.y_player, w.x_player, &w);
	check_valid(new_map, w.map);
	ft_free(new_map);
	new_window(&w);
}
