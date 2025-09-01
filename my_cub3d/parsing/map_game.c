/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 02:59:30 by hounejja          #+#    #+#             */
/*   Updated: 2025/09/01 09:49:56 by hounejja         ###   ########.fr       */
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
			return (0);
		i++;
	}
	return (1);
}

static int	check_if_map_empty(char **arr)
{
	int		i;
	int		flag;
	char	*line;

	i = 0;
	flag = 0;
	while (arr[i])
	{
		line = ft_strtrim(arr[i], " ");
		if (line_all_ones(line, '1'))
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
		line = get_next_line(fd);
	}
	close(fd);
	return (i);
}

char	**ft_return_map_game(char *str)
{
	char	*line;
	char	**arr;
	int		fd;
	int		i;

	arr = ft_malloc(sizeof(char *) * (line_count(str) + 1));
	fd = check_file(str);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		arr[i] = ft_strdup(line);
		if (!arr[i])
			exit((close(fd), 1));
		i++;
		line = get_next_line(fd);
	}
	arr[i] = NULL;
	close(fd);
	if (!check_if_map_empty(arr))
		print_error(EMPTY);
	return (arr);
}
