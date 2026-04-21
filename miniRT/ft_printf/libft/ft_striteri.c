/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslim <jslim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 11:08:20 by jslim             #+#    #+#             */
/*   Updated: 2025/06/18 13:55:21 by jslim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// void	f(unsigned int i, char *str)
// {
// 	if (str[i] >= 'A' && str[i] <= 'Z')
// 		str[i] = str[i] + 32;
// 	else if (str[i] >= 'a' && str[i] <= 'z')
// 		str[i] = str[i] - 32;
// }

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// #include <stdio.h>
// int main()
// {
// 	char s[] = "heLLO";
// 	ft_striteri(s, f);
// 	printf("%s", s);
// 	return 0;
// }
