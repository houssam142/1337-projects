/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:15:33 by hounejja          #+#    #+#             */
/*   Updated: 2024/10/31 14:05:27 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

<<<<<<< HEAD
int	ft_lstsize(t_list *lst)
=======
int	ft_lstsize_bonus(t_list *lst)
>>>>>>> b24c59b3ce0ed13393269951ba5fd487e0be51de
{
	t_list	*curr;
	size_t	i;

	i = 0;
	curr = lst;
	while (curr != NULL)
	{
		curr = curr->next;
		i++;
	}
	return (i);
}