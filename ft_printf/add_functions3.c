/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_functions3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:03:22 by hounejja          #+#    #+#             */
/*   Updated: 2024/11/15 22:51:04 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_space(const char *s)
{
	int	count;

	count = 0;
	if (*s == 32)
	{
		count += ft_putchar(' ');
		s++;
	}
	return (count);
}
int	checksigns(const char *a)
{
	int	count;

	count = 0;
	if (*a == '+')
	{
		count += ft_putchar('+');
		a++;
	}
	else if (*a == '-')
	{
		count += ft_putchar('-');
		a++;
	}
	return (count);
}

