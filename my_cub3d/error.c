/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 20:51:38 by hounejja          #+#    #+#             */
/*   Updated: 2025/08/18 21:17:59 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

void    print_error(enum parsing type)
{
    if (type == TEXTURE)
    {
        ft_putstr_fd("\033[1;31mThere is an error in texture syntax\n", 2);
        exit(1);
    }
    else if (type == COLOR)
    {
        ft_putstr_fd("\033[1;31mError: invalid color format\n", 2);
		exit(1);
    }
    else if (type == FILE1)
    {
        ft_putstr_fd("\033[1;31mthe file just needs six identifiers\n", 2);
		exit(1);
    }
    else if (type == MAP)
    {
        ft_putstr_fd("\033[1;31mError: Map parsing failed\n", 2);
		exit(1);
    }
    else if (type == EMPTY)
    {
        ft_putstr_fd("\033[1;31mError: empty map\n", 2);
        exit(1);
    }
}
