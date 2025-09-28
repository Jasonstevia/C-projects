/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslim <jslim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:17:45 by jslim             #+#    #+#             */
/*   Updated: 2025/06/18 11:27:00 by jslim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_char_in_set(char c, char const *set)
{
	unsigned int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	unsigned int	end;
	unsigned int	i;
	char			*s;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	i = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_char_in_set(s1[start], set))
		start++;
	while (end > start && ft_char_in_set(s1[end - 1], set))
		end--;
	if (start > end)
		return (ft_strdup(""));
	s = malloc(end - start + 1);
	if (!s)
		return (NULL);
	i = 0;
	while (start < end)
		s[i++] = s1[start++];
	s[i] = '\0';
	return (s);
}

// #include <stdio.h>
// int main ()
// {
// 	char s[] = "++hello+++";
// 	char set[] = "+";
// 	printf("%s", ft_strtrim(s, set));
// 	return (0);
// }
