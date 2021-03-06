#!bin/sh
NAME1 = push_swap
NAME2 = checker
# Path

SRC_PATH = ./src/

OBJ_PATH = ./objs/

INC_PATH = ./includes/

# Name

SRC_NAME =	algo3.c \
			algo5.c \
			algo5_help.c \
			helper_functions4.c \
			get_next_line.c \
			print_functions.c \
			print_functions2.c \
			print_functions3.c \
			push_functions.c \
			swap_functions.c \
			helper_functions.c \
			helper_functions2.c \
			helper_functions3.c \
			rotate_functions.c \

OBJ_NAME = $(SRC_NAME:%.c=%.o)

# Files

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

FLAGS = -Wall -Werror -Wextra

CC = gcc $(FLAGS)

LDFLAGS = -L ./libft/

LFT = -lft

all: $(NAME1) $(NAME2)

$(NAME1): $(OBJ) $(INC_PATH) ./src_main/push_swap.c
	@make -C./libft/
	@$(CC) -o $@  $(OBJ) ./src_main/push_swap.c  $(LDFLAGS) $(LFT)   

$(NAME2): $(OBJ) $(INC_PATH) ./src_main/checker.c
	@make -C./libft/
	@$(CC)  -o $@ $(OBJ) ./src_main/checker.c $(LDFLAGS) $(LFT) 

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) -I$(INC_PATH) -o $@ -c $<

clean: cleanlib
	/bin/rm -rf $(OBJ)
	/bin/rm -rf $(OBJ_PATH) 2> /dev/null || true

cleanlib:
	@make clean -C ./libft/

fclean: clean fcleanlib
	@rm -f $(NAME1)
	@rm -f $(NAME2)

fcleanlib:
	@make fclean -C ./libft/

re : fclean all