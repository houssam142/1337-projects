/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_child_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssam <houssam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 22:44:03 by houssam           #+#    #+#             */
/*   Updated: 2025/07/22 06:17:24 by houssam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	check_if_dir(t_cmd *exec_cmd)
{
	struct stat	sb;

	if (!stat(exec_cmd->path, &sb))
	{
		if (S_ISDIR(sb.st_mode) && exec_cmd->delimiter != 0)
		{
			ft_putstr_fd("Minishell: ", 2);
			ft_putstr_fd(exec_cmd->path, 2);
			ft_putstr_fd(": is a directory\n", 2);
			exit(126);
		}
		if (access(exec_cmd->path, X_OK) == -1)
		{
			ft_putstr_fd("Minishell: ", 2);
			ft_putstr_fd(exec_cmd->path, 2);
			ft_putstr_fd(": Permission denied\n", 2);
			exit(126);
		}
	}
}
