/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 11:04:49 by hounejja          #+#    #+#             */
/*   Updated: 2025/03/24 03:30:27 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_img(t_win *game, int i, int j, void *img)
{
	mlx_put_image_to_window(game->mlx, game->win, img, j * 32, i * 32);
}

void	draw_floor(t_win *w, void *img)
{
	int	i;
	int	j;

	size_of_win(w);
	i = 0;
	while (i < w->height)
	{
		j = 0;
		while (j < w->width)
		{
			draw_img(w, i, j, img);
			j++;
		}
		i++;
	}
}

void	draw_map(t_win *game, void *img, char c)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == c)
				draw_img(game, i, j, img);
			j++;
		}
		i++;
	}
}

void	render_images(t_win *game)
{
	draw_floor(game, game->floor);
	draw_map(game, game->wall, '1');
	draw_map(game, game->collec, 'C');
	draw_map(game, game->door, 'E');
	draw_map(game, game->player, 'P');
}

void	render(t_win *w)
{
	w->wall = mlx_xpm_file_to_image(w->mlx, "texture/imgs/blockSimple.xpm",
			&w->img_width, &w->img_height);
	w->player = mlx_xpm_file_to_image(w->mlx, "texture/imgs/idle_00.xpm",
			&w->img_width, &w->img_height);
	w->door = mlx_xpm_file_to_image(w->mlx, "texture/imgs/exit_close_01.xpm",
			&w->img_width, &w->img_height);
	w->collec = mlx_xpm_file_to_image(w->mlx, "texture/imgs/star_00.xpm",
			&w->img_width, &w->img_height);
	w->floor = mlx_xpm_file_to_image(w->mlx, "texture/imgs/midBlocks_02.xpm",
			&w->img_width, &w->img_height);
	error_check(w);
}
