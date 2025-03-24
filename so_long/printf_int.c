/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:48:30 by hounejja          #+#    #+#             */
/*   Updated: 2025/03/18 00:49:35 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

static void	ft_putnbr(long int n)
{
	if (n == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
	}
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(-n);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		ft_putchar(n + '0');
	}
}

long	print_int(long int n)
{
	long		i;
	long int	np;

	i = 0;
	np = n;
	if (n == -2147483648)
	{
		ft_putnbr(n);
		return (11);
	}
	if (n < 0)
	{
		np = -n;
		i++;
	}
	while (np > 0)
	{
		np /= 10;
		i++;
	}
	if (n == 0)
		i = 1;
	ft_putnbr(n);
	return (i);
}
