/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_new_ele.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssam <houssam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 22:20:05 by houssam           #+#    #+#             */
/*   Updated: 2025/07/21 17:07:48 by houssam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	new_ele->quote = ft_calloc(sizeof(char), (ft_strlen(value) + 1));
	new_ele->quote[sizeof(char) * ft_strlen(value)] = '\0';
	new_ele->strip = 1;
	new_ele->next = NULL;
	return (new_ele);
}
