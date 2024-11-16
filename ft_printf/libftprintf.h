/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:21:47 by hounejja          #+#    #+#             */
/*   Updated: 2024/11/15 22:45:57 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int	ft_printf(const char *w, ...);
int	ft_putchar(char c);
int	ft_putnbr(int nb);
int	ft_putstr(const char *str);
int	ft_putnbr_pos(unsigned int n);
int	dectohexu(unsigned long long a);
int	dectohexl(unsigned long long n);
int	putp(void *ptr);
int	ft_space(const char *s);
int	checksigns(const char *a);

#endif
