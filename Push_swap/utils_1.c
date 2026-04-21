/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslim <jslim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:53:29 by jslim             #+#    #+#             */
/*   Updated: 2025/10/06 17:02:09 by jslim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted(int *a, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (a[i] > a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	minimum_index(int *a, int size)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < size)
	{
		if (a[j] > a[i])
			j = i;
		i++;
	}
	return (j);
}

void	shrink(int *a, int *b, int *size_a, int *size_b)
{
	int	min_index;
	int	cost_ra;
	int	cost_rra;

	min_index = minimum_index(a, *size_a);
	if (min_index == 0)
		pb(a, b, size_a, size_b);
	else if (min_index > 0)
	{
		cost_ra = min_index;
		cost_rra = *size_a - min_index;
		if (cost_ra > cost_rra)
			rra(a, *size_a);
		else
			ra(a, *size_a);
	}
}

void	sort3(int *a, int *size)
{
	int	i;

	i = minimum_index(a, *size);
	if (i == 0 && a[1] > a[2])
	{
		sa(a, *size);
		ra(a, *size);
	}
	else if (i == 1 && a[0] < a[2])
		sa(a, *size);
	else if (i == 1 && a[0] > a[2])
		ra(a, *size);
	else if (i == 2 && a[0] > a[1])
	{
		sa(a, *size);
		rra(a, *size);
	}
	else if (i == 2 && a[0] < a[1])
		rra(a, *size);
}

void	rotate_to_slot(int *a, int size, int i)
{
	int	cost_ra;
	int	cost_rra;

	cost_ra = i;
	cost_rra = size - i;
	if (cost_rra > cost_ra)
	{
		while (cost_ra--)
			ra(a, size);
	}
	else
	{
		while (cost_rra--)
			rra(a, size);
	}
}
