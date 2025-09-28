/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslim <jslim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 17:52:21 by jslim             #+#    #+#             */
/*   Updated: 2025/06/11 16:46:23 by jslim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	s_len;

	s_len = ft_strlen((char *)s);
	if ((char)c == '\0')
		return ((char *)s + s_len);
	while (s_len >= 0)
	{
		if (s[s_len] == (char)c)
			return ((char *)s + s_len);
		s_len--;
	}
	return (NULL);
}

// #include <stdio.h>
// int main()
// {
// 	char s[] = "helleo";
// 	int c = 'e';
// 	printf ("%s", ft_strrchr(s, c));
// 	return 0;
// }
