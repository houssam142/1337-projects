/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssam <houssam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 21:21:45 by houssam           #+#    #+#             */
/*   Updated: 2025/07/03 15:12:56 by houssam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	search_and_replace_helper(t_cmd_exec **env_lst, char *new_str)
{
	while (env_lst)
	{
		if (!ft_strncmp((*env_lst)->name, new_str, ft_strlen(new_str) + 1))
			break ;
		*env_lst = (*env_lst)->next;
	}
	if (!new_str[0])
		return (free(new_str), 0);
	free(new_str);
	return (0);
}

void	remove_empty_tokens(t_token **toks)
{
	t_token	*curr;
	t_token	*to_delete;
	t_token	*prev;

	curr = *toks;
	prev = NULL;
	while (curr)
	{
		if (curr->value && (!curr->value[0] || curr->value[0] == 32))
		{
			to_delete = curr;
			if (prev)
				prev->next = curr->next;
			else
				*toks = curr->next;
			curr = curr->next;
			free(to_delete->value);
			free(to_delete);
		}
		else
		{
			prev = curr;
			curr = curr->next;
		}
	}
}

char	*ft_strdup_repeat(char c, size_t len)
{
	size_t	i;
	char	*res;

	i = 0;
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	while (i < len)
		res[i++] = c;
	res[len] = '\0';
	return (res);
}

int	copy_quotes(t_token *t, t_cmd_exec *env_lst, int i, int j)
{
	int		new_len;
	int		val_len;
	char	*new_quote;

	new_len = ft_strlen(t->value);
	val_len = ft_strlen(env_lst->value);
	new_quote = malloc(new_len + 1);
	if (!new_quote)
		return (-1);
	ft_memcpy(new_quote, t->quote, i);
	ft_memset(new_quote + i, '2', val_len);
	ft_memcpy(new_quote + i + val_len, t->quote + j, ft_strlen(t->quote) - j);
	new_quote[new_len] = '\0';
	free(t->quote);
	t->quote = new_quote;
	return (0);
}
