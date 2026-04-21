CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = minishell
ft_printf_dir = ft_printf
SRC = signals.c main.c execution.c pipe.c pipe_utils.c \
	builtins/builtins_echo.c \
	builtins/builtins_env.c \
	builtins/builtins_export_view.c \
	builtins/builtins_pwd.c \
	builtins/exec_builtin.c \
	builtins/parent_builtins_cd.c \
	builtins/parent_builtins_exit.c \
	builtins/parent_builtins_export.c \
	builtins/parent_builtins_unset.c \
	builtins/builtins_utils.c \
	cmd_table/cmd_builder.c \
	redirections/heredoc.c \
	redirections/heredoc_utils.c \
	redirections/redirections.c \
	tokenizer/parsing.c \
	tokenizer/tokenize.c \
	tokenizer/validation_syntax.c \
	utils/clean_all.c \
	utils/parser.c \
	utils/utils.c \
	word_validation/word_utils.c \
	word_validation/word_validation.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(MAKE) -C $(ft_printf_dir) 
	$(CC) $(CFLAGS) $(OBJ) $(ft_printf_dir)/libftprintf.a -o $(NAME) -lreadline

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	find . -name "*.o" -delete
	$(MAKE) clean -C $(ft_printf_dir)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(ft_printf_dir)
re: fclean all

.PHONY: all bonus clean fclean re
