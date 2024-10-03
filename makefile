# Variables #

NAME	= pipex
CC		= gcc
CFLAGS	= -Wall -Wextra -g
RM		= rm -rf

# Libraries #

LIBFT_DIR		= lib/libft
LIBFT_FILE		= $(LIBFT_DIR)/libft.a

MAKE_LIB		= make --no-print-directory -C

# Push swap sources #

PIPEX_SRC	= $(wildcard *.c)

# Push swap objects #

PIPEX_OBJ = $(addprefix obj/, $(PIPEX_SRC:.c=.o))

# Rules #

all: $(NAME)

$(LIBFT_FILE):
	@$(MAKE_LIB) $(LIBFT_DIR)

obj/%.o:%.c
	@mkdir -p obj
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(PIPEX_OBJ) $(LIBFT_FILE)
	@$(CC) $(CFLAGS) -o $@ $^ -L $(LIBFT_DIR)
	@echo $(NAME) compiled!

clean:
	@$(RM) obj
	@$(RM) $(LIBFT_DIR)/*.o
	@echo Objects removed

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT_FILE)
	@echo Executable removed

re: fclean all

.PHONY: all clean fclean re