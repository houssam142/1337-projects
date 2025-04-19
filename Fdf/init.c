/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 20:44:54 by hounejja          #+#    #+#             */
/*   Updated: 2025/02/23 10:45:10 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	info_to_list(t_win *data, t_struct **head)
{
	t_struct	*curr;

	curr = *head;
	while (curr)
	{
		curr->infa = data;
		curr = curr->next;
	}
}

void	check_and_count(t_struct *head, t_win *info_map)
{
	t_struct	*new_node;

	int (count);
	count = 0;
	if (!head)
		return ;
	info_map->min_height = INT_MAX;
	info_map->max_height = INT_MIN;
	new_node = head;
	while (new_node)
	{
		set_height_range(info_map, &(new_node->pt));
		if (new_node->next == NULL)
		{
			info_map->columns = new_node->x_map + 1;
			info_map->rows = new_node->y_map + 1;
		}
		new_node = new_node->next;
		count++;
	}
	info_map->total_points = count;
	info_to_list(info_map, &head);
	point_connect(&head);
	space_and_scale(info_map);
	int_to_isometric_pixel(info_map, &head);
}

void	create_list(t_struct **head, int x, int y, char *str)
{
	t_struct *(new_node);
	new_node = malloc(sizeof(t_struct));
	if (!new_node)
		return ;
	new_node->x_map = x;
	new_node->y_map = y;
	if (str)
		new_node->z_map = check_commas(str, *head);
	new_node->pt.x = x;
	new_node->pt.y = y;
	new_node->pt.z = new_node->z_map;
	new_node->x_pixel = 0;
	new_node->y_pixel = 0;
	new_node->color = get_color(new_node->z_map);
	new_node->go_right = NULL;
	new_node->go_down = NULL;
	new_node->next = NULL;
	new_node->tail = NULL;
	add_back(head, new_node);
	free(str);
}
