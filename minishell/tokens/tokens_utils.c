/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 20:11:27 by nafarid           #+#    #+#             */
/*   Updated: 2025/08/07 20:11:29 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	store_token(t_token **toks, t_buff* buff)
{
	t_token	*tok;
	char	*str;

	if (!buff || !buff->buff || !buff->len)
		return ;
	str = ft_strdup(buff->buff);
	tok = lst_new_ele_tok('w', str);
	lstadd_back_tok(toks, tok);
	free(buff->buff);
	buff->buff = NULL;
	buff->cap = 0;
	buff->len = 0;
}

static void	append_operator_as_token(char *line, int *i, t_token** toks)
{
	char	op[3] = {0};

	if (line[*i + 1] && line[*i] == '>')
	{
		if (line[*i + 1] == '>')
		{
			op[0] = '>';
			op[1] = '>';
			op[2] = '\0';
			*i += 2;
		}		
		else
		{
			op[0] = '>';
			op[1] = '\0';
			(*i)++;
		}
	}
	else if (line[*i + 1] && line[*i] == '<')
	{
		if (line[*i + 1] == '<')
		{
			op[0] = '<';
			op[1] = '<';
			op[2] = '\0';
			*i += 2;
		}
		else
		{
			op[0] = '<';
			op[1] = '\0';
			(*i)++;
		}
	}
	else
	{
		op[0] = line[*i];
		op[1] = '\0';
		(*i)++;
	}
	lstadd_back_tok(toks, lst_new_ele_tok('o', ft_strdup(op)));
}

static bool	ft_isoperator(int c)
{
	return (c == '|' || c == '>' || c == '<');
}

static void	append_char(t_buff* buf, char c)
{
	if (!buf->buff)
	{
		buf->cap = 8;
		buf->len = 0;
		buf->buff = ft_malloc(buf->cap);
	}
	if (buf->len + 1 > buf->cap)
	{
		buf->cap *= 2;
		buf->buff = realloc(buf->buff, buf->cap);
	}
	buf->buff[buf->len++] = c;
	buf->buff[buf->len] = '\0';
}

int	toks_arr(char *line, t_token **toks)
{
	int		i;
	enum e_modes	mode;
	t_buff	buff;

	i = 0;
	mode = NORMAL;
	buff.buff = NULL;
	buff.len = 0;
	buff.cap = 0;
	while (line[i])
	{
		if (mode == NORMAL)
		{
			if (line[i] == '\'')
			{
				mode = SINGLE_QUOTED;
				continue;
			}
			if (line[i] == '\"')
			{
				mode = DOUBLE_QUOTED;
				continue;
			}
			if (ft_isspace(line[i]))
			{
				if (buff.len > 0)
					store_token(toks, &buff);
				i++;
				continue;
			}
			if (ft_isoperator(line[i]))
			{
				if (buff.len > 0)
					store_token(toks, &buff);
				append_operator_as_token(line, &i, toks);
				continue;
			}
			append_char(&buff, line[i++]);
			continue;
		}
		if (mode == SINGLE_QUOTED)
		{
			i++;
			while (line[i] && line[i] != '\'')
				append_char(&buff, line[i++]);
			if (!line[i])
				return (free(buff.buff), -1);
			i++;
			mode = NORMAL;
		}
		if (mode == DOUBLE_QUOTED)
		{
			i++;
			while (line[i] && line[i] != '\"')
				append_char(&buff, line[i++]);
			if (!line[i])
				return (free(buff.buff), -1);
			i++;
			mode = NORMAL;
		}
	}
	if (buff.len > 0)
		store_token(toks, &buff);
	return (0);
}
