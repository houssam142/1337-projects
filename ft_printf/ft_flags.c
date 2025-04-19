/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 13:46:54 by iounejja          #+#    #+#             */
/*   Updated: 2024/12/04 21:49:40 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void ft_print_perc(char c, t_flags *flags)
{
    int l_c;

    l_c = 1;

    if (flags->g_found == 'a')
    {
        ft_putchar(c);
        flags->g_count += 1;
    }
    else
    {
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

void ft_flags(char c, va_list arg_list, t_flags *flags)
{
    if  (c == 's')
        ft_string_flag(arg_list, flags);
    else if (c == 'd' || c == 'i' || c == 'u')
        ft_integer_flag(c, arg_list, flags);
    else if (c == 'c')
        ft_print_char(arg_list, flags);
    else if (c == 'p' || c == 'x' || c == 'X')
        ft_hex_flags(c, arg_list, flags);
    else if (c == '%')
        ft_print_perc('%', flags);
}

