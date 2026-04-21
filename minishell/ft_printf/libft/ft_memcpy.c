/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslim <jslim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:54:49 by jslim             #+#    #+#             */
/*   Updated: 2025/06/18 13:53:32 by jslim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	const unsigned char	*ptr;
	unsigned char		*des;

	i = 0;
	ptr = (const unsigned char *)src;
	des = (unsigned char *)dest;
	while (i < n)
	{
		des[i] = ptr[i];
		i++;
	}
	return (dest);
}

// #include <stdio.h>
// int main ()
// {
// 	unsigned char src[] = "hello";
// 	unsigned char dest[4];
// 	ft_memcpy(dest, src, 3);
// 	dest[3] = '\0';
// 	printf("%s", dest);
// 	return 0;
// }
