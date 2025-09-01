/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 09:57:31 by houssam           #+#    #+#             */
/*   Updated: 2025/09/01 09:54:02 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	check_colors_two(char *line)
{
	int (i), (count), (len);
	i = 0;
	count = 0;
	len = ft_strlen(line);
	while (i < len)
	{
		if (line[i] == ',')
		{
			i++;
			while (ft_isspace(line[i]))
				i++;
			if (ft_isdigit(line[i]))
				count++;
		}
		else if (!ft_isdigit(line[i]))
			print_error(COLOR);
		i++;
	}
	if (i == len)
		count++;
	if (count != 3)
		exit((ft_putstr_fd("\033[1;31mThere are not more than 3 colors\n", 2),
				free_grabage(), 1));
}

void	check_colors(t_parse *data)
{
	check_colors_two(data->celing_color);
	check_colors_two(data->floor_color);
}
