
NAME = megaphone

CC = g++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = megaphone.cpp

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

all: $(NAME)
	@echo "It's compiled successfully!!"

clean:
		rm -rf $(NAME)
	
fclean: clean
	@echo "cleaning successfull!!!"

re: fclean all

.PHONY: clean fclean all re
