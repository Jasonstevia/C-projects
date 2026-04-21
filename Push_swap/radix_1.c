/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslim <jslim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:52:38 by jslim             #+#    #+#             */
/*   Updated: 2025/10/06 17:06:32 by jslim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *src, int *dest)
{
	int	temp;

	temp = *dest;
	*dest = *src;
	*src = temp;
}

int	*ft_intcpy(const int *src, int size)
{
	int	i;
	int	*dst;

	dst = malloc(sizeof(int) * size);
	if (!dst)
		return (NULL);
	i = 0;
	while (i < size)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

int	*sorting_helper(const int *arr, int size)
{
	int	i;
	int	j;
	int	*cpy;

	i = 0;
	cpy = ft_intcpy(arr, size);
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (cpy[i] > cpy[j])
				ft_swap(&cpy[j], &cpy[i]);
			j++;
		}
		i++;
	}
	return (cpy);
}

int	*array_to_index(int argc, char *argv[], int *size_a)
{
	int	*arr;
	int	*cpy;
	int	i;
	int	j;

	i = 0;
	arr = parsing(argc, argv, size_a);
	cpy = sorting_helper(arr, *size_a);
	while (i < *size_a)
	{
		j = 0;
		while (j < *size_a)
		{
			if (arr[i] == cpy[j])
			{
				arr[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
	return (free(cpy), arr);
}

int	nbr_of_bits(int *size_a)
{
	int	bits;
	int	max_num;

	bits = 0;
	max_num = *size_a - 1;
	while ((max_num >> bits) != 0)
		bits++;
	return (bits);
}
