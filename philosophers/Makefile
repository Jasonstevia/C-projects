CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = philo
SRC = init.c main.c start_routine_1.c start_routine_2.c utils.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -pthread -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all bonus clean fclean re
