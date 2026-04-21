CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a
LIBFT_DIR = libft
SRC = ft_printf.c ft_printf_utils.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	make -C $(LIBFT_DIR) 
	cp $(LIBFT_DIR)/libft.a $(NAME)
	ar rcs $(NAME) $(OBJ)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT_DIR)
fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)
re: fclean all

.PHONY: all bonus clean fclean re