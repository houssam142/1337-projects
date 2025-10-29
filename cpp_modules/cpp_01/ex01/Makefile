SRC = main.cpp Zombie.cpp zombieHorde.cpp

CPP = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

OBJ = $(SRC:.cpp=.o)

NAME = zombieHorde

$(NAME): $(OBJ)
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)


all: $(NAME)
	@echo "Makefile needs your attention"

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: re all fclean clean

