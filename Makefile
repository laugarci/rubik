NAME = rubik

SRC_DIR = src/
SRC_FILES = main.c \
	    utils.c \
	    face_moves.c \
	    apply_input.c \
	    moves_F.c \
	    moves_U.c \
#	    moves_D.c \
	    moves_R.c \
	    moves_L.c \
	    moves_B.c \

OBJ_DIR = objs/
OBJ_FILES = $(SRC_FILES:.c=.o)
OBJS = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

DEP_FILES = $(SRC_FILES:.c=.d)
DEPS = $(addprefix $(OBJ_DIR), $(DEP_FILES))

CC = gcc

CFLAGS = -Wall -Wextra -Werror -MMD

RM = rm -f

INCLUDE = -I inc/

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c Makefile
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) -r $(OBJ_DIR)
	$(RM) $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
