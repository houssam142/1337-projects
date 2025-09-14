/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 05:05:20 by houssam           #+#    #+#             */
/*   Updated: 2025/09/14 15:12:10 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	arr_len(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	check_map(char **map)
{
	int		i;
	int		len;
	int		size;
	char	*line;

	i = 0;
	size = arr_len(map);
	if (!line_all_ones(map[0], '1') || !line_all_ones(map[size - 1], '1'))
		print_error(WALL);
	while (map[i])
	{
		line = map[i];
		line = ft_strtrim(line, " \n");
		len = ft_strlen(line);
		if (line[0] != '1' && line[len - 1] != '1')
			break ;
		i++;
	}
	if (i < size)
		print_error(WALL);
}
