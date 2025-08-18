/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssam <houssam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 09:57:31 by houssam           #+#    #+#             */
/*   Updated: 2025/08/18 17:47:11 by houssam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	check_colors_two(char *line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] == ',' && ft_isdigit(line[i + 1]))
			count++;
		else if (!ft_isdigit(line[i]))
		{
			ft_putstr_fd("\033[1;31mError: invalid color format\n", 2);
			exit(1);
		}
		i++;
	}
	if (!line[i])
		count++;
	if (count != 3)
	{
		ft_putstr_fd("\033[1;31mThere are not more than 3 colors\n", 2);
		exit(1);
	}
}

void	check_colors(t_parse *data)
{
	check_colors_two(data->celing_color);
	check_colors_two(data->floor_color);
}
