#include "../include/cub3d.h"

static void	copy_rgb(char *line, int *i, t_parse *data, char c)
{
	int	j;
	int	k;

	while (ft_isspace(line[*i]))
		(*i)++;
	j = *i;
	k = 0;
	while (line[j] && line[j] != '\n')
	{
		j++;
		k++;
	}
	ft_alloc_str(data, k, c);
	if (c == 'F')
		ft_strlcpy(data->floor_color, &line[*i], k);
	else if (c == 'C')
		ft_strlcpy(data->celing_color, &line[*i], k);
	data->count_identifiers++;
	*i += j;
}

static void	textures_path(char *line, int *i, t_parse *data, char direction)
{
	int	j;
	int	k;

	while (ft_isspace(line[*i]))
		(*i)++;
	j = *i;
	k = 0;
	while (line[j] && line[j] != '\n')
	{
		j++;
		k++;
	}
	ft_alloc_str(data, k, direction);
	if (direction == 'N')
		ft_strlcpy(data->path_n, &line[*i], k + 1);
	else if (direction == 'S')
		ft_strlcpy(data->path_s, &line[*i], k + 1);
	else if (direction == 'E')
		ft_strlcpy(data->path_e, &line[*i], k + 1);
	else if (direction == 'W')
		ft_strlcpy(data->path_w, &line[*i], k + 1);
	data->count_identifiers++;
	*i += j;
}

void	check_identifiers(char *line, t_parse *data)
{
	int	i;
	int	len;

	i = 0;
	len = (int)ft_strlen(line);
	while (i < len && line[i])
	{
		while (line[i] && ft_isspace(line[i]))
			i++;
		if (!ft_strncmp(&line[i], "NO", 2))
			textures_path(&line[i + 2], &i, data, 'N');
		else if (!ft_strncmp(&line[i], "SO", 2))
			textures_path(&line[i + 2], &i, data, 'S');
		else if (!ft_strncmp(&line[i], "EA", 2))
			textures_path(&line[i + 2], &i, data, 'E');
		else if (!ft_strncmp(&line[i], "WE", 2))
			textures_path(&line[i + 2], &i, data, 'W');
		else if (line[i] == 'F')
			copy_rgb(&line[i + 1], &i, data, 'F');
		else if (line[i] == 'C')
			copy_rgb(&line[i + 1], &i, data, 'C');
		i++;
	}
}

int	check_map(t_parse *data)
{
	char	*line;

	line = get_next_line(data->fd);
	if (!line)
		exit((close(data->fd), 1));
	while (line)
	{
		check_identifiers(line, data);
		free(line);
		line = get_next_line(data->fd);
	}
	printf("%d\n", data->count_identifiers);
	return (0);
}

int	check_file(char *str, t_parse *data)
{
	int	len;
	int	fd;

	len = ft_strlen(str);
	if (ft_strncmp(&str[len - 4], ".cub", 3))
		return (ft_putstr_fd("it's not a valid map\n", 2), 1);
	if (errno == ENOTDIR)
	{
		printf("here\n");
		fd = open(str, O_RDONLY);
	}
	else if (errno == EISDIR)
	{
		ft_putstr_fd("It's a directory\n", 2);
		exit(1);
	}
	if (fd == -1)
	{
		ft_putstr_fd("file doesn't exist\n", 2);
		exit(1);
	}
	data->fd = fd;
	return (0);
}
