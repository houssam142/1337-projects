/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fdf_m.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 09:05:34 by hounejja          #+#    #+#             */
/*   Updated: 2025/02/21 18:26:32 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*check_the_fd(char *file_name)
{
	int (fd);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		exit(1);
	return (file_name);
}

static int	check_the_extension(char *name_of_map)
{
	int (len);
	len = ft_strlen(name_of_map);
	if (len < 4)
	{
		ft_printf("Map is very short\n");
		return (0);
	}
	if (ft_strncmp(name_of_map + len - 4, ".fdf", 4) == 0)
	{
		ft_printf("Valid file\n");
		return (0);
	}
	else
	{
		ft_printf("Not a valid file\n");
		exit(1);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_struct	*head;
	t_win		info_map;
	int			flag;

	head = NULL;
	info_map.width = WIN_W;
	info_map.height = WIN_H;
	if (ac != 2)
		return (ft_printf("NOT ENOUGH OR TOO MUCH\n"));
	flag = (check_the_extension(av[1]) + check_the_map(av[1], &head));
	if (flag != 0)
		exit(1);
	info_map.map_name = av[1];
	check_and_count(head, &info_map);
	new_windows(&info_map, &head);
	return (0);
}
