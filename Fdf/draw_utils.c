/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 09:33:37 by hounejja          #+#    #+#             */
/*   Updated: 2025/02/23 16:27:09 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_height_range(t_win *map, t_pt *cur)
{
	if (cur->z < 0)
	{
		map->min_height = INT_MIN;
		map->max_height = INT_MAX;
	}
	if (cur->z < map->min_height)
		map->min_height = cur->z;
	if (cur->z > map->max_height)
		map->max_height = cur->z;
}

void	space_and_scale(t_win *inf)
{
	int (diagonal), scaling, scale_y, scale_x;
	double (range_height);
	double (range_x), range_y;
	range_x = inf->columns;
	range_y = inf->rows;
	range_height = (double)(inf->max_height - inf->min_height);
	diagonal = sqrt(range_x * range_x + range_y * range_y);
	scale_x = inf->width / diagonal;
	scale_y = inf->height / diagonal;
	scaling = fmin(scale_x, scale_y) / 2;
	if (range_height > 0 && range_height < 1)
		scaling *= fmin(range_x, range_y);
	if (scaling < 0)
		scaling = -scaling;
	inf->scaling = scaling;
	inf->center_x = inf->width / 2 - ((inf->columns - inf->rows)
			* inf->scaling) / 2;
	inf->center_y = inf->height / 2 - ((inf->columns + inf->rows)
			* inf->scaling) / 8 - (range_height * inf->scaling) / 6;
}

void	int_to_pixel(t_win *info, t_struct **head)
{
	t_struct	*curr;

	curr = *head;
	while (curr)
	{
		curr->x_pixel = info->center_x + (curr->x_map * info->scaling);
		curr->y_pixel = info->center_y + (curr->y_map * info->scaling);
		curr = curr->next;
	}
}
