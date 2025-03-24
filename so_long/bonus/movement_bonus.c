/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 22:07:30 by hounejja          #+#    #+#             */
/*   Updated: 2025/03/23 23:17:10 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	move_right(t_game *game, void *img)
{
	if (game->player)
		mlx_destroy_image(game->mlx, game->player);
	game->player = mlx_xpm_file_to_image(game->mlx,
			"texture/imgs/walkRight_00.xpm", &game->width, &game->height);
	error_mov_bonus(game);
	draw_img(game, game->x_player, game->y_player, img);
	if (game->map[game->x_player][game->y_player + 1] == 'E'
		|| game->map[game->x_player][game->y_player + 1] == 'B')
	{
		if (game->map[game->x_player][game->y_player + 1] == 'B')
			return (draw_img(game, game->x_player, game->y_player,
					game->player), write(1, "You lost\n", 10), ft_close(game),
				1);
		else if (game->collected == game->sum_of_collec)
			return (ft_printf1("We have a winner\n"), draw_img(game,
					game->x_player, game->y_player, game->player),
				ft_close(game), 1);
	}
	draw_img(game, game->x_player, ++game->y_player, game->player);
	return (0);
}

int	move_up(t_game *game, void *img)
{
	if (game->player)
		mlx_destroy_image(game->mlx, game->player);
	game->player = mlx_xpm_file_to_image(game->mlx,
			"texture/imgs/walkUP_00.xpm", &game->width, &game->height);
	error_mov_bonus(game);
	draw_img(game, game->x_player, game->y_player, img);
	if (game->map[game->x_player - 1][game->y_player] == 'E'
		|| game->map[game->x_player - 1][game->y_player] == 'B')
	{
		if (game->map[game->x_player - 1][game->y_player] == 'B')
			return (draw_img(game, game->x_player, game->y_player,
					game->player), write(1, "You lost\n", 10), ft_close(game),
				1);
		else if (game->collected == game->sum_of_collec)
		{
			draw_img(game, game->x_player, game->y_player, game->player);
			ft_printf1("We have a winner\n");
			ft_close(game);
		}
	}
	draw_img(game, --game->x_player, game->y_player, game->player);
	return (0);
}

int	move_left(t_game *game, void *img)
{
	put(game);
	if (game->player)
		mlx_destroy_image(game->mlx, game->player);
	game->player = mlx_xpm_file_to_image(game->mlx,
			"texture/imgs/walkLeft_01.xpm", &game->width, &game->height);
	error_mov_bonus(game);
	draw_img(game, game->x_player, game->y_player, img);
	if (game->map[game->x_player][game->y_player - 1] == 'E'
		|| game->map[game->x_player][game->y_player - 1] == 'B')
	{
		if (game->map[game->x_player][game->y_player - 1] == 'B')
			return (draw_img(game, game->x_player, game->y_player,
					game->player), write(1, "You lost\n", 10), ft_close(game),
				1);
		else if (game->collected == game->sum_of_collec)
			return (draw_img(game, game->x_player, game->y_player,
					game->player), ft_printf1("We have a winner\n"),
				ft_close(game), 0);
	}
	draw_img(game, game->x_player, --game->y_player, game->player);
	return (0);
}

int	plays1(int key, t_game *game, void *img)
{
	if ((key == S || key == 65364)
		&& game->map[game->x_player + 1][game->y_player] != '1')
	{
		put(game);
		if (game->player)
			mlx_destroy_image(game->mlx, game->player);
		game->player = mlx_xpm_file_to_image(game->mlx,
				"texture/imgs/walkDown_00.xpm", &game->width, &game->height);
		error_mov_bonus(game);
		draw_img(game, game->x_player, game->y_player, img);
		if (game->map[game->x_player + 1][game->y_player] == 'E'
			|| game->map[game->x_player + 1][game->y_player] == 'B')
		{
			if (game->map[game->x_player + 1][game->y_player] == 'B')
				return (draw_img(game, game->x_player, game->y_player,
						game->player), write(1, "You lost\n", 10),
					ft_close(game), 1);
			else if (game->collected == game->sum_of_collec)
				return (draw_img(game, game->x_player, game->y_player,
						game->player), ft_printf1("We have a winner\n"),
					ft_close(game), 0);
		}
		draw_img(game, ++game->x_player, game->y_player, game->player);
	}
	return (0);
}

int	plays(int key, t_game *game, void *img)
{
	if ((key == D || key == 65363)
		&& game->map[game->x_player][game->y_player + 1] != '1')
	{
		put(game);
		move_right(game, img);
	}
	else if ((key == W || key == 65362)
		&& game->map[game->x_player - 1][game->y_player] != '1')
	{
		put(game);
		move_up(game, img);
	}
	else if ((key == A || key == 65361)
		&& game->map[game->x_player][game->y_player - 1] != '1')
		move_left(game, img);
	plays1(key, game, img);
	return (0);
}
