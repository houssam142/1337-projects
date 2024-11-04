/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:19:50 by hounejja          #+#    #+#             */
/*   Updated: 2024/10/30 16:25:02 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

<<<<<<< HEAD
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*curr;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
=======
void	ft_lstadd_back_bonus(t_list **lst, t_list *new)
{
	t_list	*curr;

	if (*lst == 0)
		*lst = new;
>>>>>>> b24c59b3ce0ed13393269951ba5fd487e0be51de
	else
	{
		curr = *lst;
		while (curr->next)
<<<<<<< HEAD
			curr = curr->next;
		curr->next = new;
=======
		{
			curr = curr->next;
		}
>>>>>>> b24c59b3ce0ed13393269951ba5fd487e0be51de
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
