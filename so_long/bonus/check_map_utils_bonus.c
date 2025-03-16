/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 23:57:19 by hounejja          #+#    #+#             */
/*   Updated: 2025/03/14 02:08:55 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	line_all_ones_b(char *line, char one)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != one)
			return (0);
		i++;
	}
	return (1);
}

int	tab_length_b(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int	check_length_walls_b(char **map)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(map[0]);
	while (map[i])
	{
		if (ft_strlen(map[i]) > len || ft_strlen(map[i]) < len)
		{
			write(2, "Error\n", 6);
			write(2, "The map is not surrounded by walls\n", 35);
			return (0);
		}
		i++;
	}
	return (1);
}

char	*get_map_characters_b(char *map)
{
	char	*line;
	char	*characters;
	int		fd_map;

	line = NULL;
	characters = NULL;
	fd_map = check_file_b(map);
	line = get_next_line(fd_map);
	if (!line)
		return (write(2, "Error\nmap is empty\n", 20), NULL);
	while (line)
	{
		if (!characters)
		{
			characters = ft_strdup(line);
			if (!characters)
				return (NULL);
		}
		else
			ft_join_and_free_b(&characters, line);
		free(line);
		line = get_next_line(fd_map);
	}
	return (characters);
}

int	first_and_last_b(char *str)
{
	int	first;
	int	last;

	first = str[0];
	last = str[ft_strlen(str) - 1];
	if (first == '1' && last == '1')
		return (1);
	return (0);
}
