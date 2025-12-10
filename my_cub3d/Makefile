# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/02 17:59:55 by hounejja          #+#    #+#              #
#    Updated: 2025/12/09 07:37:01 by hounejja         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

NAME_1 = cub3D_bonus

CC = cc

HEADERS = include/cub3d.h include/get_next_line.h

CFLAGS = -Wall -Wextra -Werror

INC = -I include/

MLX_FLAGS = -L$(MINILIBX_DIR) -lmlx -lXext -lX11 -lm

OTHER_SRCS = main.c parsing/parse_file.c utils/ft_strncmp.c utils/ft_putstr_fd.c \
	     parsing/map_game.c utils/get_next_line_utils.c utils/get_next_line.c \
		 utils/ft_atoi.c utils/ft_split.c utils/alloc.c parsing/check_color.c \
		 utils/ft_isdigit.c parsing/parse_file_utils.c error.c parsing/check_map.c \
		 utils/ft_strtrim.c mandatory/game_start.c parsing/game_map.c mandatory/player_position.c \
		mandatory/draw.c mandatory/raycasting.c \
		 mandatory/color.c mandatory/dda.c mandatory/raycasting_utils.c \
		 movement/movement.c movement/rotate.c mandatory/render.c mandatory/textures.c mandatory/init_window.c \
		 cleaning/clean_all.c utils/ft_bzero.c utils/ft_itoa.c movement/movement_utils.c parsing/game_map_utils.c \

OTHER_SRCS_B = main.c parsing/parse_file.c utils/ft_strncmp.c utils/ft_putstr_fd.c \
	     parsing/map_game.c utils/get_next_line_utils.c utils/get_next_line.c \
		 utils/ft_atoi.c utils/ft_split.c utils/alloc.c parsing/check_color.c \
		 utils/ft_isdigit.c parsing/parse_file_utils.c error.c parsing/check_map.c \
		 utils/ft_strtrim.c parsing/game_map.c mandatory/player_position.c \
		 mandatory/draw.c mandatory/raycasting.c \
		 mandatory/color.c mandatory/dda.c mandatory/raycasting_utils.c \
		 movement/movement.c movement/rotate.c mandatory/render.c mandatory/textures.c mandatory/init_window.c \
		 cleaning/clean_all.c utils/ft_bzero.c bonus/draw_minimap_bonus.c \
		 utils/ft_itoa.c bonus/game_start_bonus.c bonus/mouse_mo_bonus.c movement/movement_utils.c \
		 parsing/game_map_utils.c

OTHER_OBJS = $(OTHER_SRCS:.c=.o)

OTHER_OBJS_B = $(OTHER_SRCS_B:.c=.o)

MINILIBX_DIR = ./minilibx-linux


all: $(NAME)

$(NAME): $(OTHER_OBJS)
	@make -C minilibx-linux
	$(CC) $(CFLAGS) $(INC) $(OBJ) $(OTHER_OBJS) $(MLX_FLAGS) -o $(NAME)

$(NAME_1): $(OTHER_OBJS_B)
	@make -C minilibx-linux
	$(CC) $(CFLAGS) $(INC) $(OBJ) $(OTHER_OBJS_B) $(MLX_FLAGS) -o $(NAME_1)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

bonus:
	@make $(NAME_1)

clean:
	rm -rf $(OBJ) $(OTHER_OBJS) $(OTHER_OBJS_B)

fclean: clean
	rm -rf $(NAME) $(NAME_1)

ra: all clean

re: fclean all

.PHONY: all clean fclean re bonus ra

