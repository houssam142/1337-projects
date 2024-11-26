/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:48:35 by hounejja          #+#    #+#             */
/*   Updated: 2024/11/26 14:37:01 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	checkformats(va_list p, const char *s2)
{
	int	count;

	count = 0;
	if (*s2 == 'c')
		count += ft_putchar(va_arg(p, int));
	else if (*s2 == 's')
		count += ft_putstr(va_arg(p, char *));
	else if (*s2 == 'd' || *s2 == 'i')
		count += ft_putnbr(va_arg(p, int));
	else if (*s2 == 'u')
		count += ft_putnbr_pos(va_arg(p, unsigned int));
	else if (*s2 == 'X' || *s2 == 'x')
		count += dectohexlu(va_arg(p, unsigned int), s2);
	else if (*s2 == 'p')
		count += putp(va_arg(p, void *));
	else if (*s2 == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *w, ...)
{
	int		count;
	int		i;
	va_list	lo;

	count = 0;
	i = 0;
	if (!w)
		return (-1);
	va_start(lo, w);
	while (w[i])
	{
		if (w[i] == '%')
		{
			i++;
			if (!ft_strchr("cspdiuxX%", w[i]) || w[i] == '\0')
				return (va_end(lo), -1);
			count += checkformats(lo, &w[i]);
		}
		else
			count += ft_putchar(w[i]);
		i++;
	}
	va_end(lo);
	return (count);
}
//#include <stdio.h>
//int main()
//{
//	ft_printf("%d\n", ft_printf("%d ", 348723));
//	ft_printf("%d\n", ft_printf("%d ", -65));
//	ft_printf("%d\n", ft_printf("%d ", -2147483648));
//	ft_printf("%d\n", ft_printf("%d ", 2147483647));
//}
