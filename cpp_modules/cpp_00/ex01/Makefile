
CC = c++

NAME = phonebook

CFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = phonebook.cpp

OBJ = $(SRC:.cpp=.o)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)


all: $(NAME)
	@echo "It's compiled successfully!!"

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: re fclean clean all
