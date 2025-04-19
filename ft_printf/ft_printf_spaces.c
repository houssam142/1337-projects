/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_spaces.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 14:33:58 by iounejja          #+#    #+#             */
/*   Updated: 2024/12/01 11:20:10 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void ft_print_spaces(int l_str, char c, t_flags *flags)
{
    int spaces_to_print;

    spaces_to_print = flags->g_width - l_str;
    while (spaces_to_print > 0)
    {
        ft_putchar(c);
        spaces_to_print--;
        flags->g_count += 1;
    }
}

