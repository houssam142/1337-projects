/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 16:33:52 by hounejja          #+#    #+#             */
/*   Updated: 2025/11/26 11:17:24 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	rgb_string_to_int(t_data *data, char c)
{
	char	**arr;

	int (r), (g), (b), (num);
	arr = NULL;
	g = 0;
	b = 0;
	r = 0;
	if (c == 'C')
	{
		arr = ft_split(data->parse->celing_color, ',');
		r = ft_atoi(arr[0], data);
		g = ft_atoi(arr[1], data);
		b = ft_atoi(arr[2], data);
	}
	else if (c == 'F')
	{
		arr = ft_split(data->parse->floor_color, ',');
		r = ft_atoi(arr[0], data);
		g = ft_atoi(arr[1], data);
		b = ft_atoi(arr[2], data);
	}
	r *= (int)pow(2, 16);
	g *= (int)pow(2, 8);
	num = r + g + b;
	return (num);
}
