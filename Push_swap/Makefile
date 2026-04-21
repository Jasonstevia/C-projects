CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap
ft_printf_dir = ft_printf
SRC = handle_errors_1.c handle_errors_2.c parsing.c radix_1.c radix_2.c rules_1.c rules_2.c rules_3.c utils_1.c utils_2.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(MAKE) -C $(ft_printf_dir) 
	$(CC) $(CFLAGS) $(OBJ) $(ft_printf_dir)/libftprintf.a -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) clean -C $(ft_printf_dir)
fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(ft_printf_dir)
re: fclean all

.PHONY: all clean fclean re