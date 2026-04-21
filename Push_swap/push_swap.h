/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslim <jslim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 17:05:18 by jslim             #+#    #+#             */
/*   Updated: 2025/10/07 16:26:55 by jslim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "ft_printf/libft/libft.h"
# include <unistd.h>

void	sa(int *a, int size);
void	sb(int *b, int size);
void	ra(int *a, int size);
void	rb(int *b, int size);
void	rr(int *a, int *b, int size_a, int size_b);
void	rra(int *a, int size);
void	rrb(int *b, int size);
void	rrr(int *a, int *b, int size_a, int size_b);
void	rr_helper(int *a, int size);
void	rrr_helper(int *a, int size);
void	pa(int *a, int *b, int *size_a, int *size_b);
void	pb(int *a, int *b, int *size_a, int *size_b);
int		ft_count(int argc, char *argv[]);
int		str_to_int(int *a, char **str, int index);
int		*parsing(int argc, char *argv[], int *size_a);
int		check_sorted(int *a, int size);
int		minimum_index(int *a, int size);
void	shrink(int *a, int *b, int *size_a, int *size_b);
void	sort3(int *a, int *size);
void	rotate_to_slot(int *a, int size, int i);
void	rebuild(int *a, int *b, int *size_a, int *size_b);
void	action(int *a, int *b, int *size_a, int *size_b);
long	ft_atol(const char *ptr);
int		check_for_char(int argc, char *argv[]);
int		check_for_duplicates(int argc, char *argv[], int *size_a);
int		str_to_long(long *a, char **str, int index);
long	*parsing_long(int argc, char *argv[], int *size_a);
int		int_exceeding_limit(int argc, char *argv[], int *size_a);
int		check_errors(int argc, char *argv[], int *size_a);
void	ft_swap(int *src, int *dest);
int		*ft_intcpy(const int *src, int size);
int		*sorting_helper(const int *arr, int size);
int		*array_to_index(int argc, char *argv[], int *size_a);
int		nbr_of_bits(int *size_a);
void	radix(int *a, int *b, int *size_a, int *size_b);

#endif
