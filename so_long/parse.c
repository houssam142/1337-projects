/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 16:20:09 by hounejja          #+#    #+#             */
/*   Updated: 2025/03/24 03:32:51 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_characters(char *characters, t_win *w)
{
	int	i;

	i = 0;
	while (characters[i])
	{
		if (characters[i] == 'P')
			w->p++;
		if (characters[i] == 'E')
			w->e++;
		if (characters[i] == 'C')
			w->c++;
		if (characters[i] == '\n' && characters[i + 1] == '\n')
			return (0);
		if (characters[i] == '\n' && !characters[i + 1])
			return (0);
		else if (characters[i] != 'P' && characters[i] != 'E'
			&& characters[i] != 'C' && characters[i] != '1'
			&& characters[i] != '0' && characters[i] != '\n')
			exit((write(2, "Error\nUnknown character\n", 25), free(characters),
					1));
		i++;
	}
	if (w->p != 1 || w->e != 1 || w->c < 1)
		return (0);
	return (1);
}

int	check_map_rectangular(char **map)
{
	int	i;
	int	j;

	j = 0;
	i = ft_strlen(map[0]);
	while (map[j] != NULL)
		j++;
	if (i <= j)
	{
		write(2, "Error\n", 6);
		write(2, "The map is not enclosed by walls\n", 34);
		return (0);
	}
	return (1);
}

int	check_wall(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (!first_and_last(map[i]))
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
	if (!line_all_ones(map[0], '1') || !line_all_ones(map[tab_length(map) - 1],
			'1'))
	{
		write(2, "Error\n", 6);
		write(2, "The map is not enclosed by walls\n", 34);
		return (0);
	}
	return (1);
}

char	**check_map(char *map, t_win *w)
{
	char	*characters;
	char	**str;

	characters = get_map_characters(map);
	if (!characters)
		return (write(2, "Error\nmap is empty\n", 20), NULL);
	if (!check_map_characters(characters, w) || *characters == '\n'
		|| !*characters)
	{
		free(characters);
		raise_error();
		exit((write(2, "Missing a character or empty line\n", 35)));
	}
	str = ft_split(characters, '\n');
	if (!str)
		return (NULL);
	if (!check_wall(str) || !check_map_walls(str) || !check_length_walls(str))
	{
		exit((ft_free(str), free(characters), 1));
	}
	ft_join_and_free(str, characters + ft_strlen(*str));
	free(characters);
	return (str);
}
