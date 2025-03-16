/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 18:02:01 by hounejja          #+#    #+#             */
/*   Updated: 2025/03/12 00:16:17 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

int	ft_strlen1_b(char *str)
{
	int (i) = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
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
		draw_img(game, game->x_ext, game->y_ext, game->door);
	}
	return (0);
}
