/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslim <jslim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:53:18 by jslim             #+#    #+#             */
/*   Updated: 2025/10/06 17:15:46 by jslim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(int *b, int size)
{
	int	temp;

	if (size < 2)
		return ;
	temp = b[0];
	b[0] = b[1];
	b[1] = temp;
	ft_printf("sb\n");
}

void	rb(int *b, int size)
{
	int	i;
	int	temp;

	if (size < 2)
		return ;
	i = 0;
	temp = b[0];
	while (i < size - 1)
	{
		b[i] = b[i + 1];
		i++;
	}
	b[size - 1] = temp;
	ft_printf("rb\n");
}

void	rrb(int *b, int size)
{
	int	i;
	int	temp;

	if (size < 2)
		return ;
	i = size - 1;
	temp = b[i];
	while (i > 0)
	{
		b[i] = b[i - 1];
		i--;
	}
	b[0] = temp;
	ft_printf("rrb\n");
}

void	rr_helper(int *a, int size)
{
	int	i;
	int	temp;

	if (size < 2)
		return ;
	i = 0;
	temp = a[0];
	while (i < size - 1)
	{
		a[i] = a[i + 1];
		i++;
	}
	a[size - 1] = temp;
}

void	rrr_helper(int *a, int size)
{
	int	i;
	int	temp;

	if (size < 2)
		return ;
	i = size - 1;
	temp = a[i];
	while (i > 0)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[0] = temp;
}
