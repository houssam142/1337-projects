/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 21:12:00 by hounejja          #+#    #+#             */
/*   Updated: 2025/03/24 06:19:35 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	error_mov_bonus(t_game *w)
{
	if (!w->player)
	{
		free_all(w);
		if (w->win)
			mlx_destroy_window(w->mlx, w->win);
		mlx_destroy_display(w->mlx);
		free(w->mlx);
		ft_free(w->map);
		write(2, "Error\nimg doesn't exist\n", 25);
		exit(1);
	}
}

void	put(t_game *w)
{
	char	*str;

	str = ft_itoa(w->moves++);
	if (!str)
	{
		close_win_1_bonus(w);
		exit (write(2, "Error\nstring empty\n", 20));
	}
	mlx_put_image_to_window(w->mlx, w->win, w->bkg, 0, 0);
	mlx_string_put(w->mlx, w->win, 11, 17, 0xFFFF, str);
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
	if (w->bkg)
		mlx_destroy_image(w->mlx, w->bkg);
	destroy_anim(w);
}

void	error_check_bonus(t_game *w)
{
	if (!w->player || !w->wall || !w->floor || !w->door
		|| !w->collec || !w->enemy || !w->bkg
		|| !w->sprite[0] || !w->sprite[1] || !w->sprite[2])
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
