/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 22:40:00 by hounejja          #+#    #+#             */
/*   Updated: 2024/10/30 16:25:15 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

<<<<<<< HEAD
void	ft_lstadd_front(t_list **lst, t_list *new)
=======
void	ft_lstadd_front_bonus(t_list **lst, t_list *new)
>>>>>>> b24c59b3ce0ed13393269951ba5fd487e0be51de
{
	if (lst)
	{
		if (*lst)
			new->next = *lst;
		*lst = new;
	}
}
