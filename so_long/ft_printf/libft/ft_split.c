/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslim <jslim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 16:19:05 by jslim             #+#    #+#             */
/*   Updated: 2025/09/17 17:39:43 by jslim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char const *s, char c)
{
	int	i;
	int	count;
	int	in_word;

	i = 0;
	count = 0;
	in_word = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] != c && in_word == 0)
		{
			count++;
			in_word = 1;
		}
		else if (s[i] == c)
			in_word = 0;
		i++;
	}
	return (count);
}

static void	free_split(char **str, int j)
{
	while (j--)
		free(str[j]);
	free(str);
}

static void	fill(char **str, const char *s, char c)
{
	int	i;
	int	j;
	int	k;
	int	start;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (start < i)
		{
			str[j] = malloc(i - start + 1);
			if (!str[j])
				return (free_split(str, j));
			k = 0;
			while (start < i)
				str[j][k++] = s[start++];
			str[j++][k] = '\0';
		}
	}
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		count;

	count = ft_count(s, c);
	str = malloc((count + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	fill(str, s, c);
	str[count] = NULL;
	return (str);
}

// #include <stdio.h>
// int main()
// {
// 	int i = 0;
// 	char c = ' ';
// 	const char s[] = "  hello world split me  " ;
// 	char **str = ft_split(s, c);
// 	while (str[i])
// 		printf ("%s\n", str[i++]);
// 	i = 0;
// 	while (str[i])
// 		free(str[i++]);
// 	free(str);
// 	return 0;
// }
