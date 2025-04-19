/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 20:59:18 by hounejja          #+#    #+#             */
/*   Updated: 2024/11/29 10:38:17 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *w, ...);
int	ft_putchar(char c);
int	ft_putstr(const char *str);
int	print_hex(unsigned int hex, char format);
int	print_unsigned_int(unsigned int n);
int	print_addres(void *ptr);
int	print_int(int n);

#endif
