#include "include/cub3d.h"

static void	struct_free(t_parse *data)
{
	free(data->path_e);
	free(data->path_n);
	free(data->path_s);
	free(data->path_w);
	free(data->celing_color);
	free(data->floor_color);
}

static void	init_parse(t_parse *data)
{
	data->fd = -1;
	data->count_identifiers = 0;
	data->path_e = NULL;
	data->path_n = NULL;
	data->path_s = NULL;
	data->path_w = NULL;
	data->celing_color = NULL;
	data->floor_color = NULL;
}

int	parse_args(char **av, t_parse *data)
{
	if (check_file(av[1], data))
		return (1);
	check_map(data);
	return (0);
}

int	main(int ac, char **av)
{
	t_parse	data;

	if (ac != 2)
		return (ft_putstr_fd("Invalid arguments\n", 2), 1);
	init_parse(&data);
	if (parse_args(av, &data))
		return (1);
	struct_free(&data);
	return (0);
}
