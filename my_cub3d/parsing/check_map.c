/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssam <houssam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 05:05:20 by houssam           #+#    #+#             */
/*   Updated: 2025/08/28 11:28:45 by houssam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	check_map(char **map, t_parse *data)
{
	int	i;
	int	len;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		map[i] = ft_strtrim(map[i], " ");
		len = ft_strlen(map[i]);
		if (map[i][0] == '1' && map[i][len - 2] == '1')
		{
			if (line_all_ones(map[i], '1'))
				break ;
			count++;
		}
		i++;
	}
	if (count > 0)
		print_error(EMPTY, data);
	if (!line_all_ones(map[i], '1'))
		print_error(MAP, data);
	while (map[i])
	{
		len = ft_strlen(map[i]);
		// if (len - 1 <= 3)
		// 	print_error(MAP, data);
		i++;
	}
}
