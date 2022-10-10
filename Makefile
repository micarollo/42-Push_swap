# **************************************************************************** #
# NAME
# **************************************************************************** #

NAME			= push_swap

# **************************************************************************** #
# DIRS
# **************************************************************************** #

SRC_DIR			= src
INCLUDE_DIR		= include
OBJ_DIR			= obj

# **************************************************************************** #
# FILES
# **************************************************************************** #

INC				= -I $(INCLUDE_DIR)

SRC				=  main.c utils.c operations.c check.c sort.c \
					quick_sort.c sort_4.c sort_5.c operations2.c init_stack.c \
					ft_free.c

OBJ				= $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

DEP	   			= $(addsuffix .d, $(basename $(OBJ)))

# **************************************************************************** #
#COMPILATION
# **************************************************************************** #

COMPILE			= gcc -c
LINK			= gcc
CFLAGS			= -Wall -Werror -Wextra -MMD $(INC)
LIBC			= ar -rcs
RM_FILE			= rm -f
RM_DIR			= rm -rf
MKDIR			= mkdir -p

# **************************************************************************** #
#RULES
# **************************************************************************** #

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
			@$(MKDIR) -p $(dir $@)
			@$(COMPILE) $(CFLAGS) -o $@ $<
			@ECHO "Compiling... $^"

all:			$(NAME)

-include $(DEP) 
$(NAME):		$(OBJ)
				@$(LINK) $(OBJ) -o $(NAME)
				@ECHO "Created push_swap (mandatory)"

clean:
				@$(RM_FILE) $(OBJ)
				@$(RM_DIR)  $(OBJ_DIR)
				@ECHO "Objects cleaned"

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY: 		all clean fclean re
