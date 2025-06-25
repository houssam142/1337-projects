/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dollar_cmd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssam <houssam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:43:41 by houssam           #+#    #+#             */
/*   Updated: 2025/06/25 14:56:42 by houssam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	add_split_toks(t_token *curr, char **parts)
{
	int		i;
	t_token	*new;

	i = 1;
	while (parts[i])
	{
		new = lst_new_ele_tok(0, ft_strdup(parts[i]));
		if (!new)
			return (-1);
		new->next = curr->next;
		curr->next = new;
		curr = new;
		i++;
	}
	return (0);
}

int handle_split(t_token *toks, int i, int j, char *value)
{
    char    **parts;
    t_token *curr;
    char	*tmp;
	char	*new_val;

	parts = ft_split(value, ' ');
	if (!parts)
		return (-1);
	free(toks->value);
	tmp = ft_substr(toks->value, 0, i);
	toks->value = ft_strjoin(tmp, parts[0]);
	free(tmp);
	tmp = ft_strdup(toks->value + j);
	new_val = ft_strjoin(toks->value, tmp);
	free(tmp);
	free(toks->value);
	toks->value = new_val;
	arr_free(parts);
	curr = toks;
	if (add_split_toks(curr, parts) == -1)
		return (-1);
	return (0);
}
