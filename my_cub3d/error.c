/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 20:51:38 by hounejja          #+#    #+#             */
/*   Updated: 2025/09/15 09:59:15 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

void	print_error(enum e_parsing type)
{
	free_grabage();
	if (type == TEXTURE)
		exit((ft_putstr_fd("\033[1;31mThere is an error in texture path's"
					" syntax\n", 2), 1));
	else if (type == COLOR)
		exit((ft_putstr_fd(COLOR_S, 2), 1));
	else if (type == FILE1)
		exit((ft_putstr_fd("\033[1;31mError\nthe file just needs six"
					" identifiers\n", 2), 1));
	else if (type == MAP)
		exit((ft_putstr_fd(PARSING_S, 2), 1));
	else if (type == EMPTY)
		exit((ft_putstr_fd("\033[1;31mError\nempty map\n\033[0m", 2), 1));
	else if (type == EXTENSION)	
		exit((ft_putstr_fd(EXT_S, 2), 1));
	else if (type == ORDER)
		exit((ft_putstr_fd("\033[1;31mError\nwrong order\n\033[0m", 2), 1));
	else if (type == PLAYER)
		exit((ft_putstr_fd("\033[1;31mError\ninvalid player"
					" position\n\033[0m", 2), 1));
	else if (type == WALL)
		exit((ft_putstr_fd("\033[1;31mError\nMap is not"
					" closed by walls\n\033[0m", 2), 1));
	else if (type == SMALL)
		exit((ft_putstr_fd("\033[1;31mError\nMap too small\n\033[0m", 2), 1));
}
