SRC =	algo_2.c  error.c op_rev_rotate.c iznogoud.c\
		algo_3.c algo_launcher.c op_rotate.c \
		med_algo.c convert_to.c init_fonctions.c op_swap.c tri_index.c  \
		big_algo.c dbl_lst_utils_02.c minamax.c push_swap.c \
		dbl_lst_utils.c op_push.c \
		put_index.c index_push_swap.c index_rotate_rev.c tri_index_utils.c\

NAME = push_swap

CC = clang

CFLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address

OBJ_DIR = obj
SRC_DIR = src
INC_DIR = includes

OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
DPD = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.d))

.c.o:
	${CC} ${CFLAGS} -c$< -o ${<:.c=.o}

all:
	@$(MAKE) -j $(NAME)

$(NAME): $(OBJ)
		${CC} $(CFLAGS) -o $(NAME) $(OBJ) 
		@echo $(NAME) : Created !

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | .gitignore
		@mkdir -p $(OBJ_DIR)
		${CC} $(CFLAGS) -I $(INC_DIR) -c $< -o $@

.gitignore:
		@echo $(NAME) > .gitignore

clean:
	@rm -rf $(OBJ_DIR)
	@echo "obj deleted"./

fclean:	clean
	@rm -rf $(NAME)
	@echo "[$(NAME)]: deleted"

re: fclean all

.PHONY: all, clean, fclean, re

-include $(DPD)
