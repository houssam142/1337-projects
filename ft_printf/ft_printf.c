/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:48:35 by hounejja          #+#    #+#             */
/*   Updated: 2024/11/16 03:38:33 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	checkformats(va_list p, const char *s2)
{
	int	count;

	count = 0;
	if (*s2 == 32 && *s2 != 'p')
		ft_space(s2++);
	if (*s2 == 'c')
		count += ft_putchar(va_arg(p, int));
	else if (*s2 == 's')
		count += ft_putstr(va_arg(p, char *));
	else if (*s2 == 'd' || *s2 == 'i')
		count += ft_putnbr(va_arg(p, int));
	else if (*s2 == 'u')
		count += ft_putnbr_pos(va_arg(p, unsigned int));
	else if (*s2 == 'x')
		count += dectohexl(va_arg(p, unsigned int));
	else if (*s2 == 'X')
		count += dectohexu(va_arg(p, unsigned int));
	else if (*s2 == 'p')
		count += putp(va_arg(p, void *));
	else if (*s2 == '%')
		count += ft_putchar('%');
	return (count);
}

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
		if (w[i] == 32 && w[i + 1] != 'p')
			count += ft_space(&w[i]);
		if (w[i] == '%' || w[i + 1] == 'd' || w[i + 1] == 's' || w[i + 1] == 'c'
		|| w[i + 1] == 'x' || w[i + 1] == 'X' || w[i + 1] == 'u' || w[i + 1] == 'i' || w[i] == 'p')
		{
			count += checkformats(lo, &w[i + 1]);
		}
		if (w[i] == '+' || w[i] == '-')
			count += checksigns(&w[i]);
		i++;
	}
	va_end(lo);
	return (count);
}
int	main(void)
{
	int a;

	a = 421;
	int b = 821;
	ft_printf(NULL, &b, "hello ", &a, 'f', 432, 432, -1, 421);
}
