#include "../include/cub3d.h"

char	*check_identifiers(char *line)
{
	
}

int	check_map(char *file, t_parse *data)
{
	char	*line;
	char	*characters;

	characters = NULL;
	line = get_next_line(data->fd);
	if (!line)
		exit((close(data->fd), 1));
	while (line)
	{

		line = get_next_line(data->fd);
	}
	return (0);	
}

int	check_file(char *str, t_parse *data)
{
	int	len;
	int	fd;

	len = ft_strlen(str);
	if (ft_strncmp(&str[len - 4], ".cub", 3))
	{
		ft_putstr_fd("it's not a valid map\n", 2);
		return (1);
	}
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		if (errno == EISDIR)
		{
			ft_putstr_fd("this path is a directory\n", 2);
			exit(1);
		}
		else
		{
			ft_putstr_fd("file doesn't exist\n", 2);
			exit(1);
		}
	}
	data->fd = fd;
	return (0);
}
