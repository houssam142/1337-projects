/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssam <houssam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 13:08:36 by aoussama          #+#    #+#             */
/*   Updated: 2025/07/26 11:19:35 by houssam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_handle_sigint(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	set_exit_code(130);
}

static void	cleanup_readline(void)
{
	rl_clear_history();
	rl_free_line_state();
	rl_deprep_terminal();
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

char *red_line(void)
{
    char *line = NULL;
    char *r_line = NULL;
    int len;
    if (isatty(STDIN_FILENO))
    {
        r_line = readline("<minishell> ");
    }
    else
    {
        line = get_next_line(STDIN_FILENO);
        if (!line)
            return NULL;

        len = ft_strlen(line);
        if (len > 0 && line[len - 1] == '\n')
            line[len - 1] = '\0';

        r_line = line;
    }
    return r_line;
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
		signal(SIGINT, ft_handle_sigint);
		signal(SIGQUIT, SIG_IGN);
		cmd = red_line();
		if (!cmd)
		{
			if (isatty(STDIN_FILENO))
				ft_putstr_fd("exit\n", 1);
			exit((lst_clear(&env_lst, free), cleanup_readline(), status));
		}
		if (*cmd)
			add_history(cmd);
		if (get_exit_code() == 130)
		{
			change_stat(&env_lst, get_exit_code());
			set_exit_code(0);
		}
		parsing_line(cmd, &tok, &env_lst);
		free(cmd);
		if (check_stat(env_lst, &status) == 1)
			break ;
	}
	lst_clear(&env_lst, free);
	cleanup_readline();
	return (status);
}
