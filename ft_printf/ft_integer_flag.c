/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integer_flag.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 14:10:42 by iounejja          #+#    #+#             */
/*   Updated: 2024/12/05 09:51:12 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	print_zero_precision(char *nbr, int nb, char c, t_flags *flags)
{
	int ln;
    int s;
    int z;

    ln = (nb != 0) ? ft_strlen(nbr) : 0;
    s = (flags->g_width > flags->g_precision && flags->g_precision > ln) ? flags->g_width - flags->g_precision : 0;
    if (flags->g_precision <= ln || (flags->g_width > 0 && flags->g_precision == 0))
        s = flags->g_width - ln;
    s = (c != 'u' && nb < 0 && flags->g_precision && flags->g_precision >= ln) ? s - 1 : s;
    z = flags->g_precision - ln;
    if (nb < 0 && c != 'u')
        z += 1;
    if (flags->g_justify == 0 || flags->g_justify == -1)
        ft_print(s, ' ');
    if (nb < 0 && c != 'u')
        ft_putchar('-');
    ft_print(z, '0');
    if (!(flags->g_precision == 0 && nb == 0))
        ft_print_string(nbr + (nb < 0 && c != 'u'), ln, 0);
    if (flags->g_justify == 1)
        ft_print(s, ' ');
    s = (s < 0) ? 0 : s;
    z = (z < 0) ? 0 : z;
    flags->g_count += (nb < 0 && c != 'u') ? ln + s + z + 1 : ln + s + z;
}

void	print_zero_width(char *nbr, int nb, char c, t_flags *flags)
{
	int l_nbr;

	l_nbr = (flags->g_width > ft_strlen(nbr)) ? flags->g_width - ft_strlen(nbr) : 0;
	if (nb < 0 && c != 'u')
		ft_putchar('-');
	ft_print(l_nbr, '0');
	if (nb < 0 && c != 'u')
		ft_print_string(nbr, ft_strlen(nbr) - 1, 1);
	else
		ft_print_string(nbr, ft_strlen(nbr), 0);
	flags->g_count += l_nbr + ft_strlen(nbr);
}

int		print_space(char *nbr, t_flags *flags)
{
	int l_nbr;

	l_nbr = ft_strlen(nbr);
	if (flags->g_justify == -1)
		ft_print_spaces(l_nbr, ' ', flags);
	ft_print_string(nbr, l_nbr, 0);
	if (flags->g_justify == 1)
		ft_print_spaces(l_nbr, ' ', flags);
	return (l_nbr);
}

void	ft_integer_flag(char c, va_list arg_list, t_flags *flags)
{
	char	*nbr;
	int		nb;

	nb = (c == 'd' || c == 'i') ? va_arg(arg_list, int) : va_arg(arg_list, unsigned int);
	nbr = (c == 'd' || c == 'i') ? ft_itoa(nb) : ft_itoa_u(nb);
	if (flags->g_found == 'a')
	{
		ft_putstr(nbr);
		flags->g_count += ft_strlen(nbr);
	}
	else if (flags->g_found == 'w')
	{
		if (flags->g_justify == 0)
			print_zero_width(nbr, nb, c, flags);
		if (flags->g_justify == -1 || flags->g_justify == 1)
			flags->g_count += print_space(nbr, flags);
	}
	else
	{
		print_zero_precision(nbr, nb, c, flags);
	}
	free(nbr);
}
