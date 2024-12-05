# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/11 15:22:47 by hounejja          #+#    #+#              #
#    Updated: 2024/12/03 08:47:44 by hounejja         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c ft_printf_utils.c ft_printf_utils_2.c printf_hex.c printf_int.c

BONUS_SRCS = ft_printf_bonus.c ft_check_flags_bonus.c \
			ft_flags.c \
			ft_get_digit.c \
			ft_hex.c \
			ft_hex_flags.c \
			ft_integer_flag.c \
			ft_is_flag.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_itoa_u.c \
			ft_len_hex.c \
			ft_print.c \
			ft_print_char.c \
			ft_print_string.c \
			ft_printf_spaces.c \
			ft_putchar.c \
			ft_putnbr.c \
			ft_putstr.c \
			ft_string_flag.c \
			ft_strlen.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_init_flags.c \
			main.c \


OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

CC = cc

NAME = libftprintf.a

LIBC = ar rc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	@$(LIBC) $(NAME) $(OBJS)

bonus: $(BONUS_SRCS) $(BONUS_OBJS)
		$(LIBC) $(NAME) $(BONUS_OBJS)
		touch bonus
.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
		@rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
		@rm -f $(NAME)

re: fclean all

.PHONY: all fclean re clean

