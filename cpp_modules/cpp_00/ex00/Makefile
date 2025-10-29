
NAME = megaphone

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = megaphone.cpp

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

all: $(NAME)
	@echo "It's compiled successfully!!"

%.o: %.cpp
	$(cc) $(CFLAGS) -c $< -o $@

clean:
		rm -rf $(NAME)
	
fclean: clean
	@echo "cleaning successfull!!!"

re: fclean all

.PHONY: clean fclean all re
