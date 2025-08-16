#include "include/cub3d.h"

static void	init_parse(t_parse *data)
{
	data->fd = -1;
	data->path_e = NULL;
	data->path_n = NULL;
	data->path_s = NULL;
	data->path_w = NULL;
}

int	parse_args(char **av, t_parse *data)
{
	if (check_file(av[1], data))
		return (1);
	return (0);
}

int main(int ac, char **av)
{
	t_parse	data;
	if (ac != 2)
		return (ft_putstr_fd("Invalid arguments\n", 2), 1);
	init_parse(&data);
	if (parse_args(av, &data))
		return (1);
	return (0);
}
