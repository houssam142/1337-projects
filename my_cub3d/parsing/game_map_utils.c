/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 20:24:00 by hounejja          #+#    #+#             */
/*   Updated: 2025/12/05 19:32:02 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	is_map_cell(char c, int flag)
{
	if (flag)
		return (c == '0' || c == '1' || c == 'N' || c == 'S'
			|| c == 'E' || c == 'W');
	else
		return (c == '0' || c == 'N' || c == 'S'
			|| c == 'E' || c == 'W');
}

int	is_allowed_char(char c, char filler)
{
	return (c == filler || c == '\n' || is_map_cell(c, 1));
}

void	check_wall_boundaries(char **map, int i, int j)
{
	if (i > 0 && j < ft_strlen(map[i - 1])
		&& is_map_cell(map[i - 1][j], 0))
		print_error(WALL);
	if (i + 1 < arr_len(map) && j < ft_strlen(map[i + 1])
		&& is_map_cell(map[i + 1][j], 0))
		print_error(WALL);
	if (j - 1 > 0 && is_map_cell(map[i][j - 1], 0))
		print_error(WALL);
	if (j + 1 < ft_strlen(map[i]) && is_map_cell(map[i][j + 1], 0))
		print_error(WALL);
}

void	ensure_line_closed(char *line, char filler)
{
	int	idx;

	idx = (int)ft_strlen(line) - 1;
	while (idx >= 0 && (line[idx] == '\n' || line[idx] == filler))
		idx--;
	if (idx >= 0 && is_map_cell(line[idx], 0))
		print_error(WALL);
}
