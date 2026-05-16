#include "../minishell.h"

int	check_flags(char *arg, int* flag)
{
	(void)flag;
	int	i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] == '-' && !i)
			continue;
		i++;
	}
	return 0;
}

int	ft_type(t_cmd* cmd, t_cmd_exec **env)
{
	int	i;
	int	flag;

	i = 1;
	flag = 0;
	while (cmd->args[i])
	{
		if (check_flags(cmd->args[i], &flag) == 1)
		{
			i++;
			continue;
		}
		i++;
	}
	change_stat(env, 0);
	return (0);
}
