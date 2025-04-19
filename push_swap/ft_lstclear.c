/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 14:01:19 by hounejja          #+#    #+#             */
/*   Updated: 2025/02/14 11:57:09 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*new_lst;

	if (!lst)
		return ;
	while (*lst)
	{
		new_lst = (*lst)->next;
		free((*lst)->content);
		free(*lst);
		*lst = new_lst;
	}
	*lst = 0;
}
