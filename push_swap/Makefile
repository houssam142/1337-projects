# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/03 08:08:54 by hounejja          #+#    #+#              #
#    Updated: 2025/01/29 10:04:56 by hounejja         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


PUSH_SWAP_SRCS  = main.c

EXEC_PUSH_SWAP  = push_swap

CHECKER_SRCS	= checker.c

EXEC_CHECKER	= checker

LIB_CHECKER		= checker.a

PUSH_SWAP_OBJS = $(PUSH_SWAP_SRCS:.c=.o)

UTILS_SRCS = srcs/cost.c \
	     srcs/do_move.c \
	     srcs/initialization.c \
	     srcs/input_check_utils.c \
	     srcs/input_check.c \
	     srcs/position.c \
	     srcs/stack.c \
	     srcs/swap.c \
	     srcs/utils.c \
	     srcs/push.c \
	     srcs/reverse_rotate.c \
	     srcs/sort_tiny.c \
	     srcs/sort.c \
	     srcs/rotate.c \
	     srcs/utils2.c \
	     srcs/checker_utils.c \
	     srcs/get_next_line/get_next_line.c \
		 srcs/get_next_line/get_next_line_utils.c \
		 srcs/ft_split.c \
		 srcs/ft_lstnew.c \
		 srcs/ft_lstadd_back.c \
		 srcs/ft_lstclear.c

NAME = push_swap.a

CC = cc
CFLAGS = -Wall -Wextra -Werror


PUSH_SWAP_OBJ   = $(PUSH_SWAP_SRCS:.c=.o)
CHECKER_OBJ		= $(CHECKER_SRCS:.c=.o)
UTILS_OBJ               = $(UTILS_SRCS:.c=.o)
INCLUDES                = -I Libft/

all: $(EXEC_PUSH_SWAP)

$(EXEC_PUSH_SWAP): $(UTILS_OBJ) $(PUSH_SWAP_OBJ)
	@ar rcs $(NAME) $(PUSH_SWAP_OBJ) $(UTILS_OBJ)
	@$(CC) $(CFLAGS) $(INCLUDES) $(NAME) -o $(EXEC_PUSH_SWAP)


bonus: $(UTILS_OBJ) $(CHECKER_OBJ)
	@ar rcs $(LIB_CHECKER) $(CHECKER_OBJ) $(UTILS_OBJ)
	@$(CC) $(CFLAGS) $(INCLUDES) $(LIB_CHECKER) -o $(EXEC_CHECKER)
	@touch bonus

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@cd srcs && rm -f *.o
	@cd srcs/get_next_line && rm -f *.o
	@rm -rf *.o
	@rm -rf $(NAME)
	@rm -rf $(LIB_CHECKER)
	@rm -rf bonus
        
fclean: clean
	@rm -rf $(EXEC_PUSH_SWAP) $(EXEC_CHECKER)

re: fclean all
