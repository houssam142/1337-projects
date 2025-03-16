/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 21:12:00 by hounejja          #+#    #+#             */
/*   Updated: 2025/03/12 16:08:53 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_all(t_win *w)
{
	if (w->player)
		mlx_destroy_image(w->mlx, w->player);
	if (w->wall)
		mlx_destroy_image(w->mlx, w->wall);
	if (w->collec)
		mlx_destroy_image(w->mlx, w->collec);
	if (w->door)
		mlx_destroy_image(w->mlx, w->door);
	if (w->floor)
		mlx_destroy_image(w->mlx, w->floor);
}

void	error_check(t_win *w)
{
	if (!w->player || !w->wall || !w->floor || !w->door
		|| !w->collec)
	{
		free_all(w);
		mlx_destroy_display(w->mlx);
		free(w->mlx);
		ft_free(w->map);
		write(2, "Error\nimg doesn't exist\n", 25);
		exit(1);
	}
}

void	flood_fill(char **map, int x, int y, t_win *w)
{
	if (!map || !*map)
		return ;
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
