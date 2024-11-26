/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:06:48 by hounejja          #+#    #+#             */
/*   Updated: 2024/11/26 13:31:53 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	dectohexl(unsigned long long n)
{
	int		count;
	char	*res;

	res = "0123456789abcdef";
	count = 0;
	if (n == 0)
	{
		count += ft_putchar('0');
		return (count);
	}
	if (n >= 16)
	{
		count += dectohexl(n / 16);
	}
	count += ft_putchar(res[n % 16]);
	return (count);
}

int	putp(void *ptr)
{
	unsigned long long	a;
	int					count;

	count = 0;
	a = (unsigned long long)ptr;
	if (a == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	count += write(1, "0x", 2);
	count += dectohexl(a);
	return (count);
}

int	ft_strchr(const char *str, int search_str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (unsigned char)search_str)
		{
			break ;
		}
		i++;
	}
	if (str[i] == (unsigned char)search_str)
	{
		return (1);
	}
	return (0);
}
