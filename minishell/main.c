/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssam <houssam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 13:08:36 by aoussama          #+#    #+#             */
/*   Updated: 2025/06/30 17:21:56 by houssam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	cleanup_readline(void)
{
	rl_clear_history();
	rl_free_line_state();
	rl_deprep_terminal();
}

static void	add_env_var(t_cmd_exec **lst, const char *name, const char *value)
{
	t_cmd_exec	*node;

	node = malloc(sizeof(t_cmd_exec));
	if (!node)
		return ;
	node->name = ft_strdup(name);
	node->value = ft_strdup(value);
	node->status = 0;
	node->meaning = 0;
	node->next = *lst;
	*lst = node;
}

static int	check_stat(t_cmd_exec *env_lst, int *status)
{
	while (env_lst->meaning != '?')
		env_lst = env_lst->next;
	if (env_lst->value)
	{
		if (ft_strncmp(env_lst->value, "exit", 5) == 0)
		{
			*status = env_lst->status;
			return (1);
		}
	}
	return (0);
}

static int	start(int ac, char **av, char **env, t_cmd_exec **env_lst)
{
	(void)av;
	if (ac > 1)
	{
		ft_putstr_fd("Error\nmore than one argument\n", 2);
		return (1);
	}
	ft_signals();
	env_to_lst(env, env_lst);
	add_env_var(env_lst, "0", "minishell");
	shell_vl(env_lst);
	return (0);
}

int	main(int ac, char **av, char **env)
{
	char		*cmd;
	t_cmd_exec	*env_lst;
	t_token		*tok;
	int			status;

	if (start(ac, av, env, &env_lst) == 1)
		return (0);
	while (1)
	{
		cmd = readline("<minishell> ");
		if (!cmd)
		{
			ft_putstr_fd("exit\n", 1);
			exit((lst_clear(&env_lst, free), cleanup_readline(), 0));
		}
		if (*cmd)
			add_history(cmd);
		parsing_line(cmd, &tok, &env_lst);
		free(cmd);
		if (check_stat(env_lst, &status) == 1)
			break ;
	}
	lst_clear(&env_lst, free);
	cleanup_readline();
	return (status);
}
