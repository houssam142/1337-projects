/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 18:37:54 by hounejja          #+#    #+#             */
/*   Updated: 2025/08/30 18:38:53 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	perform_dda(t_data *data, int *pos_x, int *pos_y, int *side)
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
}
