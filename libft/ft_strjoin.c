/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslim <jslim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 17:48:44 by jslim             #+#    #+#             */
/*   Updated: 2025/06/18 13:55:43 by jslim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*s;
	unsigned int	s1_len;
	unsigned int	s2_len;
	unsigned int	i;
	unsigned int	j;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	s = malloc(s1_len + s2_len + 1);
	i = 0;
	j = 0;
	if (!s1 || !s2 || !s)
		return (NULL);
	while (s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	while (s2[j])
		s[i++] = s2[j++];
	s[i] = '\0';
	return (s);
}

// #include <stdio.h>
// int main()
// {
// 	char s1[] = "hello ";
// 	char s2[] = "world";
// 	printf("%s", ft_strjoin(s1, s2));
// 	return 0;
// }
