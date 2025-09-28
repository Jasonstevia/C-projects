CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap.a
ft_printf_dir = ft_printf
SRC = push_swap.c push_swap_utils.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	make -C $(ft_printf_dir) 
	cp $(ft_printf_dir)/libftprintf.a $(NAME)
	ar rcs $(NAME) $(OBJ)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	make clean -C $(ft_printf_dir)
fclean: clean
	rm -f $(NAME)
	make fclean -C $(ft_printf_dir)
re: fclean all

.PHONY: all bonus clean fclean re