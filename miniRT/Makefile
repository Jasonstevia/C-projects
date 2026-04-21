CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = miniRT
ft_printf_dir = ft_printf
get_next_line = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
minilibx_dir = minilibx
SRC = main.c $(get_next_line)

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(MAKE) -C $(ft_printf_dir)
	$(MAKE) -C $(minilibx_dir)
	$(CC) $(CFLAGS) $(OBJ) $(ft_printf_dir)/libftprintf.a $(minilibx_dir)/libmlx.a -lX11 -lXext -lm -lbsd -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) clean -C $(ft_printf_dir)
	$(MAKE) clean -C $(minilibx_dir)
fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(ft_printf_dir)
	$(MAKE) clean -C $(minilibx_dir)
re: fclean all

.PHONY: all clean fclean re