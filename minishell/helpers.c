/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssam <houssam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 21:21:45 by houssam           #+#    #+#             */
/*   Updated: 2025/06/26 21:29:04 by houssam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
