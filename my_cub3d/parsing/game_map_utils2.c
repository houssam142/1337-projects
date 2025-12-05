/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_map_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 11:29:56 by hounejja          #+#    #+#             */
/*   Updated: 2025/12/05 11:29:57 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	check_wall_boundaries(char **line, int i, int j)
{
	if (i > 0 && j < ft_strlen(line[i - 1])
		&& is_map_cell(line[i - 1][j], 0))
		print_error(WALL);
	if (i + 1 > 0 && j < ft_strlen(line[i + 1])
		&& is_map_cell(line[i + 1][j], 0))
		print_error(WALL);
	if (j > 0 && is_map_cell(line[i][j - 1], 0))
		print_error(WALL);
	if (j + 1 && is_map_cell(line[i][j + 1], 0))
		print_error(WALL);
}
