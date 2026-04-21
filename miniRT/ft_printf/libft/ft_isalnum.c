/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslim <jslim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:58:31 by jslim             #+#    #+#             */
/*   Updated: 2025/05/27 15:35:43 by jslim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int ch)
{
	if ((ch > 47 && ch < 58) || (ch > 64 && ch < 91)
		|| (ch > 96 && ch < 123))
		return (1);
	else
		return (0);
}

// #include <stdio.h>
// int main ()
// {
// 	printf("%d\n", ft_isalnum(']'));
// 	printf("%d\n", ft_isalnum('5'));
// 	printf("%d\n", ft_isalnum('A'));
// 	return 0;
// }
