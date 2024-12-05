/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_digit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 15:39:44 by iounejja          #+#    #+#             */
/*   Updated: 2024/12/03 08:45:29 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_get_digit(const char *str, int i)
{
	int		n;
	long	nb;
	long	val;

	n = 1;
	nb = 0;
	if (str[i] == '-')
		n = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		val = nb;
		nb = ((nb * 10) + (str[i++] - 48) * n);
		if (n == 1 && val > nb)
			return (-1);
		if (n == -1 && val < nb)
			return (0);
	}
	return (nb);
}
