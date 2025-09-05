/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_mo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 16:57:43 by hounejja          #+#    #+#             */
/*   Updated: 2025/09/04 23:00:53 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	mouse_motion(int x, int y, t_data *data)
{
	static int	old_x = WIDTH / 2;

	(void)y;
	if (x < old_x)
	{
		data->rotate_left = 1;
		rotate_l_or_r(data);
		data->rotate_left = 0;
	}
	else if (x > old_x)
	{
		data->rotate_right = 1;
		rotate_l_or_r(data);
		data->rotate_right = 0;
	}
	old_x = x;
	return (0);
}
