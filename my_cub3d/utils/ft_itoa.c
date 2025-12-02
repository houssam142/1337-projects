/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:38:11 by hounejja          #+#    #+#             */
/*   Updated: 2024/11/02 15:23:15 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	numlen(int nb)
{
	int	count;

	count = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		count++;
		nb *= -1;
	}
	while (nb != 0)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		i;
	long	o;

	o = n;
	i = numlen(n);
	res = ft_malloc(sizeof(char) * (i + 1));
	res[i--] = '\0';
	if (o < 0)
	{
		res[0] = '-';
		o *= -1;
	}
	if (o == 0)
		res[i] = '0';
	while (o > 0)
	{
		res[i] = o % 10 + 48;
		o /= 10;
		i--;
	}
	return (res);
}
