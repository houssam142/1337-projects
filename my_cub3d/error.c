/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 20:51:38 by hounejja          #+#    #+#             */
/*   Updated: 2025/09/01 09:44:39 by hounejja         ###   ########.fr       */
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
		exit((ft_putstr_fd("\033[1;31mError: invalid color format\n", 2), 1));
	else if (type == FILE1)
		exit((ft_putstr_fd("\033[1;31mthe file just needs six identifiers\n",
					2), 1));
	else if (type == MAP)
		exit((ft_putstr_fd("\033[1;31mError: Map parsing failed\n", 2),
				 1));
	else if (type == EMPTY)
		exit((ft_putstr_fd("\033[1;31mError: empty map\n", 2),
				 1));
	else if (type == EXTENSION)
		exit((ft_putstr_fd("\033[1;31mError: file extension must be .cub\n", 2),
				1));
	else if (type == ORDER)
		exit((ft_putstr_fd("\033[1;31mError: wrong order\n", 2),
				 1));
	else if (type == PLAYER)
		exit((ft_putstr_fd("\033[1;31mError: invalid player position\n", 2),
				 1));
}
