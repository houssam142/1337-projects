# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hounejja <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/29 11:10:55 by hounejja          #+#    #+#              #
#    Updated: 2024/11/10 22:51:05 by hounejja         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	ft_atoi.c ft_itoa.c ft_memmove.c ft_striteri.c \
	ft_strtrim.c ft_memset.c ft_strjoin.c ft_substr.c \
	ft_bzero.c ft_putchar_fd.c ft_strlcat.c ft_tolower.c \
	ft_calloc.c ft_putendl_fd.c ft_strlcpy.c ft_toupper.c \
	ft_isalnum.c ft_putnbr_fd.c ft_strlen.c \
	ft_isalpha.c ft_putstr_fd.c ft_strmapi.c \
	ft_isascii.c ft_memchr.c ft_split.c ft_strncmp.c \
	ft_isdigit.c ft_memcmp.c ft_strchr.c ft_strnstr.c \
	ft_isprint.c ft_memcpy.c ft_strdup.c ft_strrchr.c \

BONUS_SRCS = ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstnew_bonus.c \
	ft_lstsize_bonus.c ft_lstlast_bonus.c  ft_lstdelone_bonus.c \
	ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c \

OBJS = $(SRCS:.c=.o)

CC = cc

BONUS_OBJS = $(BONUS_SRCS:.c=.o)
	
NAME = libft.a

LIBC = ar rc

CFLAGS = -Wall -Wextra -Werror


all: $(NAME)

$(NAME): $(OBJS)
	$(LIBC) $(NAME) $(OBJS)
	

bonus: $(BONUS_SRCS) $(BONUS_OBJS)
	$(LIBC) $(NAME) $(BONUS_OBJS)
	touch bonus

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	touch clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean re
