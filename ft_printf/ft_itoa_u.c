/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 14:06:41 by iounejja          #+#    #+#             */
/*   Updated: 2024/11/29 10:09:18 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int		len_digit(long int nb)
{
	int l;

	if (nb == 0)
		return (1);
	l = 0;
	if (nb < 0)
	{
		nb = -nb;
		l++;
	}
	while (nb > 0)
	{
		nb /= 10;
		l++;
	}
	return (l);
}

char	*ft_itoa_u(unsigned int n)
{
	long	nb;
	int		count;
	char	*str;

	nb = n;
	count = len_digit(nb);
	if (!(str = malloc(sizeof(char) * (count + 1))))
		return (NULL);
	str[count--] = '\0';
	if (nb == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		str[count--] = nb % 10 + '0';
		nb /= 10;
	}
	return (str);
}
