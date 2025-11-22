SRCS = main.cpp Animal.cpp Cat.cpp Dog.cpp Brain.cpp

CPP = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

OBJS = $(SRCS:.cpp=.o)

NAME = Brain

$(NAME): $(OBJS) ./Animal.hpp ./Cat.hpp ./Dog.hpp ./Brain.hpp
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
