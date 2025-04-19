/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 00:02:55 by hounejja          #+#    #+#             */
/*   Updated: 2025/03/21 23:29:42 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	get_position(t_game *game, int *x, int *y, char asset)
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

void	ft_join_and_free_b(char **str, void *buf)
{
	char	*tmp;

	tmp = ft_strjoin(*str, buf);
	free(*str);
	*str = tmp;
}
