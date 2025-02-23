/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:19:27 by hounejja          #+#    #+#             */
/*   Updated: 2025/02/15 17:48:06 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_lines(t_win *info, t_struct **head)
{
	t_struct	*curr;

	curr = *head;
	while (curr)
	{
		if (curr->go_right != NULL)
			bresenham(info, curr, curr->go_right);
		if (curr->go_down != NULL)
			bresenham(info, curr, curr->go_down);
		curr = curr->next;
	}
}
