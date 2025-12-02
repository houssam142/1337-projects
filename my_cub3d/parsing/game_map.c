/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 02:59:26 by hounejja          #+#    #+#             */
/*   Updated: 2025/12/01 20:36:22 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	first_and_last(char *str)
{
	int	first;
	int	last;

	first = str[0];
	last = str[ft_strlen(str) - 2];
	if (first == '1' && last == '1')
		return (1);
	return (0);
}

void	replace_space_with_void(char *line, char c)
{
	int		i;
	char	left_cell;
	char	right_cell;

	ensure_line_closed(line, c);
	i = 0;
	while (line[i])
	{
		if (!is_allowed_char(line[i], c))
			print_error(MAP);
		if (line[i] == c)
		{
			left_cell = find_prev_map_cell(line, i - 1, c);
			right_cell = find_next_map_cell(line, i + 1, c);
			if ((left_cell && is_map_cell(left_cell, 0))
				|| (right_cell && is_map_cell(right_cell, 0)))
				print_error(WALL);
		}
		if (line[i] == c)
			line[i] = '1';
		i++;
	}
}

int	map_len(char **map)
{
	int		i;
	char	*line;

	i = 0;
	while (map[i])
	{
		line = map[i];
		line = ft_strtrim(line, " ");
		i++;
	}
	return (i);
}

int	len_till_first_line(char **map)
{
	int		i;
	char	*line;

	i = 0;
	while (map[i])
	{
		line = map[i];
		line = ft_strtrim(line, " ");
		if (line[0] == '1' || line[0] == '0')
			return (i);
		i++;
	}
	return (i);
}

char	**only_2d_map(char **map)
{
	char	**arr;

	int (i), (len), (j);
	i = len_till_first_line(map);
	len = map_len(&map[i]);
	arr = ft_malloc(sizeof(char *) * (len + 1));
	j = 0;
	while (j < len)
	{
		arr[j] = ft_strtrim(map[i], "\n");
		if (map[i][0] == '\0')
			break ;
		j++;
		i++;
	}
	arr[j] = NULL;
	return (arr);
}
