/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 18:02:01 by hounejja          #+#    #+#             */
/*   Updated: 2025/03/22 01:26:42 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	destroy(t_game *w)
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
}

static void	check_door_open_error(t_game *w)
{
	if (!w->door)
	{
		destroy(w);
		mlx_destroy_display(w->mlx);
		free(w->mlx);
		ft_free(w->map);
		write(2, "Error\nimg doesn't exist\n", 25);
		exit(1);
	}
}

int	count_collectibles(t_game *game)
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

int	collecting(t_game *game)
{
	if (game->map[game->x_player][game->y_player] == 'C')
	{
		game->collected++;
		game->map[game->x_player][game->y_player] = '0';
	}
	if (game->collected == game->sum_of_collec)
	{
		mlx_destroy_image(game->mlx, game->door);
		game->door = mlx_xpm_file_to_image(game->mlx,
				"texture/imgs/exit_open_01.xpm", &game->width, &game->height);
		check_door_open_error(game);
		draw_img(game, game->x_ext, game->y_ext, game->door);
	}
	return (0);
}
