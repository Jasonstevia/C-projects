CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = so_long
NAME_BONUS = so_long_bonus
ft_printf_dir = ft_printf
get_next_line = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
minilibx_dir = minilibx
SRC = so_long_1.c so_long_2.c parsing.c validation_1.c validation_2.c $(get_next_line)

OBJ = $(SRC:.c=.o)

BONUS_SRC = so_long_bonus_1.c so_long_bonus_2.c so_long_bonus_3.c parsing_bonus.c validation_1_bonus.c validation_2_bonus.c $(get_next_line)

all : $(NAME)

BONUS_OBJ = $(BONUS_SRC:.c=.o)

$(NAME) : $(OBJ)
	$(MAKE) -C $(ft_printf_dir)
	$(MAKE) -C $(minilibx_dir)
	$(CC) $(CFLAGS) $(OBJ) $(ft_printf_dir)/libftprintf.a $(minilibx_dir)/libmlx.a -lX11 -lXext -lm -lbsd -o $(NAME)

bonus : $(BONUS_OBJ)
	$(MAKE) -C $(ft_printf_dir)
	$(MAKE) -C $(minilibx_dir)
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(ft_printf_dir)/libftprintf.a $(minilibx_dir)/libmlx.a -lX11 -lXext -lm -lbsd -o $(NAME_BONUS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(BONUS_OBJ)
	$(MAKE) clean -C $(ft_printf_dir)
	$(MAKE) clean -C $(minilibx_dir)
fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	$(MAKE) fclean -C $(ft_printf_dir)
	$(MAKE) clean -C $(minilibx_dir)
re: fclean all

.PHONY: all clean fclean re