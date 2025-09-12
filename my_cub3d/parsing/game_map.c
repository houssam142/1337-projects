/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 02:59:26 by hounejja          #+#    #+#             */
/*   Updated: 2025/09/12 13:23:22 by hounejja         ###   ########.fr       */
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

static void	replace_space_with_void(char *line, char c)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == c)
			line[i] = '1';
		i++;
	}
}

static int	map_len(char **map)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		map[i] = ft_strtrim(map[i], " ");
		if (map[i][0] != '\n')
			count++;
		i++;
	}
	return (count);
}

static int	len_till_first_line(char **map)
{
	int		i;
	char	*line;

	i = 0;
	while (map[i])
	{
		line = ft_strtrim(map[i], " ");
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
		arr[j] = ft_strdup(map[i]);
		replace_space_with_void(arr[j], ' ');
		if (map[i][0] == '\0')
			break ;
		j++;
		i++;
	}
	arr[j] = NULL;
	return (arr);
}
