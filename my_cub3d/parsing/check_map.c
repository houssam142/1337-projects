/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssam <houssam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 05:05:20 by houssam           #+#    #+#             */
/*   Updated: 2025/08/22 21:28:58 by houssam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	check_map(t_parse *data)
{
	int	i;
	int	len;
	int	count;

	i = 0;
	count = 0;
	while (data->map[i])
	{
		data->map[i] = ft_strtrim(data->map[i], " ");
		len = ft_strlen(data->map[i]);
		if (data->map[i][0] == '1' && data->map[i][len - 2] == '1')
		{
			if (line_all_ones(data->map[i], '1'))
				break ;
			count++;
		}
		i++;
	}
	if (count > 0)
		print_error(EMPTY, data);
	if (!line_all_ones(data->map[i], '1'))
		print_error(MAP, data);
	while (data->map[i])
	{
		len = ft_strlen(data->map[i]);
		// if (len - 1 <= 3)
		// 	print_error(MAP, data);
		i++;
	}
}
