/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 21:12:00 by hounejja          #+#    #+#             */
/*   Updated: 2025/03/09 15:38:10 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **map, int x, int y, t_win *w)
{
	if (x < 0 || y < 0 || x >= w->width || y >= w->height)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'X')
		return ;
	map[y][x] = 'X';
	flood_fill(map, x - 1, y, w);
	flood_fill(map, x + 1, y, w);
	flood_fill(map, x, y + 1, w);
	flood_fill(map, x, y - 1, w);
}
