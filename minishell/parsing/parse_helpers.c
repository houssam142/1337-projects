/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssam <houssam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 22:01:33 by houssam           #+#    #+#             */
/*   Updated: 2025/07/08 21:10:59 by houssam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	helper(t_token *toks, int *i, char c)
{
	toks->quote[*i] = '1';
	while (toks->value[++(*i)] != c)
		toks->quote[*i] = '0';
	toks->quote[*i] = '1';
}

void	quote_count(t_token *toks, t_token *tmp2)
{
	int	i;

	i = -1;
	if (tmp2 != toks && tmp2->type == 'r' && !ft_strncmp(tmp2->value, "<", 2))
		toks->strip = 2;
	else if (tmp2 != toks && tmp2->type == 'r' && !ft_strncmp(tmp2->value, ">",
			2))
		toks->strip = 2;
	else if (tmp2 != toks && tmp2->type == 'r' && !ft_strncmp(tmp2->value, ">>",
			3))
		toks->strip = 2;
	if (toks != NULL)
	{
		while (toks->value[++i])
		{
			if (toks->value[i] == '\'')
				helper(toks, &i, '\'');
			else if (toks->value[i] == '\"')
				helper(toks, &i, '\"');
			else
				toks->quote[i] = '0';
		}
	}
}
