CPP = c++

NAME = phonebook

SRC = Phonebook.cpp Contact.cpp
CFLAGS = -Wall -Wextra -Werror -std=c++98


OBJ = $(SRC:.cpp=.o)

$(NAME): $(OBJ)
	$(CPP) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CPP) $(CFLAGS) -c $< -o $@

all: $(NAME)
	@echo "It compiled successfully!"

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: re fclean clean all
