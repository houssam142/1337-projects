/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 09:57:31 by houssam           #+#    #+#             */
/*   Updated: 2025/08/21 07:58:51 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	check_colors_two(char *line, t_parse *data)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i])
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
			print_error(COLOR, data);
		i++;
	}
	if (!line[i])
		count++;
	if (count != 3)
	{
		ft_putstr_fd("\033[1;31mThere are not more than 3 colors\n", 2);
		struct_free(data);
		exit(1);
	}
}

void	check_colors(t_parse *data)
{
	check_colors_two(data->celing_color, data);
	check_colors_two(data->floor_color, data);
}
