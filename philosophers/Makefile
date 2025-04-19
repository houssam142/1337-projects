# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/14 18:07:47 by hounejja          #+#    #+#              #
#    Updated: 2025/03/24 02:44:51 by hounejja         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = philosophers.c

NAME = philo

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3

UTILS = utils.c helpers.c ft_atoi.c

OBJ = $(SRC:.c=.o)

UTILS_OBJ = $(UTILS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(UTILS_OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(UTILS_OBJ) -o $(NAME)

.o: .c
	$(CC) $(CFLAGS) -c $< -o $@

.SECONDARY: $(OBJ) $(UTILS_OBJ)

clean:
	@rm -f $(OBJ) $(UTILS_OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all fclean clean re
