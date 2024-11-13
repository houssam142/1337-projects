/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:23:09 by hounejja          #+#    #+#             */
/*   Updated: 2024/11/11 15:34:26 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	handlesc(const char *str, const char *s1)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	if (*str == 'c')
	{
		count += ft_putchar(s1[i]);
	}
	else if (*str == 's')
	{
		count += ft_putstr(s1);
	}
	return (count);
}

int	handlediu(int n, const char *str1)
{
	int	count;

	count = 0;
	if (*str1 == 'u')
	{
		count += ft_putnbr_pos(n);
	}
	else
	{
		count += ft_putnbr(n);
	}
	return (count);
}

int	handlepxx(const char *str1, va_list ken)
{
	int		count;
	void	*ptr;

	ptr = va_arg(ken, void *);
	count = 0;
	if (*str1 == 'x')
		count += dectohexl(va_arg(ken, unsigned int));
	else if (*str1 == 'X')
		count += dectohexu(va_arg(ken, unsigned int));
	else if (*str1 == 'p')
	{
		if (ptr == NULL)
			return (write(1, "(nil)", 5));
		else
		{
			write(1, "0x", 2);
			count += putp(ptr);
		}
	}
	return (count);
}
#include <stdio.h>

int	ft_printf(const char *w, ...)
{
	int		count;
	size_t	i;
	va_list	lo;

	if (!w)
		return (write(1, "-1", 2));
	count = 0;
	i = 0;
	va_start(lo, w);
	while (w[i])
	{
		if (w[i] == '%')
		{
			i++;
			if (w[i] == 's' || w[i] == 'c')
				count += handlesc(&w[i], va_arg(lo, char *));
			else if (w[i] == 'd' || w[i] == 'i' || w[i] == 'u')
				count += handlediu(va_arg(lo, int), &w[i]);
			else if (w[i] == 'p' || w[i] == 'x' || w[i] == 'X')
				count += handlepxx(&w[i], lo);
			else if (w[i] == '%')
				ft_putchar('%');
		}
		i++;
	}
	return (va_end(lo), count);
}
int	main(void)
{
	ft_printf("%p %s %d %u", "dasjh ", " kjsdagshk ", 43, -1);
	printf("\n%p", "kjsdagshk");
}
