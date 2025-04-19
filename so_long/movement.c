/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 22:07:30 by hounejja          #+#    #+#             */
/*   Updated: 2025/03/24 06:16:29 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_win *game, void *img)
{
	ft_printf("Player moves: %d\n", ++game->moves);
	if (game->player)
		mlx_destroy_image(game->mlx, game->player);
	game->player = mlx_xpm_file_to_image(game->mlx,
			"texture/imgs/walkUP_00.xpm", &game->width, &game->height);
	error_mov(game);
	draw_img(game, game->x_player, game->y_player, img);
	if (game->map[game->x_player - 1][game->y_player] == 'E')
	{
		if (game->collected == game->sum_of_collec)
		{
			draw_img(game, game->x_player, game->y_player, game->player);
			ft_printf("We have a winner\n");
			ft_close(game);
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
			"texture/imgs/walkLeft_01.xpm", &game->width, &game->height);
	error_mov(game);
	draw_img(game, game->x_player, game->y_player, img);
	if (game->map[game->x_player][game->y_player - 1] == 'E')
	{
		if (game->collected == game->sum_of_collec)
		{
			draw_img(game, game->x_player, game->y_player, game->player);
			ft_printf("We have a winner\n");
			ft_close(game);
		}
	}
	draw_img(game, game->x_player, --game->y_player, game->player);
}

int	plays1(int key, t_win *game, void *img)
{
	if ((key == S || key == 65364) && game->map[game->x_player
			+ 1][game->y_player] != '1')
	{
		ft_printf("Player moves: %d\n", ++game->moves);
		if (game->player)
			mlx_destroy_image(game->mlx, game->player);
		game->player = mlx_xpm_file_to_image(game->mlx,
				"texture/imgs/walkDown_00.xpm", &game->width, &game->height);
		error_mov(game);
		draw_img(game, game->x_player, game->y_player, img);
		if (game->map[game->x_player + 1][game->y_player] == 'E')
		{
			if (game->collected == game->sum_of_collec)
			{
				draw_img(game, game->x_player, game->y_player, game->player);
				ft_printf("We have a winner\n");
				ft_close(game);
			}
		}
		draw_img(game, ++game->x_player, game->y_player, game->player);
	}
	else if ((key == A || key == 65361)
		&& game->map[game->x_player][game->y_player - 1] != '1')
		move_left(game, img);
	return (0);
}

int	plays(int key, t_win *game, void *img)
{
	if ((key == D || key == 65363) && game->map[game->x_player][game->y_player
		+ 1] != '1')
	{
		ft_printf("Player moves: %d\n", ++game->moves);
		if (game->player)
			mlx_destroy_image(game->mlx, game->player);
		game->player = mlx_xpm_file_to_image(game->mlx,
				"texture/imgs/walkRight_00.xpm", &game->width, &game->height);
		error_mov(game);
		draw_img(game, game->x_player, game->y_player, img);
		if (game->map[game->x_player][game->y_player + 1] == 'E')
		{
			if (game->collected == game->sum_of_collec)
			{
				draw_img(game, game->x_player, game->y_player, game->player);
				ft_printf("We have a winner\n");
				ft_close(game);
			}
		}
		draw_img(game, game->x_player, ++game->y_player, game->player);
	}
	else if ((key == W || key == 65362) && game->map[game->x_player
			- 1][game->y_player] != '1')
		move_up(game, img);
	return (plays1(key, game, img), 0);
}
