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
	if (*lst == NULL)
	{
		*lst = new;
		(*lst)->tail = new;
	}
	else
	{
		(*lst)->tail->next = new;
		(*lst)->tail = new;
	}
}
