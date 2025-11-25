
SRCS = main.cpp Bureaucrat.cpp

CPP = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

OBJS = $(SRCS:.cpp=.o)

NAME = Bureaucrat

$(NAME): $(OBJS) ./Bureaucrat.hpp
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

