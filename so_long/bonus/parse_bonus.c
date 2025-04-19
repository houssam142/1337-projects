/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 16:20:09 by hounejja          #+#    #+#             */
/*   Updated: 2025/03/24 06:18:27 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_map_characters(char *c, t_game *w)
{
	int	i;

	i = 0;
	while (c[i])
	{
		if (c[i] == 'P')
			w->p++;
		if (c[i] == 'E')
			w->e++;
		if (c[i] == 'C')
			w->c++;
		if (c[i] == '\n' && c[i + 1] == '\n')
			return (0);
		if (c[i] == '\n' && !c[i + 1])
			return (0);
		else if (c[i] != 'P' && c[i] != 'E' && c[i] != 'C' && c[i] != '1'
			&& c[i] != '0' && c[i] != 'B' && c[i] != '\n')
			exit((write(2, "Error\nUnknown character\n", 25), free(c), 1));
		i++;
	}
	if (w->p != 1 || w->e != 1 || w->c < 1)
		return (0);
	return (1);
}

int	check_wall_b(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (!first_and_last_b(map[i]))
		{
			write(2, "Error\n", 6);
			write(2, "The map is not surrounded by walls\n", 35);
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_map_walls(char **map)
{
	if (!line_all_ones_b(map[0], '1') || !line_all_ones_b(map[tab_length_b(map)
				- 1], '1'))
	{
		write(2, "Error\n", 6);
		write(2, "The map is not enclosed by walls\n", 34);
		return (0);
	}
	return (1);
}

char	**check_map(char *map, t_game *w)
{
	char	*characters;
	char	**str;

	characters = get_map_characters_b(map);
	if (!characters)
		return (write(2, "Error\nempty map\n", 17), NULL);
	if (!check_map_characters(characters, w)
		|| *characters == '\n' || !*characters)
	{
		free(characters);
		raise_error_bonus();
		exit((write(2, "Missing a character or empty line or more char\n",
					48)));
	}
	str = ft_split_bonus(characters, '\n');
	if (!str)
		return (NULL);
	if (!check_wall_b(str) || !check_map_walls(str)
		|| !check_length_walls_b(str))
	{
		exit((ft_free(str), free(characters), 1));
	}
	ft_join_and_free_b(str, characters + ft_strlen(*str));
	free(characters);
	return (str);
}
