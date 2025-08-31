/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 02:59:26 by hounejja          #+#    #+#             */
/*   Updated: 2025/08/31 23:51:42 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	replace_space_with_void(char *line, char c)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == c)
			line[i] = '0';
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
		if (line_all_ones(map[i], '1'))
			count++;
		if (count == 2)
			break ;
		i++;
	}
	return (i);
}

static int	len_till_first_line(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (line_all_ones(map[i], '1'))
			return (i + 1);
		i++;
	}
	return (i);
}

char	**only_2d_map(char **map)
{
	char	**arr;

	int (i), (len), (count), (j);
	i = len_till_first_line(map);
	len = map_len(&map[i]);
	arr = ft_malloc(sizeof(char *) * (len + 1));
	if (!arr)
		print_error(MAP, NULL);
	j = 0;
	count = 0;
	while (j < len - 1)
	{
		arr[j] = ft_strdup(map[i]);
		replace_space_with_void(arr[j], ' ');
		if (line_all_ones(map[i], '1'))
			count++;
		j++;
		if (count == 2)
			break ;
		i++;
	}
	arr[j] = NULL;
	return (arr);
}
