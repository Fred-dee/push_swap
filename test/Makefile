NAME = test

# Path

SRC_PATH = ../src/

OBJ_PATH = ./objs/

INC_PATH = ../includes/

# Name

SRC_NAME =	get_next_line.c \
			push_functions.c \
			swap_functions.c \

OBJ_NAME = $(SRC_NAME:%.c=%.o)

# Files

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

FLAGS = -Wall -Werror -Wextra

CC = gcc $(FLAGS)

LDFLAGS = -L../libft/

LFT = -lft


all: $(NAME)

$(NAME): $(SRC) $(OBJ) $(INC_PATH)
	@make -C../libft/
	@$(CC) $(LDFLAGS) $(LFT) $(OBJ) main.c -o $@

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) -I$(INC_PATH) -o $@ -c $<

clean: cleanlib
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

cleanlib:
	@make clean -C ../libft/

fclean: clean fcleanlib
	@rm -f $(NAME)

fcleanlib:
	@make fclean -C ../libft/

re : fclean all