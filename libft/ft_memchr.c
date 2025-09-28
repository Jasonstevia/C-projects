/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslim <jslim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 18:05:43 by jslim             #+#    #+#             */
/*   Updated: 2025/06/18 13:53:12 by jslim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned int	i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
		{
			return ((void *)ptr + i);
		}
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// int main()
// {
// 	unsigned char ptr[] = "helleo";
// 	int c = 'e';
// 	printf("%s", (char *)ft_memchr(ptr, c, 4));
// 	return 0;
// }
