SRC = main.cpp Zombie.cpp zombieHorde.cpp

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

OBJ = $(SRC:.cpp=.o)

NAME = zombieHorde

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)


all: $(NAME)
	@echo "Makefile needs your attention"

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: re all fclean clean

