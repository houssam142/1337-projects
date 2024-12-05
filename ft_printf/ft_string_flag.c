/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 12:48:07 by iounejja          #+#    #+#             */
/*   Updated: 2024/12/01 23:17:18 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	found_precision_s(char *str, int l_str, t_flags *flags)
{
	l_str = (flags->g_precision >= ft_strlen(str)) ? ft_strlen(str) : flags->g_precision;
	if (flags->g_justify == -1)
		ft_print_spaces(l_str, ' ', flags);
	if (flags->g_justify == 0)
		ft_print_spaces(l_str, '0', flags);
	ft_print_string(str, l_str, 0);
	if (flags->g_justify == 1)
		ft_print_spaces(l_str, ' ', flags);
	flags->g_count += l_str;
}

void	found_width_s(char *str, int l_str, t_flags *flags)
{
	l_str = ft_strlen(str);

	if (flags->g_justify == -1)
		ft_print_spaces(l_str, ' ', flags);
	if (flags->g_justify == 0)
		ft_print_spaces(l_str, '0', flags);
	ft_print_string(str, l_str, 0);
	if (flags->g_justify == 1)
		ft_print_spaces(l_str, ' ', flags);
	flags->g_count += l_str;
}

void	ft_string_flag(va_list arg_list, t_flags *flags)
{
	char	*str;
	int		l_str;

	str = va_arg(arg_list, char *);
	l_str = ft_strlen(str);
	if (!str)
		str = "(null)";
	if (flags->g_found == 'a')
	{
		ft_putstr(str);
		flags->g_count += ft_strlen(str);
	}
	else if (flags->g_found == 'w')
		found_width_s(str, l_str, flags);
	else
		found_precision_s(str, l_str, flags);
}

