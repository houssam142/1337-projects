/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_functions3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:03:22 by hounejja          #+#    #+#             */
/*   Updated: 2024/11/21 20:43:49 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_space(const char *s)
{
	int	count;

	count = 0;
	if (*s == '\t' || ((unsigned char)(*s) >= 32
		&& (unsigned char)(*s) <= 127 && *s != '%'))
	{
		count += ft_putchar(*s);
		s++;
	}	
	return (count);
}
