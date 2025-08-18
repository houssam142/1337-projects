/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:03:04 by hounejja          #+#    #+#             */
/*   Updated: 2025/08/17 22:55:55 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_isspace(char c)
{
	return (c == '\t' || c == '\r' || c == '\f' || c == '\v' || c == ' '
		|| c == '\n');
}

int	ft_atoi(const char *str)
{
	int	x;
	int	sign;
	int	res;

	x = 0;
	sign = 1;
	res = 0;
	while (ft_isspace(str[x]))
		x++;
	if (str[x] == '-' || str[x] == '+')
	{
		if (str[x] == '-')
			sign *= -1;
		x++;
	}
	while (str[x] >= '0' && str[x] <= '9')
		res = (res * 10) + (str[x++] - 48);
	if (res * sign < 0)
		return ((res * sign));
}
