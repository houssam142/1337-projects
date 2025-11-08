/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-mou <zael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 05:05:20 by hounejja           #+#    #+#             */
/*   Updated: 2025/11/08 21:33:49 by zael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	find_real_lines(char **map, int *real_lines)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i][0] && map[i][0] != '\n')
			(*real_lines)++;
		i++;
	}
}

static int	arr_len(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

static int	arr_len_till_char(char **map)
{
	int		i;
	char	*line;

	i = 0;
	line = ft_strtrim(map[i], " ");
	while (line)
	{
		line = ft_strtrim(map[i], " ");
		if (!line || line[0] != '1')
			return (i);
		i++;
	}
	return (i);
}

static void	check_after_eo_map(char **map)
{
	int	i;
	int	len;

	i = 0;
	len = arr_len(map);
	while (i < len)
	{
		map[i] = ft_strtrim(map[i], " \n");
		if (map[i][0])
			print_error(WALL);
		i++;
	}
}

void	check_map(char **map)
{
	int		i;
	int		size;

	i = 0;
	size = arr_len_till_char(map);
	if (!line_all_ones(map[0], '1') || !line_all_ones(map[size - 1], '1'))
		print_error(WALL);
	while (map[i])
	{
		replace_space_with_void(map[i], ' ');
		if (map[i][0] != '1')
			check_after_eo_map(&map[i]);
		i++;
	}
	if (i < size)
		print_error(WALL);
}
