# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "ft_printf/ft_printf.h"
#include "ft_printf/libft/libft.h"

void	sa(int *a, int size);
void	ra(int *a, int size);
void	rra(int *a, int size);
void	pa(int *a, int *b, int *size_a, int *size_b);
void	pb(int *a, int *b, int *size_a, int *size_b);
void	print_stacks(int *a, int size_a, int *b, int size_b);
int	is_sorted_from_index(int *a, int start, int size);
int	check_sorted(int *a, int size);
char	*decide(int *a, int *b, int size_a, int size_b);
void	action(int *a, int *b, int size_a, int size_b);


# endif