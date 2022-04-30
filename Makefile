
NAME	= push_swap

SRC	= ./src/check_arg.c	./src/main.c	./src/lst.c	./src/utils.c \
	  ./src/init.c	./src/push_swap.c	./src/instruction1.c \
	  ./src/instruction2.c	./src/instruction.c	./src/move.c   ./src/algo.c \
	  ./src/ft_return.c	./src/ft_split.c	./src/bubbles.c	./src/radix_sort.c \
	  ./src/alg.c

OBJ	= $(SRC:.c=.o)
		
CC	= gcc

CFLAG	= -Wall -Wextra -Werror -g3

all	:	$(NAME)

%.o	:	%.c
		$(CC) $(CFLAG) -Iinclude -c $< -o $@

$(NAME)	:	$(OBJ)
		$(CC) $(CFLAG) -o $@ $^ 

clean	:
		rm -rf $(OBJ)

fclean	:	clean
		rm -rf $(NAME)

re	:	fclean all

.PHONY	:	all	clean	fclean	re
