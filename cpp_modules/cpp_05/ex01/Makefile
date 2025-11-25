SRCS = main.cpp Bureaucrat.cpp Form.cpp

CPP = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

OBJS = $(SRCS:.cpp=.o)

NAME = Forms

$(NAME): $(OBJS) ./Bureaucrat.hpp ./Form.hpp
	$(CPP) $(FLAGS) $(OBJS) -o $@

all: $(NAME)

%.o: %.cpp
	$(CPP) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: re fclean clean all
