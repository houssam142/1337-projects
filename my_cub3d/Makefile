NAME = cub3d

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3

SRC = main.c

OTHER_SRCS = parsing/parse_file.c utils/ft_strncmp.c utils/ft_putstr_fd.c \
	     parsing/check_map.c utils/get_next_line_utils.c utils/get_next_line.c \
		 utils/ft_atoi.c utils/ft_split.c utils/alloc.c parsing/check_color.c \
		 utils/ft_isdigit.c

OTHER_OBJS = $(OTHER_SRCS:.c=.o)

MINILIBX_DIR = /usr/include/minilibx-linux

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(OTHER_OBJS)
	$(CC) $(CFLAGS) $(OBJ) $(OTHER_OBJS) -lXext -lX11 -o $(NAME)

.o:.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ) $(OTHER_OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean
