/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing_cmd_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 13:21:04 by nafarid           #+#    #+#             */
/*   Updated: 2025/05/11 13:21:04 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	**find_and_split(t_cmd_exec *env_lst)
{
	char	**path;

	path = NULL;
	while (env_lst)
	{
		if (!ft_strncmp(env_lst->name, "PATH", 5))
		{
			path = ft_split(env_lst->value, ':');
			break ;
		}
		env_lst = env_lst->next;
	}
	return (path);
}

static char	*find_path(t_cmd_exec *env_lst, char *cmd)
{
	char	**path;
	char	*value;
	int		i;

	i = -1;
	path = find_and_split(env_lst);
	while (path && path[++i] != NULL)
	{
		value = ft_strjoin_sep(path[i], cmd, '/');
		if (access(value, F_OK | X_OK) == 0)
		{
			arr_free(path);
			return (value);
		}
		free(value);
	}
	if (path != NULL)
		arr_free(path);
	return (0);
}

static int	built(t_cmd *cmd)
{
	int	i;

	i = 0;
	if (cmd->args != NULL)
	{
		if (!ft_strncmp(cmd->args[0], "echo", 5))
			i = 1;
		else if (!ft_strncmp(cmd->args[0], "cd", 3))
			i = 1;
		else if (!ft_strncmp(cmd->args[0], "pwd", 4))
			i = 1;
		else if (!ft_strncmp(cmd->args[0], "export", 7))
			i = 1;
		else if (!ft_strncmp(cmd->args[0], "unset", 6))
			i = 1;
		else if (!ft_strncmp(cmd->args[0], "env", 4))
			i = 1;
		else if (!ft_strncmp(cmd->args[0], "exit", 5))
			i = 1;
		cmd->builtin = i;
	}
	return (i);
}

static void	ft_str_tolower(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		str[i] = ft_tolower(str[i]);
}

char	*find_cmd(t_cmd *cmd, t_cmd_exec *env_lst)
{
	char	*path;

	path = NULL;
	if (!cmd->args || !cmd->args[0])
		return (0);
	ft_str_tolower(cmd->args[0]);
	if ((built(cmd) == 1) || (ft_strchr(cmd->args[0], '/') != 0))
		path = ft_strdup(cmd->args[0]);
	else
	{
		path = find_path(env_lst, cmd->args[0]);
		if (path)
		{
			free(cmd->args[0]);
			cmd->args[0] = ft_strdup(path);
		}
	}
	if (!path)
		cmd->path_error = 1;
	return (path);
}
