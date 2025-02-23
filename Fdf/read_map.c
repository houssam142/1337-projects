/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 08:16:17 by hounejja          #+#    #+#             */
/*   Updated: 2025/02/23 13:11:01 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_the_map(char *file_name, t_struct **head)
{
	char **(map);
	char *(line);
	int (fd), rows = 0, columns = 0;
	fd = open(check_the_fd(file_name), O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		map = ft_split(line);
		if (!map)
			return (ft_free(map), free(line), 1);
		while (map[rows])
		{
			create_list(head, rows, columns, map[rows]);
			rows++;
		}
		rows = 0;
		columns = increment_and_free(columns, line, map);
		line = get_next_line(fd);
	}
	return (0);
}
