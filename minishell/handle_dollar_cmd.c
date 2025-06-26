/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dollar_cmd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssam <houssam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:43:41 by houssam           #+#    #+#             */
/*   Updated: 2025/06/26 22:33:10 by houssam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strdup_blank(char *s)
{
	int		len;
	char	*blank;

	len = ft_strlen(s);
	blank = malloc(len + 1);
	if (!blank)
		return (NULL);
	ft_memset(blank, '2', len);
	blank[len] = '\0';
	return (blank);
}

static t_token	*new_ele(char **parts, t_token *last, int i)
{
	t_token	*curr;

	curr = malloc(sizeof(t_token));
	if (!curr)
		return (NULL);
	curr->value = ft_strdup(parts[i]);
	curr->quote = ft_strdup_blank(parts[i]);
	curr->next = last->next;
	return (curr);
}

int	handle_split(t_token *toks, char *value)
{
	char	**parts;
	t_token	*new;
	t_token	*last;
	int		i;

	parts = ft_split(value, ' ');
	if (!parts)
		return (-1);
	free(toks->value);
	free(toks->quote);
	toks->value = ft_strdup(parts[0]);
	toks->quote = ft_strdup_blank(parts[0]);
	if (!toks->value || !toks->quote)
		return (arr_free(parts), -1);
	last = toks;
	i = 0;
	while (parts[++i])
	{
		new = new_ele(parts, last, i);
		if (!new)
			return (arr_free(parts), -1);
		last->next = new;
		last = new;
	}
	return (arr_free(parts), 0);
}
