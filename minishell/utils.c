/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssam <houssam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 12:59:12 by houssam           #+#    #+#             */
/*   Updated: 2025/06/25 13:37:52 by houssam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int update_quote_double_dollar(t_token *t, int *i)
{
	char    *qtmp;
	size_t  len;

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
