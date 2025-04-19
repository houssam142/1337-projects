/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:49:12 by hounejja          #+#    #+#             */
/*   Updated: 2024/12/03 23:51:39 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct
{
	int		g_count;
	char	g_found;
	int		g_justify;
	int		g_point;
	int		g_width;
	int		g_plus;
	int		g_precision;
}t_flags;

int		ft_printf(const char *w, ...);
int		ft_isprint(int c);
int		check_format(const char *format, int index, va_list arg_list, t_flags *flags);
int		ft_isdigit(int c);
int		ft_isalpha(int c);
int		ft_len_hex(unsigned long nb);
int		ft_check_flags_bonus(const char *format, int index, va_list arg_list, t_flags *flags);
int		ft_get_digit(const char *str, int i);
int		ft_strlen(char const *s);
void	ft_print_spaces(int l_str, char c, t_flags *flags);
int		ft_tolower(int c);
int		ft_is_flag(char c, t_flags *flags);
void	ft_print_char(va_list arg_list, t_flags *flags);
void	ft_flags(char c, va_list arg_list, t_flags *flags);
void	ft_print(int l_nbr, char c);
int		ft_toupper(int c);
void	ft_string_flag(va_list arg_list, t_flags *flags);
void	ft_putnbr(int nb);
void	ft_hex_flags(char c, va_list arg_list, t_flags *flags);
void	ft_hex(unsigned long p, char c);
void	ft_integer_flag(char c, va_list arg_list, t_flags *flags);
void	ft_putstr(char *str);
void	ft_print_string(char *str, int l_str, int index);
void	ft_putchar(char c);
void    ft_init_flags(t_flags *flags);
char	*ft_itoa_u(unsigned int n);
char	*ft_itoa(int n);

#endif
