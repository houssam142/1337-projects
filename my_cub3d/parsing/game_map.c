/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssam <houssam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 02:59:26 by hounejja          #+#    #+#             */
/*   Updated: 2025/08/28 11:46:24 by houssam          ###   ########.fr       */
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

	i = len_till_first_line(map);
	arr = malloc(sizeof(char *) * (map_len(&map[i]) + 1));
	if (!arr)
		print_error(MAP, NULL);
	j = 0;
	count = 0;
	while (map[i])
	{
		arr[j] = ft_strdup(map[i]);
		if (line_all_ones(map[i], '1'))
			count++;
		if (count == 2)
			break ;
		j++;
		i++;
	}
	arr[j] = NULL;
	return arr;
}