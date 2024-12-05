/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 19:02:14 by iounejja          #+#    #+#             */
/*   Updated: 2024/12/04 18:02:49 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*covert(char *str, char c, unsigned long p, int *index)
{
	unsigned long	nb;

	while (p != 0)
	{
		nb = p % 16;
		if (nb < 10)
			str[*index] = (c == 'X') ? ft_toupper(nb + '0') : ft_tolower(nb + '0');
		else
			str[*index] = (c == 'X') ? ft_toupper(nb - 10 + 'A') : ft_tolower(nb - 10 + 'A');
		*index += 1;
		p /= 16;
	}
	return (str);
}

void	ft_hex(unsigned long p, char c)
{
	int		i;
	int		len;
	char	*str;

	if (c == 'p' && p == 0)
	{
		ft_putstr("(nil)");
		return ;
	}
	else if (p == 0)
	{
		ft_putchar('0');
        return ;
	}
	len = ft_len_hex(p);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return ;
	i = 0;
	str = covert(str, c, p, &i);
	str[i] = '\0';
	while (--i >= 0)
		write(1, &str[i], 1);
	free(str);
}
