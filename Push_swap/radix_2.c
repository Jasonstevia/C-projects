/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 17:07:08 by jslim             #+#    #+#             */
/*   Updated: 2025/10/06 17:07:10 by jslim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix(int *a, int *b, int *size_a, int *size_b)
{
	int	i;
	int	bits;
	int	j;
	int	pass_len;

	i = 0;
	bits = nbr_of_bits(size_a);
	while (i < bits)
	{
		if (check_sorted(a, *size_a) && *size_b == 0)
			return ;
		j = 0;
		pass_len = *size_a;
		while (j < pass_len)
		{
			if (((a[0] >> i) & 1) == 1)
				ra(a, *size_a);
			else
				pb(a, b, size_a, size_b);
			j++;
		}
		while (*size_b > 0)
			pa(a, b, size_a, size_b);
		i++;
	}
}
