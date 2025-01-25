/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:19:50 by hounejja          #+#    #+#             */
/*   Updated: 2025/01/25 09:17:01 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*curr;

	if (*lst == NULL)
	{
		*lst = new;
	}
	else
	{
		curr = *lst;
		while (curr->next)
		{
			curr = curr->next;
		}
		curr->next = new;
	}
}

