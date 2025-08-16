/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 20:10:19 by nafarid           #+#    #+#             */
/*   Updated: 2025/08/13 11:07:18 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	final_parsing(t_token **toks, t_cmd_exec *env_lst)
{
	t_token	*tmp;
	t_token	*tmp2;

	tmp = *toks;
	tmp2 = tmp;
	while (tmp && tmp->type != 'c')
	{
		if (tmp2 != tmp && tmp2->type == 'r' && !ft_strncmp(tmp2->value, "<<",
				3))
			tmp->type = 'h';
		quote_count(tmp);
		if (tmp->type != 'h')
			p_expansion(tmp, env_lst);
		tmp2 = tmp;
		tmp = tmp->next;
	}
	remove_empty_tokens(toks);
	if (!toks || !*toks)
		return (-1);
	ft_quote_removal(toks);
	return (0);
}

static int	parsing_cmd(t_token **toks, t_cmd *cmd, t_cmd_exec **env_lst)
{
	int	i;

	if (final_parsing(toks, *env_lst))
		return (-1);
	arg_count(toks, cmd);
	i = parsing_opers(toks, cmd, env_lst);
	if (i == -1)
	{
		cmd->redir_error = 1;
		change_stat(env_lst, 1);
	}
	if (i == -2)
	{
		change_stat(env_lst, 2);
		return (-1);
	}
	if (i == -3)
	{
		change_stat(env_lst, 130);
		return (-1);
	}
	if (i == -4)
		return (change_stat(env_lst, 0), -1);
	return (0);
}

static void	cmd_init(t_cmd **cmd)
{
	(*cmd) = ft_malloc(sizeof(t_cmd));
	if (!(*cmd))
		return ;
	(*cmd)->id = 0;
	(*cmd)->args = NULL;
	(*cmd)->op = NULL;
	(*cmd)->path = NULL;
	(*cmd)->path_error = 0;
	(*cmd)->op_value = NULL;
	(*cmd)->builtin = 0;
	(*cmd)->std_in = 0;
	(*cmd)->std_out = 1;
	(*cmd)->std_err = 2;
	(*cmd)->pipe = 0;
	(*cmd)->redir_error = 0;
	(*cmd)->pipe_out = 0;
	(*cmd)->pipe_in = 0;
	(*cmd)->std_in_dup1 = -1;
	(*cmd)->std_out_dup1 = -1;
	(*cmd)->delimiter = 0;
	(*cmd)->next = NULL;
}

static int	parse_pipe(t_token **toks, t_cmd *last)
{
	t_cmd	*new_cmd;
	int		fd[2];

	while (last->next != NULL)
		last = last->next;
	last->pipe = 1;
	*toks = (*toks)->next;
	if (pipe(fd) == -1)
		return (-1);
	cmd_init(&new_cmd);
	if (!new_cmd)
	{
		close(fd[0]);
		close(fd[1]);
		return (-1);
	}
	last->next = new_cmd;
	last->pipe_out = fd[1];
	last->next->pipe_in = fd[0];
	return (0);
}

int	toks_to_struct(t_token **toks, t_cmd **cmd, t_cmd_exec **env_lst)
{
	t_cmd	*last;
	int		id;

	id = 0;
	cmd_init(cmd);
	if (parsing_cmd(toks, *cmd, env_lst))
		return (-1);
	(*cmd)->id = id;
	while ((*toks) && (*toks)->type == 'c')
		*toks = (*toks)->next;
	while ((*toks) && ft_strncmp((*toks)->value, "|", 2) == 0)
	{
		last = *cmd;
		parse_pipe(toks, last);
		last = *cmd;
		while (last->next)
			last = last->next;
		if (parsing_cmd(toks, last, env_lst) == -1)
			return (-1);
		last->id = ++id;
	}
	return (0);
}
