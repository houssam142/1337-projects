# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/03 08:08:54 by hounejja          #+#    #+#              #
#    Updated: 2025/02/23 16:30:02 by hounejja         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP_SRCS  = push_swap.c

EXEC_PUSH_SWAP  = push_swap

EXEC_CHECKER	= checker

NAME = push_swap.a

CFLAGS = -Wall -Wextra -Werror

LIB_CHECKER		= checker.a

PUSH_SWAP_OBJS = $(PUSH_SWAP_SRCS:.c=.o)

UTILS_SRCS = cost.c \
	     do_move.c \
	     initialization.c \
	     input_check_utils.c \
	     input_check.c \
	     position.c \
	     stack.c \
	     swap.c \
	     utils.c \
	     push.c \
	     reverse_rotate.c \
	     sort_tiny.c \
	     sort.c \
	     rotate.c \
	     utils2.c \
		 ft_split.c \
		 ft_lstnew.c \
		 ft_lstclear.c \
		 get_next_line_utils.c

SRCS_BONUS = helper_bonus.c checker_utils_bonus.c get_next_line.c \
		  checker_bonus.c \

PUSH_SWAP_OBJ   = $(PUSH_SWAP_SRCS:.c=.o)
UTILS_OBJ       = $(UTILS_SRCS:.c=.o)

UTILS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(EXEC_PUSH_SWAP)

$(EXEC_PUSH_SWAP): $(UTILS_OBJ) $(PUSH_SWAP_OBJ)
	@ar rcs $(NAME) $(PUSH_SWAP_OBJ) $(UTILS_OBJ)
	@$(CC) $(CFLAGS) $(INCLUDES) $(NAME) -o $(EXEC_PUSH_SWAP)


bonus: $(UTILS_OBJ) $(UTILS_BONUS)
	@ar rcs $(LIB_CHECKER) $(UTILS_BONUS) $(UTILS_OBJ)
	@$(CC) $(CFLAGS) $(LIB_CHECKER) -o $(EXEC_CHECKER)
	@touch bonus

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

.SECONDARY: $(UTILS_OBJ) $(PUSH_SWAP_OBJ) $(BONUS_UTILS)

clean:
	@rm -f *.o
	@rm -rf $(NAME)
	@rm -rf $(LIB_CHECKER)
        
fclean: clean
	@rm -rf $(EXEC_PUSH_SWAP) $(EXEC_CHECKER) bonus

re: fclean all

.PHONY: all re fclean clean
