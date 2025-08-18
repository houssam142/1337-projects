/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 02:59:30 by hounejja          #+#    #+#             */
/*   Updated: 2025/08/18 05:58:50 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	ft_join(char **arr, char *line, int i)
{
	char	*tmp;

	tmp = ft_strjoin(arr[i], line);
	free(arr[i]);
	arr[i] = tmp;
}

static int	line_count(char *str)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = check_file(str);
	line = get_next_line(fd);
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	return (i);
}

char    **ft_return_map_game(char *str)
{
    char    *line;
    char    **arr;
	int		fd;
	int		i;

    arr = malloc(sizeof(char *)* line_count(str) + 1);
	fd = check_file(str);
	i = 0;
    line = get_next_line(fd);
	if (!line)
		exit((close(fd), 1));
	while (line)
	{
		arr[i] = ft_strdup(line);
		if (!arr[i])
			exit((close(fd), 1));
		free(line);
		i++;
		line = get_next_line(fd);
	}
	close(fd);
	return (arr);
}
