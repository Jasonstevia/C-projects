/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslim <jslim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:40:03 by jslim             #+#    #+#             */
/*   Updated: 2025/06/18 13:56:53 by jslim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	f(unsigned int i, char c)
// {
// 	if (i % 2 == 0)
// 		return (c);
// 	else
// 		return (c - 32);
// }

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		s_len;
	int		i;
	char	*str;

	i = 0;
	s_len = ft_strlen((char *)s);
	str = malloc(s_len + 1);
	if (!str)
		return (NULL);
	while (i < s_len)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

// #include <stdio.h>
// int main()
// {
// 	char s[] = "hello";
// 	char *s1 = ft_strmapi(s, f);
// 	printf("%s", s1);
// 	return 0;
// }
