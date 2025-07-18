/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssam <houssam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 22:56:21 by nafarid           #+#    #+#             */
/*   Updated: 2025/07/18 14:13:43 by houssam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	check_flag(char *str, int *n)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!i && str[i] == '-')
			continue ;
		else if (i && str[i] == 'n')
			continue ;
		else
			break ;
	}
	if (i && str[i] == '\0')
	{
		*n = 1;
		return (1);
	}
	return (0);
}

static void	echo_print(t_cmd *cmd, int *i)
{
	int	flag;

	flag = 0;
	while (cmd->args[*i])
	{
		if (flag == 1)
			ft_putchar_fd(' ', 1);
		ft_putstr_fd(cmd->args[*i], 1);
		flag = 1;
		++(*i);
	}
}

int	echo(t_cmd *cmd, t_cmd_exec **env_lst)
{
	int	n;
	int	i;

	n = 0;
	if (cmd->args[1] == 0)
		ft_putchar_fd('\n', 1);
	else
	{
		i = 0;
		while (cmd->args[++i] && check_flag(cmd->args[i], &i) == 1)
			;
		echo_print(cmd, &i);
		if (!n)
			ft_putchar_fd('\n', 1);
	}
	change_stat(env_lst, 0);
	return (0);
}
