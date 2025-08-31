/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 02:59:22 by hounejja          #+#    #+#             */
/*   Updated: 2025/08/31 21:23:20 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_alloc_str(t_parse *data, int k, char c)
{
	if (c == 'E')
		data->path_e = ft_malloc(k + 1);
	else if (c == 'W')
		data->path_w = ft_malloc(k + 1);
	else if (c == 'N')
		data->path_n = ft_malloc(k + 1);
	else if (c == 'S')
		data->path_s = ft_malloc(k + 1);
}
