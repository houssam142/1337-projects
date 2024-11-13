/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addfunctions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:40:52 by hounejja          #+#    #+#             */
/*   Updated: 2024/11/11 15:40:53 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(const char *str)
{
	int		count;
	size_t	i;

	count = 0;
	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
		count++;
	}
	return (count);
}

int	ft_putnbr(int nb)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	if (nb >= 0 && nb <= 9)
	{
		ft_putchar(nb + 48);
	}
	return (count);
}

int	ft_putnbr_pos(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
	{
		ft_putnbr_pos(n / 10);
		ft_putnbr_pos(n % 10);
	}
	if (n > 0 && n <= 9)
	{
		ft_putchar(n + 48);
	}
	return (count);
}

int	dectohexu(unsigned int a)
{
	int		count;
	char	*str;

	str = "0123456789ABCDEF";
	count = 0;
	if (a >= 16)
	{
		count += dectohexu(a / 16);
	}
	ft_putchar(str[a % 16]);
	count++;
	return (count);
}
