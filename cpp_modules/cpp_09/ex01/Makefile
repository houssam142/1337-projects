SRCS = main.cpp RPN.cpp

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = RPN

OBJS = $(SRCS:.cpp=.o)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)


clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

ra: all clean

.PHONY: re ra fclean clean all
