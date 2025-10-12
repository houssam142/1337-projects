
CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp HumanA.cpp Weapon.cpp HumanB.cpp

OBJ = $(SRC:.cpp=.o)

NAME = war

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

all: $(NAME)
	@echo "It's been compiled successfully!!"

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: re all fclean clean

