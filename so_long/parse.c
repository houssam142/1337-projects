/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 16:20:09 by hounejja          #+#    #+#             */
/*   Updated: 2025/03/09 14:20:08 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_caracters(char *characters, t_win *w)
{
	int (i) = 0;
	while (characters[i])
	{
		if (characters[i] == 'P')
			w->p++;
		if (characters[i] == 'E')
			w->e++;
		if (characters[i] == 'C')
			w->c++;
		if (!characters[i + 1] && characters[i] == '\n')
			return (0);
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
		return (0);
	return (1);
}

int	check_wall(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (!first_and_last(map[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_map_walls(char **map)
{
	if (!line_all_ones(map[0], '1') || !line_all_ones(map[tab_length(map) - 1],
			'1'))
		return (0);
	return (1);
}

char	**check_map(char *map, t_win *w)
{
	char	*characters;
	char	**str;

	characters = get_map_caracters(map);
	if (!check_map_caracters(characters, w) || *characters == '\n'
		|| !*characters)
	{
		free(characters);
		raise_error();
	}
	str = ft_split(characters, '\n');
	if (!check_wall(str) || !check_map_rectangular(str) || !check_map_walls(str)
		|| !check_length_walls(str))
	{
		free(characters);
		ft_free(str);
		raise_error();
	}
	ft_join_and_free(str, characters + ft_strlen(*str));
	free(characters);
	return (str);
}
