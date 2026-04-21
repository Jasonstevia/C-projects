/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslim <jslim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:09:38 by jslim             #+#    #+#             */
/*   Updated: 2025/06/18 14:19:43 by jslim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	size_t	total;
	char	*str;

	i = 0;
	if (size == 0 || nmemb == 0)
		return (malloc(0));
	total = nmemb * size;
	str = malloc(total);
	if (!str)
		return (NULL);
	while (i < total)
	{
		str[i] = 0;
		i++;
	}
	return ((void *)str);
}

// #include <stdio.h>
// int main()
// {
// 	size_t i = 0;
// 	size_t size = 4;
// 	size_t nmemb = 5;
// 	char *str = (char *)ft_calloc(nmemb, size);
// 	while (i < size *nmemb)
// 	{
// 		printf("%d", str[i]);
// 		i++;
// 	}
// 	free(str);
// 	return 0;
// }
