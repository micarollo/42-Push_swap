NAME = push_swap

SRC = main.c utils.c operations.c check.c print_lst.c sort.c \
		quick_sort.c sort_4.c sort_5.c operations2.c

OBJ = ${SRC:.c=.o}

PUSHSWAP = -Ipush_swap

CC = GCC

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(PUSHSWAP) -o push_swap

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
