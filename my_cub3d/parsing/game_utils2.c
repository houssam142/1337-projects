/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 20:02:27 by hounejja          #+#    #+#             */
/*   Updated: 2025/12/04 20:38:16 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	find_down_map_cell(char *line, int idx, char filler)
{
	while (idx >= 0)
	{
		if (line[idx] == '\n')
			return ('\0');
		if (line[idx] != filler && is_map_cell(line[idx], 1))
			return (line[idx]);
		idx--;
	}
	return ('\0');
}

char	find_top_map_cell(char *line, int i, int idx, char filler)
{
	while (i > 0 && idx >= 0)
	{
		if (line[idx] == '\n')
			return ('\0');
		if (line[idx] != filler && is_map_cell(line[idx], 1))
			return (line[idx]);
		idx--;
	}
	return ('\0');
}
