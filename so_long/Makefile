# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/01 17:57:25 by hounejja          #+#    #+#              #
#    Updated: 2025/03/24 03:40:25 by hounejja         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = so_long

NAME_BONUS = so_long_bonus


MLX_FLAGS = -L/usr/include/minilibx-linux/ -lmlx -lXext -lX11


UTILS = parse.c utils.c ft_strncmp.c get_next_line.c get_next_line_utils.c ft_split.c init.c rendering.c handling.c \
		check_map_utils.c map_utils.c errors.c movement.c validate.c print.c printf_int.c

UTILS_BONUS = bonus/parse_bonus.c bonus/errors_bonus.c bonus//ft_strncmp_bonus.c bonus/get_next_line.c \
				bonus/rendering_bonus.c bonus/movement_bonus.c bonus/init_bonus.c bonus/utils_bonus.c \
				bonus/validate_bonus.c bonus/ft_split_bonus.c bonus/check_map_utils_bonus.c \
				bonus/so_long_bonus.c bonus/get_next_line_utils.c bonus/map_utils_bonus.c bonus/handling_bonus.c \
				bonus/ft_itoa.c bonus/ft_printf_bonus.c bonus/printf_int_bonus.c bonus/animation_bonus.c
OBJ = $(SRC:.c=.o)

UTILS_OBJ = $(UTILS:.c=.o)

UTILS_BONUS_OBJ = $(UTILS_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(UTILS_OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(UTILS_OBJ) $(MLX_FLAGS) -o $(NAME)

bonus: $(UTILS_BONUS_OBJ)
	@$(CC) $(CFLAGS) $(UTILS_BONUS_OBJ) $(MLX_FLAGS) -o $(NAME_BONUS)

.o: .c
	$(CC) $(CFLAGS) -c $< -o $@

.SECONDARY: $(OBJ) $(UTILS_OBJ)

clean:
	rm -rf $(OBJ) $(UTILS_BONUS_OBJ) $(UTILS_OBJ)

fclean: clean
	rm -rf $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all re fclean clean
