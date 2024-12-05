/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 15:38:38 by iounejja          #+#    #+#             */
/*   Updated: 2024/12/01 11:24:22 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_print_char(va_list arg_list, t_flags *flags)
{
	char	c;
	int		l_c;

	c = va_arg(arg_list, int);
	if (flags->g_found == 'a')
	{
		ft_putchar(c);
		flags->g_count += 1;
	}
	else
	{
		l_c = 1;
		if (flags->g_justify == -1)
			ft_print_spaces(l_c, ' ', flags);
		if (flags->g_justify == 0)
			ft_print_spaces(l_c, '0', flags);
		ft_putchar(c);
		if (flags->g_justify == 1)
			ft_print_spaces(l_c, ' ', flags);
		flags->g_count += 1;
	}
}
