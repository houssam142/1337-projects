NAME = cub3D

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3

MLX_FLAGS = -L$(MINILIBX_DIR) -lmlx -lXext -lX11 -lm

SRC = main.c

OTHER_SRCS = parsing/parse_file.c utils/ft_strncmp.c utils/ft_putstr_fd.c \
	     parsing/map_game.c utils/get_next_line_utils.c utils/get_next_line.c \
		 utils/ft_atoi.c utils/ft_split.c utils/alloc.c parsing/check_color.c \
		 utils/ft_isdigit.c parsing/parse_file_utils.c error.c parsing/check_map.c \
		 utils/ft_strtrim.c mandatory/game_start.c parsing/game_map.c

OTHER_OBJS = $(OTHER_SRCS:.c=.o)

MINILIBX_DIR = /usr/include/minilibx-linux

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(OTHER_OBJS)
	$(CC) $(CFLAGS) $(OBJ) $(OTHER_OBJS) $(MLX_FLAGS) -o $(NAME)

.o:.c
	$(CC) $(CFLAGS) $(MLX_FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ) $(OTHER_OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean
