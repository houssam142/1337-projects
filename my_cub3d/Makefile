NAME = cub3d

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3

SRC = main.c

OTHER_SRCS = parsing/parse_file.c utils/ft_strlen.c utils/ft_strncmp.c utils/ft_putstr_fd.c \
	     parsing/check_map.c

OTHER_OBJS = $(OTHER_SRCS:.c=.o)

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
