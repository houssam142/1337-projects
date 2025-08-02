/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_child.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssam <houssam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 13:21:13 by nafarid           #+#    #+#             */
/*   Updated: 2025/08/02 17:30:43 by houssam          ###   ########.fr       */
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

static void	not_built(t_cmd_exec **env_lst, t_cmd *exec_cmd, t_cmd **cmd)
{
	int		i;
	char	**env;

	env = env_lst_to_arr(*env_lst, 'e', 0);
	check_if_dir(exec_cmd, env_lst, env);
	if (!exec_cmd->path)
		exec_cmd->path = ft_strdup("");
	i = execve(exec_cmd->path, exec_cmd->args, env);
	if (i == -1)
	{
		perror("Minishell");
		cleanup(env_lst, cmd, exec_cmd, env);
		exit(127);
	}
}

static void	fun(t_cmd *exec_cmd, int *exit_code)
{
	if (exec_cmd->path_error == 4)
	{
		*exit_code = 0;
		cmd_free(&exec_cmd);
	}
	else if (!exec_cmd->path_error)
		*exit_code = 0;
	else
	{
		ft_putstr_fd("Minishell: ", 2);
		ft_putstr_fd(exec_cmd->args[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		*exit_code = 127;
	}
}

void	child_proc(t_cmd **cmd, t_cmd_exec **env_lst, int id)
{
	t_cmd	*exec_cmd;
	int		exit_code;

	signal(SIGINT, proc_handle_ctrl_c);
	signal(SIGQUIT, proc_handle_sigquit);
	exec_cmd = close_pipes(cmd, id);
	exec_cmd->path = find_cmd(exec_cmd, *env_lst);
	exit_code = 0;
	if (!exec_cmd->path && exec_cmd->redir_error != 3)
	{
		fun(exec_cmd, &exit_code);
		restore_std_fds(exec_cmd);
		cleanup(env_lst, cmd, exec_cmd, NULL);
		exit(exit_code);
	}
	else if (exec_cmd->builtin != 1)
	{
		not_built(env_lst, exec_cmd, cmd);
	}
	else if (exec_cmd->redir_error != 3)
	{
		exit_code = exec_run(exec_cmd, env_lst);
		restore_std_fds(exec_cmd);
		cleanup(env_lst, cmd, exec_cmd, NULL);
		exit(exit_code);
	}
}
