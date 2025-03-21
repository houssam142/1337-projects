/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:48:35 by hounejja          #+#    #+#             */
/*   Updated: 2025/03/18 00:48:51 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	checkformats(va_list p, const char s2)
{
	int	count;

	count = 0;
	if (s2 == 'd' || s2 == 'i')
		count += print_int(va_arg(p, int));
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
			if (w[i] == '\0')
				return (va_end(lo), -1);
			count += checkformats(lo, w[i]);
		}
		else
			count += ft_putchar(w[i]);
		i++;
	}
	va_end(lo);
	return (count);
}
