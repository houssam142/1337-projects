/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:40:52 by hounejja          #+#    #+#             */
/*   Updated: 2024/11/21 20:56:31 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
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
		count += write(1, "-", 1);
		nb *= -1;
	}
	if (nb > 9)
	{
		count += ft_putnbr(nb / 10);
		count += ft_putnbr(nb % 10);
	}
	if (nb >= 0 && nb <= 9)
	{
		count += ft_putchar(nb + 48);
	}
	return (count);
}

int	ft_putnbr_pos(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
		count = ft_putnbr(n);
	if (n > 9)
	{
		count += ft_putnbr_pos(n / 10);
		count += ft_putnbr_pos(n % 10);
	}
	if (n > 0 && n <= 9)
	{
		count += ft_putchar(n + 48);
	}
	return (count);
}

int	dectohexlu(unsigned int a, const char *s1)
{
	int		count;
	char	*str;
	char	*res;

	res = "0123456789abcdef";
	str = "0123456789ABCDEF";
	count = 0;
	if (a >= 16)
	{
		count += dectohexlu((a / 16), s1);
	}
	if (*s1 == 'X')
		count += ft_putchar(str[a % 16]);
	else if (*s1 == 'x')
		count += ft_putchar(res[a %16]);
	return (count);
}
