/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 05:05:20 by houssam           #+#    #+#             */
/*   Updated: 2025/09/01 19:30:56 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	arr_len(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	check_map(char **map)
{
	int	i;
	int	len;
	int	size;

	i = 0;
	size = arr_len(map);
	if (!line_all_ones(map[0], '1') || !line_all_ones(map[size - 1], '1'))
		print_error(WALL);
	while (map[i])
	{
		map[i] = ft_strtrim(map[i], " ");
		len = ft_strlen(map[i]);
		if (map[i][0] != '1' || map[i][len - 2] != '1')
			print_error(WALL);
		i++;
	}
}
