SRCS = main.cpp

CPP = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

OBJS = $(SRCS:.cpp=.o)

NAME = ex01

$(NAME): $(OBJS)
	$(CPP) $(FLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

%.o: %.cpp
	$(CPP) $(FLAGS) -c $< -o $@

clean:
	 rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

ra: all clean

.PHONY: clean all re ra fclean
