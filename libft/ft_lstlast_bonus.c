/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:17:58 by hounejja          #+#    #+#             */
/*   Updated: 2024/10/30 16:25:38 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

<<<<<<< HEAD
t_list	*ft_lstlast(t_list *lst)
=======
t_list	*ft_lstlast_bonus(t_list *lst)
>>>>>>> b24c59b3ce0ed13393269951ba5fd487e0be51de
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
