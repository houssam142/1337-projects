SRCS = main.cpp AForm.cpp Bureaucrat.cpp ShrubberyCreationForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp Intern.cpp

CPP = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

OBJS = $(SRCS:.cpp=.o)

INC = ./ShrubberyCreationForm.hpp ./AForm.hpp ./Bureaucrat.hpp ./PresidentialPardonForm.hpp ./RobotomyRequestForm.hpp

NAME = ex03

$(NAME): $(OBJS) $(INC)
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

.PHONY: re fclean clean all ra
