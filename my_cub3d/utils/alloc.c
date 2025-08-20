/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssam <houssam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 02:59:22 by hounejja          #+#    #+#             */
/*   Updated: 2025/08/20 20:33:02 by houssam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_alloc_str(t_parse *data, int k, char c)
{
	if (c == 'E')
		data->path_e = malloc(k + 1);
	else if (c == 'W')
		data->path_w = malloc(k + 1);
	else if (c == 'N')
		data->path_n = malloc(k + 1);
	else if (c == 'S')
		data->path_s = malloc(k + 1);
}
