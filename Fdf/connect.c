/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:20:10 by hounejja          #+#    #+#             */
/*   Updated: 2025/02/21 17:32:56 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	update_point_connect(t_struct *curr, t_struct *right,
		t_struct *down)
{
	if (right != NULL)
		curr->go_right = right;
	if (down != NULL)
		curr->go_down = down;
}

static t_struct	*address_finder(int corr_x, int corr_y, t_struct **head)
{
	t_struct	*curr;

	curr = *head;
	while (curr)
	{
		if (curr->x_map == corr_x && curr->y_map == corr_y)
			return (curr);
		curr = curr->next;
	}
	return (NULL);
}

int	point_connect(t_struct **head)
{
	t_struct	*curr;
	t_struct	*helper;

	curr = *head;
	while (curr)
	{
		helper = address_finder(curr->x_map + 1, curr->y_map, head);
		update_point_connect(curr, helper, NULL);
		helper = address_finder(curr->x_map, curr->y_map + 1, head);
		update_point_connect(curr, NULL, helper);
		curr = curr->next;
	}
	return (0);
}
