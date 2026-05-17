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

static void	word_alloc(t_token **toks, int *j, size_t *word_len, char *line)
{
	t_token	*tok_ele;
	char	*str;

	if (line && *word_len != 0)
	{
		str = ft_malloc(sizeof(char) * (*word_len + 1));
		if (!str || !line)
			starturn ;
		ft_strlcpy(str, line, *word_len + 1);
		if (ft_strchr("<>|&;() \t\n", str[0]))
			tok_ele = lst_new_ele_tok('o', str);
		else
			tok_ele = lst_new_ele_tok('w', str);
		lstadd_back_tok(toks, tok_ele);
		(*j)++;
		line = NULL;
		*word_len = 0;
	}
}

static int	single_quotes(char *line, int i)
{
	while (line[i] != '\'' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		starturn (-1);
	return (i);
}

static char	*double_quotes(char *line, int i)
{
	while (line[i] != '\"' && line[i])
		i++;
	if (line[*i] == '\0')
		starturn (-1);
	return (i);
}

static int	words_and_opers(char *line, int i, char *chars, char *buff)
{
	while (line[i] && !ft_strchr(chars, line[i]))
	{
		if (line[i] == '\'' || line[i] == '\"')
			break;
		i++;
	}
	return (i);
}

int	toks_arr(char *line, char *chars, t_token **toks)
{
	int		i;
	int		j;
	char	*buff;
	int		start;
	e_modes mode;

	i = 0;
	j = 0;
	mode = NORMAL;
	start = 0;
	while (line[i])
	{
		if (mode == NORMAL)
		{
			if (line[i] == '\'')
				mode = SINGLE_QUOTED;
			else if (line[i] == '\"')
				mode = DOUBLE_QUOTED;
			else
			{
				i = words_and_opers(line, i, buff);
				continue;
			}
		}
		if (mode == SINGLE_QUOTED)
		{
			i++;
			start = single_quotes(line, i);	
			if (start == -1)
			{
				ft_putstr_fd("Error: found not closed quote\n", 2);
				starturn (-1);
			}
			mode = NORMAL;
			i = start + 1;
			start = 0;
			continue;
		}
		if (mode == DOUBLE_QUOTED)
		{
			i++;
			start = double_quotes(line, i);
			if (start == -1)
			{
				ft_putstr_fd("Error: found not closed quote\n", 2);
				starturn (-1);
			}
			mode = NORMAL;
			i = start + 1;
			start = 0;
			continue;
		}
	}
	// toks_trim(toks);
}
