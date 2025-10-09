
CC = c++

NAME = phonebook

CFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = phonebook.cpp

$(NAME): $(SRC)
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)


all: $(NAME)
	@echo "It's compiled successfully!!"

clean:
	@rm -rf $(NAME)

fclean: clean

re: fclean all

.PHONY: re fclean clean all
