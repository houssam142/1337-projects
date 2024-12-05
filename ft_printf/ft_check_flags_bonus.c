/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 13:46:45 by iounejja          #+#    #+#             */
/*   Updated: 2024/12/03 11:19:31 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void get_width(const char *format, int *index, t_flags *flags)
{
    flags->g_found = 'w';
    while (format[*index] == '-')
        (*index)++;
    flags->g_width = ft_get_digit(format, *index);
    while (format[*index] >= '0' && format[*index] <= '9')
        (*index)++;
    (*index)--;
}

void get_precision(const char *format, int *index, va_list arg_list, t_flags *flags)
{
    flags->g_found = 'p';
    if (format[*index] == '*')
        flags->g_precision = va_arg(arg_list, int);
    else
        flags->g_precision = ft_get_digit(format, *index);
    while (ft_isdigit(format[*index]) || format[*index] == '*')
        (*index)++;
    (*index)--;
}

int check_format(const char *format, int index, va_list arg_list, t_flags *flags)
{
    while (ft_isprint(format[index]) && !(ft_isalpha(format[index]))
        && format[index] != '%')
    {
        if (format[index] == '0' && (ft_isdigit(format[index + 1])
                || format[index + 1] == '*') && format[index - 1] != '-')
            flags->g_justify = 0;
        if (format[index] == '.')
        {
            flags->g_found = 'p';
            flags->g_point = 1;
        }
        if ((ft_isdigit(format[index]) || format[index] == '-') && flags->g_point == 0)
            get_width(format, &index, flags);
        if (format[index] == '*' && flags->g_point == 0)
        {
            flags->g_found = 'w';
            flags->g_width = va_arg(arg_list, int);
        }
        if ((format[index] == '*' || ft_isdigit(format[index])
                || format[index] == '-') && flags->g_point == 1)
            get_precision(format, &index, arg_list, flags);
        index++;
    }
    return index;
}

int ft_check_flags_bonus(const char *format, int index, va_list arg_list, t_flags *flags)
{
    flags->g_justify = -1;
    flags->g_point = 0;
    flags->g_width = 0;
    flags->g_precision = 0;
    flags->g_found = 'a';
    
    if (format[index] == '-')
    {
        flags->g_justify = 1;
        index++;
    }
    index = check_format(format, index, arg_list, flags);  
    if (!(ft_is_flag(format[index], flags)))
        return (index - 1);
    if (flags->g_width < 0)
    {
        flags->g_width = -flags->g_width;
        flags->g_justify = 1;
    }    
    if (flags->g_precision < 0)
    {
        flags->g_found = 'w';
        flags->g_precision = 0;
    }   
    ft_flags(format[index], arg_list, flags);
    return (index);
}

