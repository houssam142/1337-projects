/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 16:33:52 by hounejja          #+#    #+#             */
/*   Updated: 2025/08/30 16:59:58 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	rgb_string_to_int(t_data *data, char c)
{
	char	**arr;
	
	int (r), (g), (b);
	arr = NULL;
	g = 0;
	b = 0;
	r = 0;
	if (c == 'C')
	{
		arr = ft_split(data->parse->celing_color, ',');
		if (!arr)
			exit(1);
		r = ft_atoi(arr[0]);
		g = ft_atoi(arr[1]);
		b = ft_atoi(arr[2]);
	}
	else if (c == 'F')
	{
		arr = ft_split(data->parse->floor_color, ',');
		if (!arr)
			exit(1);
		r = ft_atoi(arr[0]);
		g = ft_atoi(arr[1]);
		b = ft_atoi(arr[2]);
	}
	return ((r << 16) | (g << 8) | b);
}
