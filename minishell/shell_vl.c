/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_vl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 20:15:49 by nafarid           #+#    #+#             */
/*   Updated: 2026/05/27 22:08:55 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	handle_single_quotes(t_token *toks, int i, t_buff* buff)
{
	i++;
	while (toks->value[i] && toks->value[i] != '\'')
	{
		append_char(buff, toks->value[i]);
		i++;
	}
	if (toks->value[i] == '\'')
		i++;
	return (i);
}

char	*resolve_dollar(char* str, int* i, t_cmd_exec* env)
{
	char	*name;
	int		start;
	char	*val;

	if (str[*i] != '$')
		return (NULL);
	start = *i + 1;
	if (!ft_isalpha(str[*i + 1]) && str[*i + 1] != '_'
		&& str[*i + 1] == '?')
	{
		(*i)++;
		return (ft_strdup("$"));
	}
	(*i)++;
	func(str, i);
	name = ft_substr(str, start, *i - start);
	if (!name)
		return (NULL);
	while (env && ft_strncmp(env->name, name, ft_strlen(name) + 1))
		env = env->next;
	if (!env)
		return (ft_strdup(""));
	val = ft_strdup(env->value);
	return (val);
}

void	append_str(t_buff* buff, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		append_char(buff, str[i]);
		i++;
	}
}

// int	handle_dollar_sign(t_token *toks, int i, t_cmd_exec *env_lst, t_buff* buff)
// {
// 	char	*val;

// 	i++;
// 	val = resolve_dollar(toks, &i, env_lst);
// 	if (!val)
// 		return (i);
// 	append_str(buff, val);
// 	return (i);
// }

int	len_till_expansion(char *s, int start_pos)
{
	int	i;
	int	in_quotes;
	int	len;

	if (!s || start_pos < 0)
		return (0);
	len = ft_strlen(s);
	if (start_pos >= len)
		return (0);
	i = start_pos;
	in_quotes = 0;
	while (s[i])
	{
		if (s[i] == '\"' && !in_quotes)
			in_quotes = 1;
		else if (s[i] == '\"' && in_quotes)
			in_quotes = 0;
		else if (!in_quotes && (s[i] == ' ' || s[i] == '\t'))
			break ;
		i++;
	}
	return (i - start_pos);
}

void	build_new_tok_val(t_token *toks, char *value, int i, int j)
{
	char	*prefix;
	char	*suffix;
	char	*new_val;

	prefix = ft_substr(toks->value, 0, i);
	suffix = ft_strdup(toks->value + j);
	new_val = ft_strjoin(prefix, value);
	value = ft_strjoin(new_val, suffix);
	toks->value = value;
	check_if_should_split(toks);
}

char	*erase_spaces(char *str)
{
	int		i;
	int		j;
	int		space;
	char	*res;

	res = ft_malloc(ft_strlen(str) + 1);
	i = -1;
	j = 0;
	if (!res)
		return (NULL);
	while (str[++i])
	{
		if (str[i] == 32 || str[i] == '\t')
		{
			if (!space)
				res[j++] = ' ';
			space = 1;
		}
		else
		{
			res[j++] = str[i];
			space = 0;
		}
	}
	return (res[j] = '\0', res);
}
