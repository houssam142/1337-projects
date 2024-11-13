/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_functions2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:06:48 by hounejja          #+#    #+#             */
/*   Updated: 2024/11/12 18:07:42 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	dectohexl(unsigned int n)
{
	int		count;
	char	*res;

	res = "0123456789abcdef";
	count = 0;
	if (n >= 16)
	{
		count += dectohexl(n / 16);
	}
	ft_putchar(res[n % 16]);
	return (count);
}

int	putp(void *ptr)
{
	unsigned long long	a;
	char				*res;
	int					count;

	a = (unsigned long long)ptr;
	res = "0123456789abcdef";
	count = 0;
	if (a >= 16)
	{
		count += putp((void *)(a / 16));
	}
	ft_putchar(res[a % 16]);
	count++;
	return (count);
}
