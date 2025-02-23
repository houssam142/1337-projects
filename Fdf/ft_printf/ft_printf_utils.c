/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:06:48 by hounejja          #+#    #+#             */
/*   Updated: 2024/11/26 22:44:50 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len_pointer(unsigned long long num)
{
	int	count;

	count = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num /= 16;
		count++;
	}
	return (count);
}

static void	put_addres(unsigned long long num)
{
	if (num >= 16)
	{
		put_addres(num / 16);
		put_addres(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar(num + '0');
		else
			ft_putchar(num - 10 + 'a');
	}
}

int	print_addres(void *ptr)
{
	int					len;
	unsigned long long	num;

	num = (unsigned long long)ptr;
	len = 0;
	if (num == 0)
		len += write(1, "(nil)", 5);
	else
	{
		len += write(1, "0x", 2);
		put_addres(num);
		len += len_pointer(num);
	}
	return (len);
}
