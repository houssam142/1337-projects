SRC = Fdf_m.c

NAME = fdf

CC = cc

OBJ_SRC = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g3

UTILS = get_next_line.c get_next_line_utils.c utils.c init.c read_map.c free_data.c draw_map.c ft_get_win.c iso.c ft_split.c draw_utils.c bresenham.c connect.c \
		ft_atoi.c ft_strncmp.c ft_strchr.c add_back.c

LIBFTPRINTF = ft_printf/libftprintf.a

MINILIBX_LIB = minilibx-linux/libmlx.a

UTILS_OBJ = $(UTILS:.c=.o)

MLX_FLAGS   = -L./minilibx-linux -lmlx -lXext -lX11 -lm -lbsd

all: $(NAME)

$(NAME): $(UTILS_OBJ) $(OBJ_SRC)
	@cd ft_printf && make -s
	@cd minilibx-linux && make -s
	@$(CC) $(CFLAGS) $(OBJ_SRC) $(UTILS_OBJ) $(LIBFTPRINTF) $(MINILIBX_LIB) $(MLX_FLAGS) -o $(NAME)

clean:
	@cd ft_printf && make -s fclean
	@rm -f *.o

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: re all fclean clean
