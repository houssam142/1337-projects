# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/11 15:22:47 by hounejja          #+#    #+#              #
#    Updated: 2024/11/15 15:19:42 by hounejja         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c add_functions.c add_functions2.c add_functions3.c

OBJS = $(SRCS:.c=.o)

CC = cc

NAME = libftprintf.a

LIBC = ar rc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(LIBC) $(NAME) $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
		rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all fclean re clean

