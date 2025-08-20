/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssam <houssam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 05:05:20 by houssam           #+#    #+#             */
/*   Updated: 2025/08/20 22:43:32 by houssam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	check_map(t_parse *data)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			while (ft_isspace(data->map[i][j]) && data->map[i][j])
				j++;
			if (data->map[i][j] == 'C' || data->map[i][j] == 'F')
				i++;
			else if (data->map[i][j] == '1' || data->map[i][j] == '0')
				count++;
			j++;
		}
		i++;
	}
	if (count == 0)
		print_error(EMPTY, data);
}
