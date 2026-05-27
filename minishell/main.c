/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 20:15:02 by nafarid           #+#    #+#             */
/*   Updated: 2026/05/27 23:07:45 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*join_with_newline(char *cmd, char *next)
{
	char	*res;
	char	*tmp;

	tmp = ft_strjoin(cmd, "\n");
	res = ft_strjoin(tmp, next);
	return (res);
}

static void	check_ctrl_c(t_cmd_exec *env_lst)
{
	if (get_exit_code() == 130)
	{
		change_stat(&env_lst, get_exit_code());
		set_exit_code(0);
	}
}

void	ft_handle_sigint(int sig)
{
	(void)sig;
	write(2, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	set_exit_code(130);
}

static int	check_stat(t_cmd_exec *env_lst, int *status)
{
	while (env_lst->meaning != '?')
		env_lst = env_lst->next;
	if (env_lst->meaning == '?')
		*status = env_lst->status;
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

static void matching_quotes(char *cmd, t_token *tok, t_cmd_exec *env_lst)
{
	char		*next;

	while (parsing_line(cmd, &tok, &env_lst) == TOK_INCOMPLETE)
	{
		next = readline("quote> ");
		if (!next)
		{
			ft_putstr_fd("\nminishelll: unexpected EOF while looking for matching `''\n", 2);
			break;
		}
		cmd = join_with_newline(cmd, next);
	}
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
	return (0);
}

int	main(int ac, char **av, char **env)
{
	char		*cmd;
	t_cmd_exec	*env_lst;
	t_token		*tok;
	int			status;

	status = 0;
	tok = NULL;
	if (start(ac, av, env, &env_lst) == 1)
		return (0);
	while (1)
	{
		signal(SIGINT, ft_handle_sigint);
		signal(SIGQUIT, SIG_IGN);
		cmd = readline("<Minishell> ");
		if (!cmd)
			ft_exitt(&status);
		if (*cmd)
			add_history(cmd);
		check_ctrl_c(env_lst);
		matching_quotes(cmd, tok, env_lst);
		if (check_stat(env_lst, &status) == 1)
			break ;
	}
	return (free_grabage(), status);
}
