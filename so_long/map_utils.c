/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 00:02:55 by hounejja          #+#    #+#             */
/*   Updated: 2025/03/12 01:06:20 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_position(t_win *game, int *x, int *y, char asset)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == asset)
			{
				*x = i;
				*y = j;
			}
			j++;
		}
		i++;
	}
}

void	ft_join_and_free(char **str, void *buf)
{
	char	*tmp;

	tmp = ft_strjoin(*str, buf);
	free(*str);
	*str = tmp;
}

char	*check_the_fd(char *file_name)
{
	int (fd);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		exit(1);
	return (file_name);
}
