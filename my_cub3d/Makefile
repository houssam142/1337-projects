# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/02 17:59:55 by hounejja          #+#    #+#              #
#    Updated: 2025/09/02 20:09:25 by hounejja         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

BONUS = 0

CC = cc

CFLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -L$(MINILIBX_DIR) -lmlx -lXext -lX11 -lm

SRC = main.c

OTHER_SRCS = parsing/parse_file.c utils/ft_strncmp.c utils/ft_putstr_fd.c \
	     parsing/map_game.c utils/get_next_line_utils.c utils/get_next_line.c \
		 utils/ft_atoi.c utils/ft_split.c utils/alloc.c parsing/check_color.c \
		 utils/ft_isdigit.c parsing/parse_file_utils.c error.c parsing/check_map.c \
		 utils/ft_strtrim.c mandatory/game_start.c parsing/game_map.c mandatory/player_position.c \
		 mandatory/vector.c mandatory/draw.c mandatory/raycasting.c mandatory/init_player_pos_and_ore.c \
		 mandatory/color.c mandatory/dda.c mandatory/raycasting_utils.c \
		 movement/movement.c movement/rotate.c mandatory/render.c mandatory/textures.c mandatory/init_window.c \
		 cleaning/clean_all.c utils/ft_bzero.c mandatory/mouse_mo.c

OTHER_OBJS = $(OTHER_SRCS:.c=.o)

MINILIBX_DIR = /usr/include/minilibx-linux

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(OTHER_OBJS)
	@clear
	$(CC) $(CFLAGS) -DBONUS=$(BONUS) $(OBJ) $(OTHER_OBJS) $(MLX_FLAGS) -o $(NAME)
	@clear

bonus:
	@$(MAKE) all BONUS=1

CFLAGS += -DBONUS=$(BONUS)

clean:
	rm -rf $(OBJ) $(OTHER_OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean bonus re

