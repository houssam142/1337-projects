/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 02:59:26 by hounejja          #+#    #+#             */
/*   Updated: 2025/08/28 15:05:32 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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
			return (i);
		i++;
	}
	return (i);
}

char    **only_2d_map(char **map)
{
	char	**arr;
	int		i;
	int		j;
	int		count;
	int		len;

	i = len_till_first_line(map);
	len = map_len(&map[i]);
	arr = malloc(sizeof(char *) * (len + 1));
	if (!arr)
		print_error(MAP, NULL);
	j = 0;
	count = 0;
	while (map[i])
	{
		arr[j] = ft_strdup(map[i]);
		if (line_all_ones(map[i], '1'))
			count++;
		j++;
		if (count == 2)
			break ;
		i++;
	}
	arr[j] = NULL;
	return arr;
}