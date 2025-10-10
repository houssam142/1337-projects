# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/08 17:33:59 by hounejja          #+#    #+#              #
#    Updated: 2025/10/10 20:00:12 by hounejja         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = tests.cpp Accounts.cpp

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

NAME = account

OBJ = $(SRC:.cpp=.o)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)
	@echo "It's been compiled successfully"

clean:
	rm -f $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: re fclean clean all
