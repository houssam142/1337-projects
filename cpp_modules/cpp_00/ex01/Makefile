CC = c++

NAME = phonebook

SRC = Phonebook.cpp
CFLAGS = -Wall -Wextra -Werror -std=c++98


OBJ = $(SRC:.cpp=.o)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)
	@echo "It compiled successfully!"

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: re fclean clean all
