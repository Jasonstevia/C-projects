/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslim <jslim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:07:44 by jslim             #+#    #+#             */
/*   Updated: 2025/06/11 16:58:37 by jslim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dup;
	int		str_len;

	str_len = ft_strlen(s);
	dup = malloc(str_len + 1);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

// #include <stdio.h>
// int main()
// {
// 	char s[] = "hello";
// 	char *dup = ft_strdup(s);
// 	printf("%s", dup);
// 	free(dup);
// 	return 0;
// }
