# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/01 17:57:25 by hounejja          #+#    #+#              #
#    Updated: 2025/03/09 15:45:03 by hounejja         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = so_long

LIBFTPRINTF = ft_printf/libftprintf.a

MLX_FLAGS = -L/usr/include/minilibx-linux/ -lmlx -lXext -lX11


UTILS = parse.c utils.c ft_strncmp.c get_next_line.c get_next_line_utils.c ft_split.c ft_atoi.c init.c rendering.c handling.c \
		check_map_utils.c map_utils.c errors.c movement.c validate.c

OBJ = $(SRC:.c=.o)

UTILS_OBJ = $(UTILS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(UTILS_OBJ)
	@make -s -C ft_printf
	@$(CC) $(CFLAGS) $(OBJ) $(UTILS_OBJ) $(LIBFTPRINTF) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf *.o
	@make -s -C ft_printf clean

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all re fclean clean