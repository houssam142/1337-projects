/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_child_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 22:44:03 by houssam           #+#    #+#             */
/*   Updated: 2025/07/25 08:42:12 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	check_if_dir(t_cmd *exec_cmd, t_cmd_exec **env_lst, char **env)
{
	struct stat	sb;

	if ((!exec_cmd->path || exec_cmd->path[0] == '\0') && !exec_cmd->args[0][0])
	{
		ft_putstr_fd("Minishell: : command not found\n", 2);
		exit(127);
	}
	if (!stat(exec_cmd->path, &sb))
	{
		if (S_ISDIR(sb.st_mode))
		{
			ft_putstr_fd("Minishell: ", 2);
			ft_putstr_fd(exec_cmd->path, 2);
			ft_putstr_fd(": is a directory\n", 2);
			exit(126);
		}
	}
	if (!exec_cmd->path)
		exec_cmd->path = ft_strdup("");
	if (access(exec_cmd->path, X_OK) == -1 && !ft_strcmp(exec_cmd->args[0], "sudo"))
	{
		ft_putstr_fd("Minishell: ", 2);
		ft_putstr_fd(exec_cmd->path, 2);
		ft_putstr_fd(": Permission denied\n", 2);
		lst_clear(env_lst, free);
		free(exec_cmd->path);
		arr_free(env);
		cmd_free(&exec_cmd);
		exit(126);
	}
}
