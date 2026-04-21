#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include "minilibx/mlx.h"
# include "ft_printf/libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"

typedef struct s_miniRT
{
	char	*path;
	char	*sphere;
	char	*light;
	char	*plane;
	char	*cylinder;
} miniRT;


#endif