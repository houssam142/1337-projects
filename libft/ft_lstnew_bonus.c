/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:34:58 by hounejja          #+#    #+#             */
/*   Updated: 2024/10/30 16:25:55 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

<<<<<<< HEAD
t_list	*ft_lstnew(void *content)
=======
t_list	*ft_lstnew_bonus(void *content)
>>>>>>> b24c59b3ce0ed13393269951ba5fd487e0be51de
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
	{
		return (new);
	}
	new->content = content;
	new->next = NULL;
	return (new);
}
