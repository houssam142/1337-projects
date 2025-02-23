/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:47:09 by hounejja          #+#    #+#             */
/*   Updated: 2024/11/26 17:53:23 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len_hex(unsigned int hex)
{
	int	len;

	len = 0;
	while (hex != 0)
	{
		hex = hex / 16;
		len++;
	}
	return (len);
}

static void	put_hex(unsigned int hex, char format)
{
	if (hex >= 16)
	{
		put_hex(hex / 16, format);
		put_hex(hex % 16, format);
	}
	else
	{
		if (hex <= 9)
			ft_putchar(hex + 48);
		else
		{
			if (format == 'x')
				ft_putchar(hex - 10 + 97);
			if (format == 'X')
				ft_putchar(hex - 10 + 65);
		}
	}
}

int	print_hex(unsigned int hex, char format)
{
	if (hex == 0)
		return (write(1, "0", 1));
	else
		put_hex(hex, format);
	return (len_hex(hex));
}
