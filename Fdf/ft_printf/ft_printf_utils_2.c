/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:40:52 by hounejja          #+#    #+#             */
/*   Updated: 2024/11/26 17:52:50 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(const char *str)
{
	int	count;

	count = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[count])
	{
		write(1, &str[count], 1);
		count++;
	}
	return (count);
}

static void	ft_putnbru(unsigned int n)
{
	if (n > 9)
	{
		ft_putnbru(n / 10);
		ft_putnbru(n % 10);
	}
	else
	{
		ft_putchar(n + '0');
	}
}

int	print_unsigned_int(unsigned int n)
{
	int				i;
	unsigned int	np;

	i = 0;
	np = n;
	while (np > 0)
	{
		np /= 10;
		i++;
	}
	if (n == 0)
		i = 1;
	ft_putnbru(n);
	return (i);
}
