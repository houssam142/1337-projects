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
	else if (*s2 == 'x')
		count += dectohexl(va_arg(p, unsigned int));
	else if (*s2 == 'X')
		count += dectohexu(va_arg(p, unsigned int));
	else if (*s2 == 'p')
		count += putp(va_arg(p, void *));
	else if (*s2 == '%')
		ft_putchar('%');
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
		if (w[i] == '%')
		{
			i++;
			count += checkformats(lo, &w[i]);
		}
		i++;
	}
	va_end(lo);
	return (count);
}
//int	main(void)
//{
//	//ft_printf("%p %d %s %x", "dasjh ", 423, " daiuw", 244);
//	ft_printf("%X %p %x %s %d %i %u %% %c", 234, 234, 234, " dasjnw ", 432, 634, -1, 'g');
//}
