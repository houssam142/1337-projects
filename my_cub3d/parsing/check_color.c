/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 09:57:31 by houssam           #+#    #+#             */
/*   Updated: 2025/12/01 20:55:36 by hounejja         ###   ########.fr       */
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
		exit((ft_putstr_fd("Error\nThere are no more than 3 colors\n", 2),
				free_garbage(), 1));
}

void	check_colors(t_parse *data)
{
	check_colors_two(data->celing_color);
	check_colors_two(data->floor_color);
}

void	validate_identifiers(t_parse *data, int flag)
{
	if (data->count_no > 1 || data->count_so > 1 || data->count_ea > 1
		|| data->count_we > 1 || data->count_f > 1 || data->count_c > 1)
	{
		free_garbage();
		exit((ft_putstr_fd("Error\nDuplicate identifier found\n", 2), 1));
	}
	if (flag)
	{
		if (data->count_no != 1 || data->count_so != 1 || data->count_ea != 1
			|| data->count_we != 1 || data->count_f != 1 || data->count_c != 1)
		{
			free_garbage();
			exit((ft_putstr_fd("Error\nMissing identifier\n", 2), 1));
		}
	}
}
