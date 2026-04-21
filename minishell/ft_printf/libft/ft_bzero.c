/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslim <jslim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 13:24:25 by jslim             #+#    #+#             */
/*   Updated: 2025/06/18 13:48:36 by jslim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = '\0';
		i++;
	}
}

// #include <stdio.h>
// int main()
// {
// 	unsigned char ptr[10];
// 	int i = 0;
// 	while (i < 10)
// 	{
// 		ptr[i] = '5';
// 		i++;
// 	}
// 	printf("before erasing :%s\n", ptr);
// 	ft_bzero(ptr, 10);
// 	printf("After erasing :%s", ptr);
// 	return 0;
// }
