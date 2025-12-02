/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 21:19:43 by hounejja          #+#    #+#             */
/*   Updated: 2025/11/29 20:18:24 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_gc	*create_node(void *data)
{
	t_gc	*new_node;

	new_node = malloc(sizeof(t_gc));
	if (!new_node)
		return (NULL);
	new_node->ptr = data;
	new_node->next = NULL;
	return (new_node);
}

t_gc	*get_garbage_collector(void *ptr)
{
	static t_gc	*gc;
	t_gc		*new_gc;

	if (ptr)
	{
		new_gc = create_node(ptr);
		new_gc->next = gc;
		gc = new_gc;
	}
	return (gc);
}

void	*ft_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
	{
		perror("Error\nMemory allocation failed!");
		free_garbage();
		exit(2);
	}
	get_garbage_collector(ptr);
	return (ptr);
}

void	free_garbage(void)
{
	t_gc	*gc;
	t_gc	*tmp;

	gc = get_garbage_collector(NULL);
	while (gc)
	{
		tmp = gc;
		gc = gc->next;
		free(tmp->ptr);
		tmp->ptr = NULL;
		free(tmp);
		tmp = NULL;
	}
}
