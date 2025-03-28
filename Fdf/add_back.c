/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_back.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:19:50 by hounejja          #+#    #+#             */
/*   Updated: 2025/02/23 10:48:05 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	add_back(t_struct **lst, t_struct *new)
{
	t_struct	*curr;

	if (*lst == NULL)
		*lst = new;
	else
	{
		curr = *lst;
		while (curr->next)
			curr = curr->next;
		curr->next = new;
	}
}

//t_list	*create_node(int *value)
//{
//	t_list *new_node = (t_list *)malloc(sizeof(t_list));
//	if (!new_node) return NULL;
//	new_node->content = value;
//	new_node->next = NULL;
//	return new_node;
//}

//void	print_list(t_list *lst)
//{
//	while (lst)
//	{
//		printf("%d", *(int *)lst->content);
//		lst = lst->next;
//	}
//}
//int main()
//{
//	t_list *list = NULL;
//	int *s = malloc(sizeof(int));
//	*s = 24;
//	int *n = malloc(sizeof(int));
//	*n = 32;
//	int *num = malloc(sizeof(int));
//	*num = 43;
//	ft_lstadd_back(&list, create_node(s));
//	ft_lstadd_back(&list, create_node(n));
//	ft_lstadd_back(&list, create_node(num));
//	while (list)
//	{
//		printf("%d", *(int *)list->content);
//		list = list->next;
//	}
//	return 0;
//}
