/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssam <houssam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 12:59:12 by houssam           #+#    #+#             */
/*   Updated: 2025/06/29 15:38:42 by houssam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*new_ele_tok_node(char **words, int i)
{
	t_token	*curr;

	curr = malloc(sizeof(t_token));
	if (!curr)
		return (NULL);
	curr->type = 'w';
	curr->value = ft_strdup(words[i]);
	curr->quote = ft_strdup("0");
	curr->next = NULL;
	if (!curr->value || !curr->quote)
		return (NULL);
	return (curr);
}

static int	ft_split_token_into_nodes_2(t_token *curr, char **words,
	t_token *next)
{
	int		i;
	t_token	*new;

	i = 0;
	while (words[++i])
	{
		new = new_ele_tok_node(words, i);
		if (!new)
			return (-1);
		curr->next = new;
		curr = new;
	}
	curr->next = next;
	return (0);
}

int	split_token_into_nodes(t_token *tok)
{
	char	**words;
	t_token	*curr;
	t_token	*next;

	if (!tok || !tok->value)
		return (-1);
	curr = tok;
	next = tok->next;
	words = ft_split(tok->value, ' ');
	if (!words || !words[0])
		return (-1);
	free(curr->value);
	curr->value = ft_strdup(words[0]);
	free(curr->quote);
	curr->quote = ft_strdup("0");
	if (!curr->value || !curr->quote)
		return (-1);
	if (ft_split_token_into_nodes_2(curr, words, next) == -1)
		return (-1);
	return (arr_free(words), 0);
}

static int	update_quote_double_dollar(t_token *t, int *i)
{
	char	*qtmp;
	size_t	len;

	len = ft_strlen(t->quote);
	qtmp = malloc(len + 2);
	if (!qtmp)
		return (-1);
	ft_memcpy(qtmp, t->quote, *i);
	ft_strlcpy(qtmp + *i, "22", 3);
	ft_strlcpy(qtmp + *i + 2, t->quote + *i + 2, len - *i - 1);
	free(t->quote);
	t->quote = qtmp;
	*i += ft_strlen(ft_itoa(getpid())) - 1;
	return (0);
}

int	handle_double_dollar(t_token *t, int *i)
{
	char	*pid;
	char	*tmp;
	char	*rest;
	char	*val;

	pid = ft_itoa(getpid());
	if (!pid)
		return (-1);
	t->value[*i] = '\0';
	tmp = ft_strjoin(t->value, pid);
	if (!tmp)
		return (free(pid), -1);
	rest = ft_strdup(t->value + *i + 2);
	if (!rest)
		return (free(tmp), free(pid), -1);
	val = ft_strjoin(tmp, rest);
	free(tmp);
	free(rest);
	free(pid);
	if (!val)
		return (-1);
	free(t->value);
	t->value = val;
	return (update_quote_double_dollar(t, i));
}
