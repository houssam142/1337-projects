/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 02:59:30 by hounejja          #+#    #+#             */
/*   Updated: 2025/08/21 08:25:28 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	line_all_ones(char *line, char one)
{
	int	i;

	i = 0;
	line = ft_strtrim(line, "\n");
	if (!line[0])
		return (0);
	while (line[i])
	{
		if (line[i] != one)
			return (free(line), 0);
		i++;
	}
	free(line);
	return (1);
}

static int	check_if_map_empty(char **arr)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (arr[i])
	{
		arr[i] = ft_strtrim(arr[i], " ");
		if (line_all_ones(arr[i], '1'))
			flag = 1;
		i++;
	}
	if (!flag)
		ft_free(arr);
	return (flag);
}

static int	line_count(char *str)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = check_file(str);
	line = get_next_line(fd);
	if (!line)
		exit((close(fd), 1));
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (i);
}

char	**ft_return_map_game(char *str, t_parse *data)
{
	char	*line;
	char	**arr;
	int		fd;
	int		i;

	arr = malloc(sizeof(char *) * (line_count(str) + 1));
	fd = check_file(str);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		arr[i] = ft_strdup(line);
		if (!arr[i])
			exit((close(fd), 1));
		free(line);
		i++;
		line = get_next_line(fd);
	}
	arr[i] = NULL;
	close(fd);
	if (!check_if_map_empty(arr))
		print_error(EMPTY, data);
	return (arr);
}
