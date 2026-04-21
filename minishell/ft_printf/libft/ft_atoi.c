/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslim <jslim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 12:52:46 by jslim             #+#    #+#             */
/*   Updated: 2025/06/11 17:00:03 by jslim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *ptr)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	result = 0;
	sign = 1;
	while (ptr[i] == ' ' || ptr[i] == '\f' || ptr[i] == '\n'
		|| ptr[i] == '\r' || ptr[i] == '\t' || ptr[i] == '\v')
		i++;
	if (ptr[i] == '-' || ptr[i] == '+')
	{
		if (ptr[i] == '-')
			sign = -1;
		i++;
	}
	while (ptr[i] >= '0' && ptr[i] <= '9')
	{
		result = result * 10 + ptr[i] - '0';
		i++;
	}
	return (result * sign);
}

// #include <stdio.h>
// int main()
// {
//     char str[] = "    --+-123 Ab67";
// 	printf("%d", ft_atoi(str));
//     return 0;
// }
