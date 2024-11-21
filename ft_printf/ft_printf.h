/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 20:59:18 by hounejja          #+#    #+#             */
/*   Updated: 2024/11/21 20:55:19 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int	ft_printf(const char *w, ...);
int	ft_putchar(char c);
int	ft_putnbr(int nb);
int	ft_putstr(const char *str);
int	ft_putnbr_pos(unsigned int n);
int	dectohexlu(unsigned int a, const char *s1);
int	dectohexl(unsigned long long n);
int	putp(void *ptr);
int	ft_space(const char *s);

#endif
