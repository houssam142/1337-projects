/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 20:51:38 by hounejja          #+#    #+#             */
/*   Updated: 2025/10/03 17:18:25 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

void	print_error(enum e_parsing type)
{
	free_garbage();
	if (type == TEXTURE)
		exit((ft_putstr_fd("There is an error in texture path's"
					" syntax\n", 2), 1));
	else if (type == COLOR)
		exit((ft_putstr_fd(COLOR_S, 2), 1));
	else if (type == FILE1)
		exit((ft_putstr_fd("Error\nthe file just needs six"
					" identifiers\n", 2), 1));
	else if (type == MAP)
		exit((ft_putstr_fd(PARSING_S, 2), 1));
	else if (type == EMPTY)
		exit((ft_putstr_fd("Error\nempty map\n", 2), 1));
	else if (type == EXTENSION)
		exit((ft_putstr_fd(EXT_S, 2), 1));
	else if (type == ORDER)
		exit((ft_putstr_fd("Error\nwrong order\n", 2), 1));
	else if (type == PLAYER)
		exit((ft_putstr_fd(PLAYER_E, 2), 1));
	else if (type == WALL)
		exit((ft_putstr_fd(WALL_E, 2), 1));
	else if (type == SMALL)
		exit((ft_putstr_fd("Error\nMap too small\n", 2), 1));
	else if (type == ERROR)
		exit((ft_putstr_fd("Error\nfunction failed\n", 2), 1));
}
