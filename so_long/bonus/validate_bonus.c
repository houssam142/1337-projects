/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 21:12:00 by hounejja          #+#    #+#             */
/*   Updated: 2025/03/16 01:30:02 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put(t_game *w)
{
	char	*str;

	str = ft_itoa(w->moves++);
	mlx_put_image_to_window(w->mlx, w->win, w->bkg, 8, 3);
	mlx_string_put(w->mlx, w->win, 13, 17, 0xFFFFFF, str);
	free(str);
}

void	free_all(t_game *w)
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
	if (w->enemy)
		mlx_destroy_image(w->mlx, w->enemy);
}

void	error_check_bonus(t_game *w)
{
	if (!w->player || !w->wall || !w->floor || !w->door
		|| !w->collec || !w->enemy)
	{
		free_all(w);
		mlx_destroy_display(w->mlx);
		free(w->mlx);
		ft_free(w->map);
		write(2, "Error\nimg doesn't exist\n", 25);
		exit(1);
	}
}

void	flood_fill_bonus(char **map, int x, int y, t_game *w)
{
	if (x < 0 || y < 0 || x >= w->width || y >= w->height)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'X')
		return ;
	map[y][x] = 'X';
	flood_fill_bonus(map, x - 1, y, w);
	flood_fill_bonus(map, x + 1, y, w);
	flood_fill_bonus(map, x, y + 1, w);
	flood_fill_bonus(map, x, y - 1, w);
}
