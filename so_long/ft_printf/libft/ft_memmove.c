/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslim <jslim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 12:07:02 by jslim             #+#    #+#             */
/*   Updated: 2025/06/18 13:53:44 by jslim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*des;
	const unsigned char	*ptr;

	des = (unsigned char *)dest;
	ptr = (const unsigned char *)src;
	if (ptr < des)
	{
		i = n;
		while (i > 0)
		{
			des[i - 1] = ptr[i - 1];
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			des[i] = ptr [i];
			i++;
		}
	}
	return (dest);
}
// #include <stdio.h>
// int main ()
// {
// 	unsigned char src[] = "hello";
// 	ft_memmove(src + 2, src, 3);
// 	printf("%s", src);
// 	return 0;
// }
