/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 18:02:01 by hounejja          #+#    #+#             */
/*   Updated: 2025/03/22 01:27:50 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_collectibles(t_win *game)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (game->map[i][j])
	{
		if (game->map[i][j] == 'C')
			count++;
		j++;
	}
	return (count);
}

int	collecting(t_win *game)
{
	if (game->map[game->x_player][game->y_player] == 'C')
	{
		game->collected++;
		game->map[game->x_player][game->y_player] = '0';
	}
	return (0);
}
