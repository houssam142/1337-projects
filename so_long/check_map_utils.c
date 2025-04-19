/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 23:57:19 by hounejja          #+#    #+#             */
/*   Updated: 2025/03/24 03:54:03 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	line_all_ones(char *line, char one)
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

int	tab_length(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int	check_length_walls(char **map)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(map[0]);
	while (map[i])
	{
		if ((ft_strlen(map[i]) > len || ft_strlen(map[i]) < len))
		{
			write(2, "Error\n", 6);
			write(2, "Not the same length\n", 21);
			return (0);
		}
		i++;
	}
	return (1);
}

char	*get_map_characters(char *map)
{
	char	*line;
	char	*characters;
	int		fd_map;

	line = NULL;
	characters = NULL;
	fd_map = check_file(map);
	line = get_next_line(fd_map);
	if (!line)
		return (close(fd_map), NULL);
	while (line)
	{
		if (!characters)
		{
			characters = ft_strdup(line);
			if (!characters)
				return (close(fd_map), free(line), NULL);
		}
		else
			ft_join_and_free(&characters, line);
		free(line);
		line = get_next_line(fd_map);
	}
	close(fd_map);
	return (characters);
}

int	first_and_last(char *str)
{
	int	first;
	int	last;

	first = str[0];
	last = str[ft_strlen(str) - 1];
	if (first == '1' && last == '1')
		return (1);
	return (0);
}
