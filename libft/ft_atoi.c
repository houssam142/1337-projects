/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:03:04 by hounejja          #+#    #+#             */
/*   Updated: 2024/10/22 14:19:33 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char *str)
{
	int	x;
	int	sign;
	int	res;

	x = 0;
	sign = 1;
	res = 0;
	while (str[x])
	{
		while (str[x] == 32 || str[x] == '\t')
			x++;
		if (str[x] == '-' || str[x] == '+')
		{
			if (str[x] == '-')
				sign *= -1;
			x++;
		}
		if (str[x] == '+' || str[x] == '-')
			return (0);
		if (str[x] >= '0' && str[x] <= '9')
			res = (res * 10) + (str[x] - 48);
		x++;
	}
	return (res * sign);
}
