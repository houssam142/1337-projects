# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/02 17:59:55 by hounejja          #+#    #+#              #
#    Updated: 2025/09/21 18:37:19 by hounejja         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

NAME_1 = cub3D_bonus

BONUS = 0

CC = cc

CFLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -L$(MINILIBX_DIR) -lmlx -lXext -lX11 -lm

OTHER_SRCS = main.c parsing/parse_file.c utils/ft_strncmp.c utils/ft_putstr_fd.c \
	     parsing/map_game.c utils/get_next_line_utils.c utils/get_next_line.c \
		 utils/ft_atoi.c utils/ft_split.c utils/alloc.c parsing/check_color.c \
		 utils/ft_isdigit.c parsing/parse_file_utils.c error.c parsing/check_map.c \
		 utils/ft_strtrim.c mandatory/game_start.c parsing/game_map.c mandatory/player_position.c \
		 mandatory/vector.c mandatory/draw.c mandatory/raycasting.c mandatory/init_player_pos_and_ore.c \
		 mandatory/color.c mandatory/dda.c mandatory/raycasting_utils.c \
		 movement/movement.c movement/rotate.c mandatory/render.c mandatory/textures.c mandatory/init_window.c \
		 cleaning/clean_all.c utils/ft_bzero.c

OTHER_SRCS_B = main.c parsing/parse_file.c utils/ft_strncmp.c utils/ft_putstr_fd.c \
	     parsing/map_game.c utils/get_next_line_utils.c utils/get_next_line.c \
		 utils/ft_atoi.c utils/ft_split.c utils/alloc.c parsing/check_color.c \
		 utils/ft_isdigit.c parsing/parse_file_utils.c error.c parsing/check_map.c \
		 utils/ft_strtrim.c mandatory/game_start.c parsing/game_map.c mandatory/player_position.c \
		 mandatory/vector.c mandatory/draw.c mandatory/raycasting.c mandatory/init_player_pos_and_ore.c \
		 mandatory/color.c mandatory/dda.c mandatory/raycasting_utils.c \
		 movement/movement.c movement/rotate.c mandatory/render.c mandatory/textures.c mandatory/init_window.c \
		 cleaning/clean_all.c utils/ft_bzero.c movement/mouse_mo.c bonus/draw_minimap.c

OTHER_OBJS = $(OTHER_SRCS:.c=.o)

OTHER_OBJS_B = $(OTHER_SRCS_B:.c=.o)

MINILIBX_DIR = ./minilibx-linux


all: $(NAME)

$(NAME): $(OTHER_OBJS)
	@make -C minilibx-linux
	$(CC) $(CFLAGS) -DBONUS=$(BONUS) $(OBJ) $(OTHER_OBJS) $(MLX_FLAGS) -o $(NAME)
	@clear

$(NAME_1): $(OTHER_OBJS_B)
	@make -C minilibx-linux
	$(CC) $(CFLAGS) -DBONUS=$(BONUS) $(OBJ) $(OTHER_OBJS_B) $(MLX_FLAGS) -o $(NAME_1)

bonus:
	@make $(NAME_1) BONUS=1
	@clear

CFLAGS += -DBONUS=$(BONUS)

clean:
	rm -rf $(OBJ) $(OTHER_OBJS) $(OTHER_OBJS_B)

fclean: clean
	rm -rf $(NAME) $(NAME_1)

re: fclean all

.PHONY: all clean fclean re bonus

