/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 09:04:46 by hounejja          #+#    #+#             */
/*   Updated: 2025/02/23 16:10:13 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_color(int z)
{
	if (z < 0)
		return (0x0000FF);
	else if (z < 5)
		return (0xFF0000);
	else if (z < 10)
		return (0xFFFF00);
	else if (z < 20)
		return (0x808080);
	return (0xFFFFFF);
}

int	ft_isspace(char c)
{
	return (c == '\t' || c == '\r' || c == '\f' || c == '\v'
		|| c == ' ' || c == '\n');
}

void	int_to_isometric_pixel(t_win *info, t_struct **head)
{
	t_struct	*curr;

	double (angle), z_factor;
	angle = M_PI / 6;
	z_factor = 0.1;
	curr = *head;
	while (curr)
	{
		curr->x_pixel = info->center_x + ((curr->x_map - curr->y_map)
				* cos(angle) * info->scaling);
		curr->y_pixel = info->center_y - (curr->z_map * z_factor
				* info->scaling)
			+ ((curr->x_map + curr->y_map) * sin(angle) * info->scaling);
		curr = curr->next;
	}
}
