/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:05:40 by hounejja          #+#    #+#             */
/*   Updated: 2025/02/23 13:54:58 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	color_zed(char *input, t_struct *new_node)
{
	(void)new_node;
	int (i), z;
	i = 0;
	z = 0;
	while (input[i] != ',' && input[i])
	{
		z = (z * 10) + (input[i] - '0');
		i++;
	}
	if (input[i] == ',')
		i++;
	return (z);
}

	// new_node->color = ft_strtol(&input[i]);
int	check_commas(char *str, t_struct *head)
{
	int	count;

	count = 0;
	while (str[count])
	{
		if (str[count] == ',')
			return (color_zed(str, head));
		count++;
	}
	return (ft_atoi(str));
}

int	increment_and_free(int count, char *str, char **map)
{
	count++;
	free(map);
	free(str);
	return (count);
}

void	draw_point(t_win *info, int x, int y, int color)
{
	char	*data_img;

	if (x >= 0 && x < info->width && y >= 0 && y < info->height)
	{
		data_img = mlx_get_data_addr(info->img_ptr, &info->bits, &info->lsize,
				&info->endian);
		((int *)data_img)[y * info->width + x] = color;
	}
}
