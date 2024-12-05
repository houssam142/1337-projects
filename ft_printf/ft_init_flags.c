/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 11:08:57 by hounejja          #+#    #+#             */
/*   Updated: 2024/12/04 00:41:57 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"


void    ft_init_flags(t_flags *flags)
{
	flags->g_count = 0;
	flags->g_found = 0;
	flags->g_width = 0;
	flags->g_precision = 0;
	flags->g_point = 0;
	flags->g_justify = 0;
}
