/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 17:08:29 by jslim             #+#    #+#             */
/*   Updated: 2025/10/06 17:08:31 by jslim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(int *a, int *b, int size_a, int size_b)
{
	rrr_helper(a, size_a);
	rrr_helper(b, size_b);
	ft_printf("rrr\n");
}

void	rr(int *a, int *b, int size_a, int size_b)
{
	rr_helper(a, size_a);
	rr_helper(b, size_b);
	ft_printf("rr\n");
}
