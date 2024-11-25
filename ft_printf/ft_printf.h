/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 20:59:18 by hounejja          #+#    #+#             */
/*   Updated: 2024/11/24 17:59:55 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *w, ...);
int		ft_putchar(char c);
int		ft_putnbr(int nb);
int		ft_putstr(const char *str);
int		ft_putnbr_pos(unsigned int n);
int		dectohexlu(unsigned int a, const char *s1);
int		dectohexl(unsigned long long n);
int		putp(void *ptr);
int		ft_space(const char *s);
char	*ft_strchr(const char *str, int search_str);

#endif
