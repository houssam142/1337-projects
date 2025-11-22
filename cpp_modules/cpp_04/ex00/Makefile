SRCS = main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp

CPP = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

OBJS = $(SRCS:.cpp=.o)

NAME = Animal

$(NAME): $(OBJS) ./Animal.hpp ./Cat.hpp ./Dog.hpp ./WrongAnimal.hpp ./WrongCat.hpp
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: re fclean all clean
