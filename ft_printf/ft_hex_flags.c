/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 14:32:53 by iounejja          #+#    #+#             */
/*   Updated: 2024/12/04 18:14:40 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	w_p_not_found(unsigned long nb, char c, t_flags *flags)
{
	int l_nb;

	l_nb = 0;
	if (c == 'p')
	{
		if (nb == 0)
		{
			ft_putstr("(nil)");
			flags->g_count += 5;
			return ;
		}
		ft_putstr("0x");
		flags->g_count += 2;
	}
	ft_hex(nb, c);
	l_nb = (c == 'p') ? ft_len_hex(nb) + 2 : ft_len_hex(nb);
	flags->g_count += l_nb;
}

void	found_precision_hex(unsigned long nb, int space, int zero, char c, t_flags *flags)
{
	if (c == 'p' && nb == 0)
    {
        if (flags->g_justify == -1)
            ft_print(space, ' ');
        ft_putstr("(nil)");
        if (flags->g_justify == 1)
            ft_print(space, ' ');
        flags->g_count += space + 5;
        return;
    }
    if (flags->g_justify == -1 || flags->g_justify == 0)
        ft_print(space, ' ');
    if (c == 'p' && nb != 0)
    {
        ft_putstr("0x");
        flags->g_count += 2;
    }
    if (flags->g_justify == 0 || flags->g_precision > 0)
        ft_print(zero, '0');
    if (nb != 0)
        ft_hex(nb, c);
    if (flags->g_justify == 1)
        ft_print(space, ' ');
}

void	found_width_hex(unsigned long nb, int space, char c, t_flags *flags)
{
	int l_nb;

    if (c == 'p' && nb == 0)
    {
        space = (flags->g_width > 5) ? flags->g_width - 5 : 0;
        if (flags->g_justify == -1)
            ft_print(space, ' ');
        ft_putstr("(nil)");
        if (flags->g_justify == 1)
            ft_print(space, ' ');
        flags->g_count += space + 5;
        return;
    }
    l_nb = ft_len_hex(nb);
    space = (flags->g_width > l_nb) ? flags->g_width - l_nb : 0;
    space = (c == 'p') ? space - 2 : space;
    if (flags->g_justify == -1)
        ft_print(space, ' ');
    if (c == 'p' && nb != 0)
    {
        ft_putstr("0x");
        flags->g_count += 2;
    }
    if (flags->g_justify == 0)
        ft_print(space, '0');
    ft_hex(nb, c);
    if (flags->g_justify == 1)
        ft_print(space, ' ');
    space = (space < 0) ? 0 : space;
    flags->g_count += l_nb + space;
}

void	ft_hex_flags(char c, va_list arg_list, t_flags *flags)
{
	unsigned long	nb;
	int				l_nb;
	int				space;
	int				zero;

	space = 0;
	zero = 0;
	if (c == 'p')
		nb = va_arg(arg_list, unsigned long);
	else
		nb = va_arg(arg_list, unsigned int);
	if (flags->g_found == 'a')
		w_p_not_found(nb, c, flags);
	else if (flags->g_found == 'w')
		found_width_hex(nb, space, c, flags);
	else
	{
		l_nb = (nb > 0) ? ft_len_hex(nb) : 0;
		zero = (flags->g_precision > 0 && flags->g_precision > l_nb) ? flags->g_precision - l_nb : 0;
		space = (c == 'p') ? 2 : 0;
		space = (flags->g_width > l_nb + zero + space) ?
		flags->g_width - (l_nb + zero + space) : 0;
		found_precision_hex(nb, space, zero, c, flags);
		flags->g_count += l_nb + space + zero;
	}
}

