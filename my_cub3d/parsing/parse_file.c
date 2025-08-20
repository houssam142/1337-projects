/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 02:59:37 by hounejja          #+#    #+#             */
/*   Updated: 2025/08/20 16:01:26 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	copy_rgb(char *line, t_parse *data, char c)
{
	char	**arr;
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strdup("");
	line = ft_strtrim(line, " ");
	if (c == 'F')
	{
		arr = ft_split(line, ' ');
		while (arr[i] != NULL)
			tmp = ft_strjoin(tmp, arr[i++]);
		data->floor_color = ft_strtrim(tmp, "\n");
		ft_free(arr);
		free(tmp);
	}
	else if (c == 'C')
	{
		arr = ft_split(line, ' ');
		while (arr[i])
			tmp = ft_strjoin(tmp, arr[i++]);
		data->celing_color = ft_strtrim(tmp, "\n");
		ft_free(arr);
		free(tmp);
	}
	data->count_identifiers++;
}

static void	textures_path(char *line, int *i, t_parse *data, char direction)
{
	int	j;
	int	k;
	int	h;

	j = 0;
	line = ft_strtrim(line, " ");
	k = 0;
	h = 0;
	while (line[h] && !ft_isspace(line[h]))
	{
		h++;
		k++;
	}
	ft_alloc_str(data, k, direction);
	if (direction == 'N')
		ft_strlcpy(data->path_n, line, k + 1);
	else if (direction == 'S')
		ft_strlcpy(data->path_s, line, k + 1);
	else if (direction == 'E')
		ft_strlcpy(data->path_e, line, k + 1);
	else if (direction == 'W')
		ft_strlcpy(data->path_w, line, k + 1);
	data->count_identifiers++;
	*i += j;
}

int	check_identifiers(char *line, t_parse *data)
{
	int	i;
	int	len;

	i = 0;
	len = (int)ft_strlen(line);
	while (i < len && line[i])
	{
		while (line[i] && ft_isspace(line[i]))
			i++;
		check_order(&line[i], data);
		if (!ft_strncmp(&line[i], "NO", 2))
			textures_path(&line[i + 2], &i, data, 'N');
		else if (!ft_strncmp(&line[i], "SO", 2))
			textures_path(&line[i + 2], &i, data, 'S');
		else if (!ft_strncmp(&line[i], "EA", 2))
			textures_path(&line[i + 2], &i, data, 'E');
		else if (!ft_strncmp(&line[i], "WE", 2))
			textures_path(&line[i + 2], &i, data, 'W');
		else if (line[i] == 'F')
			copy_rgb(&line[i + 1], data, 'F');
		else if (line[i] == 'C')
			copy_rgb(&line[i + 1], data, 'C');
		i++;
	}
	return (data->count_identifiers);
}

int	check_extensions(char *str, t_parse *data)
{
	char	*line;
	int		count;
	int		fd;

	fd = check_file(str);
	line = get_next_line(fd);
	if (!line)
		exit((close(fd), print_error(EMPTY), 1));
	while (line)
	{
		count = check_identifiers(line, data);
		free(line);
		line = get_next_line(fd);
	}
	if (!data->flag)
		print_error(EMPTY);
	else if (data->flag)
		print_error(ORDER);
	if (count != 6)
	{
		struct_free(data);
		print_error(FILE1);
	}
	check_texture_syntax(data);
	check_colors(data);
	return (0);
}

int	check_file(char *str)
{
	int		len;
	int		fd;
	char	*buff;

	len = (int)ft_strlen(str);
	if (ft_strncmp(&str[len - 4], ".cub", 3))
		print_error(EXTENSION);
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("file doesn't exist\n", 2);
		exit(1);
	}
	else
	{
		if (read(fd, &buff, 0) == -1 && errno == EISDIR)
		{
			ft_putstr_fd("it's a directory, not a file\n", 2);
			exit((close(fd), 1));
		}
	}
	return (fd);
}
