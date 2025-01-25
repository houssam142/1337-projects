/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 14:01:19 by hounejja          #+#    #+#             */
/*   Updated: 2025/01/25 09:16:24 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*new_lst;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		new_lst = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = new_lst;
	}
	*lst = 0;
}
