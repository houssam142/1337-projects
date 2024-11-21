/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:48:35 by hounejja          #+#    #+#             */
/*   Updated: 2024/11/21 20:56:20 by hounejja         ###   ########.fr       */
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
	size_t	i;
	va_list	lo;

	if (!w)
		return (write(1, "-1", 2));
	count = 0;
	i = 0;
	va_start(lo, w);
	while (w[i])
	{
		if (w[i] == '\t' || ((unsigned char)(w[i]) >= 32
			&& (unsigned char)(w[i]) <= 127 && w[i] != '%'))
			count += ft_space(&w[i]);
		if (w[i] == '%')
		{
			i++;
			if (!w[i])
				return (write(1, "-1", 2));
			count += checkformats(lo, &w[i]);
		}
		i++;
	}
	va_end(lo);
	return (count);
}
//int main()
//{
//    printf("%d\n", ft_printf(" %x ", ));
//    return (0);
//}
