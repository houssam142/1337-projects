/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 18:37:54 by hounejja          #+#    #+#             */
/*   Updated: 2025/08/31 14:36:39 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	perform_dda(t_data *data, int *pos_x, int *pos_y, int *side)
{
	if (data->side_dist_x < data->side_dist_y)
	{
		data->side_dist_x += data->delta_dist_x;
		*pos_x += data->step_x;
		*side = 0;
	}
	else
	{
		data->side_dist_y += data->delta_dist_y;
		*pos_y += data->step_y;
		*side = 1;
	}
	if (*pos_x < 0 || *pos_x >= data->map_width || 
        *pos_y < 0 || *pos_y >= data->map_height)
        return (1);
	if (data->parse->map[*pos_y][*pos_x] == '1')
		return (1);
	return (0);
}
