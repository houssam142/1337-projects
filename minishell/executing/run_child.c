/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_child.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssam <houssam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 13:21:13 by nafarid           #+#    #+#             */
/*   Updated: 2025/07/25 05:37:08 by houssam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	proc_handle_ctrl_c(int sig)
{
	(void)sig;
	exit(2);
}

static void	proc_handle_sigquit(int sig)
{
	(void)sig;
	exit(3);
}

static t_cmd	*close_pipes(t_cmd **cmd, int id)
{
	t_cmd	*tmp;

	tmp = *cmd;
	while (tmp)
	{
		if (tmp->id != id)
		{
			if (tmp->std_in != 0)
				close(tmp->std_in);
			if (tmp->std_out != 1)
				close(tmp->std_out);
			if (tmp->pipe_out != 0)
				close(tmp->pipe_out);
			if (tmp->pipe_in != 0)
				close(tmp->pipe_in);
		}
		tmp = tmp->next;
	}
	tmp = *cmd;
	while (tmp->id != id)
		tmp = tmp->next;
	dups(tmp);
	return (tmp);
}

static void	not_built(t_cmd_exec **env_lst, t_cmd *exec_cmd)
{
	int			i;
	char		**env;

	env = env_lst_to_arr(*env_lst, 'e', 0);
	check_if_dir(exec_cmd);
	i = execve(exec_cmd->path, exec_cmd->args, env);
	if (i == -1)
	{
		ft_putstr_fd("Minishell: : command not found\n", 2);
		arr_free(env);
		cmd_free(&exec_cmd);
		lst_clear(env_lst, free);
		exit(127);
	}
}

void	child_proc(t_cmd **cmd, t_cmd_exec **env_lst, int id)
{
	t_cmd	*exec_cmd;

	signal(SIGINT, proc_handle_ctrl_c);
	signal(SIGQUIT, proc_handle_sigquit);
	exec_cmd = close_pipes(cmd, id);
	exec_cmd->path = find_cmd(exec_cmd, *env_lst);
	if (!exec_cmd->path)
	{
		if (exec_cmd->path_error == 0)
		{
			lst_clear(env_lst, &free);
			cmd_free(&exec_cmd);
			exit(0);
		}
		// ft_putstr_fd("Minishell: ", 2);
		// ft_putstr_fd(": command not found\n", 2);
		// lst_clear(env_lst, &free);
		// cmd_free(&exec_cmd);
		// exit(127);
	}
	if (exec_cmd->builtin != 1)
		not_built(env_lst, exec_cmd);
	else
		exec_built(exec_cmd, env_lst, 1);
}
