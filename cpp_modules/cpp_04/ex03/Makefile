SRCS = main.cpp Character.cpp Ice.cpp Cure.cpp MateriaSource.cpp AMateria.cpp

CPP = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

INCS = ./Character.hpp ./MateriaSource.hpp ./ICharacter.hpp ./Ice.hpp ./Cure.hpp

OBJS = $(SRCS:.cpp=.o)

NAME = Interface

$(NAME): $(OBJS) $(INCS)
	$(CPP) $(CPPFLAGS) $(INCS) $(OBJS) -o $(NAME)

all: $(NAME)
	@echo "It's been compiled successfully!!"

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: re fclean all clean

