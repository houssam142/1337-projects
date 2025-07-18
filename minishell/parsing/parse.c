/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssam <houssam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 22:01:26 by houssam           #+#    #+#             */
/*   Updated: 2025/07/18 14:11:26 by houssam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	cmd_free(t_cmd **cmd)
{
	int	i;

	i = 0;
	if (!cmd || !*cmd)
		return ;
	if ((*cmd) != NULL)
	{
		if ((*cmd)->args)
		{
			while ((*cmd)->args[i] != NULL)
				free((*cmd)->args[i++]);
			free((*cmd)->args);
		}
		if ((*cmd)->op)
			free((*cmd)->op);
		if ((*cmd)->op_value)
			free((*cmd)->op_value);
		free(*cmd);
	}
}

static int	opers(t_token *toks, t_cmd_exec **env_lst)
{
	t_token	*prev;

	prev = toks;
	while (toks)
	{
		if (toks->type == 'o')
		{
			if (ft_strncmp(toks->value, ">", 2) == 0 || ft_strncmp(toks->value,
					">>", 3) == 0 || ft_strncmp(toks->value, "<", 2) == 0
				|| ft_strncmp(toks->value, "<<", 3) == 0)
				toks->type = 'r';
			else if (prev->type == 'w' && !ft_strncmp(toks->value, "|", 2)
				&& toks->next)
				toks->type = 'c';
			else
			{
				ft_putstr_fd("Minishell: Syntax error: unexpected token '", 2);
				ft_putstr_fd(toks->value, 2);
				ft_putstr_fd("'\n", 2);
				change_stat(env_lst, 2);
				return (-1);
			}
		}
		toks = toks->next;
	}
	return (0);
}

void	clear_all(t_cmd **cmds, t_token **tokens)
{
	t_cmd	*tmp;

	lst_clear_tok(tokens, &free);
	while (*cmds != NULL)
	{
		tmp = (*cmds)->next;
		cmd_free(cmds);
		*cmds = tmp;
	}
}

int	parsing_line(char *line, t_token **toks, t_cmd_exec **env_lst)
{
	int		count;
	char	chars[11];
	t_cmd	*cmd;

	cmd = NULL;
	*toks = NULL;
	ft_strlcpy(chars, "<>|&;() \t\n", 11);
	count = tokens_count(line, chars);
	if (count > 0)
	{
		toks_arr(line, chars, toks);
		if (opers(*toks, env_lst) == -1)
		{
			lst_clear_tok(toks, &free);
			return (-1);
		}
		if (toks_to_struct(toks, &cmd, env_lst) == 0)
			exec(&cmd, env_lst);
		clear_all(&cmd, toks);
	}
	return (1);
}
