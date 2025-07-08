/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstadd_front.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssam <houssam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 22:20:22 by houssam           #+#    #+#             */
/*   Updated: 2025/07/08 21:11:50 by houssam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lstadd_front(t_cmd_exec **lst, t_cmd_exec *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}
