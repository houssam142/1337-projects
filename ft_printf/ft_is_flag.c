/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 15:59:52 by iounejja          #+#    #+#             */
/*   Updated: 2024/12/03 11:25:52 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int		ft_is_flag(char c, t_flags *flags)
{
	if (c == 'c' || c == 's' || c == 'd' || c == 'i' ||
			c == 'u' || c == 'p' || c == 'x' || c == 'X' || c == '%')
		return (1);
	else
	{
		if (flags->g_width - 1 > 0)
			ft_print(flags->g_width - 1, c);
		if (flags->g_width == 0)
		{
			flags ->g_count += flags->g_width;
		}
		flags->g_count += flags->g_width - 1;
		return (0);
	}
}
