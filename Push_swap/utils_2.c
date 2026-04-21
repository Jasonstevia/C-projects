/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslim <jslim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:53:40 by jslim             #+#    #+#             */
/*   Updated: 2025/10/07 16:13:47 by jslim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rebuild(int *a, int *b, int *size_a, int *size_b)
{
	int	i;
	int	cost_rra;
	int	cost_ra;

	i = 0;
	while (i < *size_a - 1 && !(b[0] > a[i] && b[0] < a[i + 1]))
		i++;
	cost_ra = i;
	cost_rra = *size_a - i;
	if (b[0] < a[0])
		pa(a, b, size_a, size_b);
	else if (b[0] > a[*size_a - 1])
	{
		pa(a, b, size_a, size_b);
		ra(a, *size_a);
	}
	else
	{
		rotate_to_slot(a, *size_a, i);
		pa(a, b, size_a, size_b);
	}
}

void	action(int *a, int *b, int *size_a, int *size_b)
{
	while (1)
	{
		if (check_sorted(a, *size_a) && *size_b == 0)
			break ;
		else if (check_sorted(a, *size_a) && *size_b > 0)
		{
			while (*size_b > 0)
				rebuild(a, b, size_a, size_b);
		}
		else if (!check_sorted(a, *size_a) && *size_a > 3 && *size_a <= 50)
			shrink(a, b, size_a, size_b);
		else if (!check_sorted(a, *size_a) && *size_a == 3)
			sort3(a, size_a);
		else if (!check_sorted(a, *size_a) && *size_a == 2)
			sa(a, *size_a);
	}
}

int	main(int argc, char **argv)
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;

	size_b = 0;
	a = NULL;
	if (argc == 1)
		return (0);
	if (check_errors(argc, argv, &size_a))
		return (0);
	b = malloc(ft_count(argc, argv) * sizeof(int));
	if (!b)
		return (1);
	if (size_a <= 50)
	{
		a = parsing(argc, argv, &size_a);
		action(a, b, &size_a, &size_b);
	}
	else if (size_a > 50)
	{
		a = array_to_index(argc, argv, &size_a);
		radix(a, b, &size_a, &size_b);
	}
	return (free(a), free(b), 0);
}
