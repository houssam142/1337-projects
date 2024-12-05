/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:48:53 by hounejja          #+#    #+#             */
/*   Updated: 2024/12/04 23:00:31 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_printf(const char *w, ...)
{
	size_t	i;
	va_list	lo;
	t_flags	*flag;

	if (!w)
		return (-1);
	i = 0;
	flag = malloc(sizeof(t_flags));
	if (!flag)
	    return (-1);
	ft_init_flags(flag);
	va_start(lo, w);
	while (w[i])
	{
		if (w[i] != '%')
		{
			ft_putchar(w[i]);
			flag->g_count += 1;
		}
		else
			i = ft_check_flags_bonus(w, i + 1, lo, flag);
		i++;
	}
	va_end(lo);
	return (free(flag), flag->g_count);
}

