/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_new_ele.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssam <houssam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 22:20:05 by houssam           #+#    #+#             */
/*   Updated: 2025/07/16 20:51:12 by houssam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_ambiguous_redirect(t_token *toks)
{
	t_token *curr;
	t_token	*next;

	curr = toks;
	while (curr)
	{
		if (curr->type == 'r' || curr->type == 'R')
		{
			next = curr->next;
			if (!next || !next->value || next->value[0] == '\0')
			{
				ft_putstr_fd("minishell: ", 2);
				ft_putstr_fd(next && next->value ? next->value : "", 2);
				ft_putstr_fd(": ambiguous redirect\n", 2);
				return (1);
			}
			if (next->next && next->type == 'w' && next->next->type == 'w')
			{
				ft_putstr_fd("minishell: ", 2);
				ft_putstr_fd(next->value, 2);
				ft_putstr_fd(": ambiguous redirect\n", 2);
				return (1);
			}
		}
		curr = curr->next;
	}
	return (0);
}

t_cmd_exec	*lst_new_ele(char *name, char *value)
{
	t_cmd_exec	*new_ele;

	new_ele = malloc(sizeof(t_cmd_exec));
	if (!new_ele)
		return (NULL);
	new_ele->name = name;
	new_ele->value = value;
	new_ele->meaning = 'e';
	new_ele->next = NULL;
	return (new_ele);
}

t_token	*lst_new_ele_tok(char type, char *value)
{
	t_token	*new_ele;

	new_ele = malloc(sizeof(t_token));
	if (!new_ele)
		return (NULL);
	new_ele->type = type;
	new_ele->value = value;
	new_ele->quote = (char *)ft_calloc(sizeof(char), (ft_strlen(value) + 1));
	new_ele->quote[sizeof(char) * ft_strlen(value)] = '\0';
	new_ele->strip = 1;
	new_ele->next = NULL;
	return (new_ele);
}
