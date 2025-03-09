/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 22:07:30 by hounejja          #+#    #+#             */
/*   Updated: 2025/03/09 14:12:37 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_win *game, void *img)
{
	ft_printf("Player moves: %d\n", ++game->moves);
	if (game->player)
		mlx_destroy_image(game->mlx, game->player);
	game->player = mlx_xpm_file_to_image(game->mlx,
			"Texture/imgs/walkUP_00.xpm",
			&game->width, &game->height);
	draw_img(game, game->x_player, game->y_player, img);
	if (game->map[game->x_player - 1][game->y_player] == 'E')
	{
		if (game->collected == game->sum_of_collec)
		{
			draw_img(game, game->x_player, game->y_player, game->player);
			ft_close(game);
		}
		else
		{
			draw_img(game, game->x_player, game->y_player, game->player);
			return ;
		}
	}
	draw_img(game, --game->x_player, game->y_player, game->player);
}

void	move_left(t_win *game, void *img)
{
	ft_printf("Player moves: %d\n", ++game->moves);
	if (game->player)
		mlx_destroy_image(game->mlx, game->player);
	game->player = mlx_xpm_file_to_image(game->mlx,
			"Texture/imgs/walkLeft_01.xpm", &game->width, &game->height);
	draw_img(game, game->x_player, game->y_player, img);
	if (game->map[game->x_player][game->y_player - 1] == 'E')
	{
		if (game->collected == game->sum_of_collec)
		{
			draw_img(game, game->x_player, game->y_player, game->player);
			ft_close(game);
		}
		else
		{
			draw_img(game, game->x_player, game->y_player, game->player);
			return ;
		}
	}
	draw_img(game, game->x_player, --game->y_player, game->player);
}

int	plays1(int key, t_win *game, void *img)
{
	if (key == S && game->map[game->x_player + 1][game->y_player] != '1')
	{
		ft_printf("Player moves: %d\n", ++game->moves);
		if (game->player)
			mlx_destroy_image(game->mlx, game->player);
		game->player = mlx_xpm_file_to_image(game->mlx,
				"Texture/imgs/walkDown_00.xpm", &game->width, &game->height);
		draw_img(game, game->x_player, game->y_player, img);
		if (game->map[game->x_player + 1][game->y_player] == 'E')
		{
			if (game->collected == game->sum_of_collec)
			{
				draw_img(game, game->x_player, game->y_player, game->player);
				ft_close(game);
			}
			else
				return (draw_img(game, game->x_player,
						game->y_player, game->player), 1);
		}
		draw_img(game, ++game->x_player, game->y_player, game->player);
	}
	else if (key == A && game->map[game->x_player][game->y_player - 1] != '1')
		move_left(game, img);
	return (0);
}

int	plays(int key, t_win *game, void *img)
{
	if (key == D && game->map[game->x_player][game->y_player + 1] != '1')
	{
		ft_printf("Player moves: %d\n", ++game->moves);
		if (game->player)
			mlx_destroy_image(game->mlx, game->player);
		game->player = mlx_xpm_file_to_image(game->mlx,
				"Texture/imgs/walkRight_00.xpm", &game->width, &game->height);
		draw_img(game, game->x_player, game->y_player, img);
		if (game->map[game->x_player][game->y_player + 1] == 'E')
		{
			if (game->collected == game->sum_of_collec)
			{
				draw_img(game, game->x_player, game->y_player, game->player);
				ft_close(game);
			}
			else
				return (draw_img(game, game->x_player,
						game->y_player, game->player), 1);
		}
		draw_img(game, game->x_player, ++game->y_player, game->player);
	}
	else if (key == W && game->map[game->x_player - 1][game->y_player] != '1')
		move_up(game, img);
	plays1(key, game, img);
	return (0);
}
