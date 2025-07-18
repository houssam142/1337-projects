/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_del.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssam <houssam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 21:52:18 by houssam           #+#    #+#             */
/*   Updated: 2025/07/18 02:24:46 by houssam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	lst_del(t_cmd_exec *lst, void (*del)(void *))
{
	if (lst)
	{
		del(lst->name);
		del(lst->value);
		free(lst);
	}
}

void	lst_del_tok(t_token *lst, void (*del)(void *))
{
	if (lst)
	{
		del(lst->value);
		del(lst->quote);
		free(lst);
	}
}
