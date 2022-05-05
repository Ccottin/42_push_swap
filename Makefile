
NAME	= push_swap

SRC	= ./src/check_arg.c	./src/main.c		./src/lst.c		./src/utils.c	./src/alg_utils_2.c	./src/radix_bin.c\
	  ./src/init.c		./src/push_swap.c	./src/instruction1.c	./src/truc6.c	./src/truc_cmd.c	./src/bubbles_2.c\
	  ./src/instruction2.c	./src/instruction.c	./src/move.c		./src/sort_5.c	./src/sort_small.c	./src/sort_6.c\
	  ./src/ft_return.c	./src/ft_split.c	./src/radix_sort.c	./src/bubbles.c	./src/alg_utils.c\
	  ./src/truc.c		./src/truc_utils.c

OBJ	= $(SRC:.c=.o)
		
CC	= gcc

CFLAG	= -Wall -Wextra -Werror -g3 #-fsanitize=address -g3

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
