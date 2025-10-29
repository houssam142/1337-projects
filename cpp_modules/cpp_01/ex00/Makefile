SRC = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = zombie

OBJ = $(SRC:.cpp=.o)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: re all clean fclean
