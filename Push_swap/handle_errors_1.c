/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslim <jslim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:54:11 by jslim             #+#    #+#             */
/*   Updated: 2025/10/07 15:53:08 by jslim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *ptr)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	result = 0;
	sign = 1;
	while (ptr[i] == ' ' || ptr[i] == '\f' || ptr[i] == '\n'
		|| ptr[i] == '\r' || ptr[i] == '\t' || ptr[i] == '\v')
		i++;
	if (ptr[i] == '-' || ptr[i] == '+')
	{
		if (ptr[i] == '-')
			sign = -1;
		i++;
	}
	while (ptr[i] >= '0' && ptr[i] <= '9')
	{
		result = result * 10 + ptr[i] - '0';
		i++;
	}
	return (result * sign);
}

int	check_for_char(int argc, char *argv[])
{
	int		i;
	char	*s;

	i = 1;
	while (i < argc)
	{
		s = argv[i];
		if (*s == '\0')
			return (1);
		while (*s)
		{
			if (*s == ' ' || (*s >= 9 && *s <= 13))
				s++;
			if ((*s == '+' || *s == '-' )
				&& ft_isdigit((unsigned char) *(s + 1)))
				s++;
			if (!ft_isdigit((unsigned char) *s))
				return (1);
			s++;
		}
		i++;
	}
	return (0);
}

int	check_for_duplicates(int argc, char *argv[], int *size_a)
{
	int	*a;
	int	i;
	int	j;

	a = parsing(argc, argv, size_a);
	i = 0;
	while (i < *size_a)
	{
		j = i + 1;
		while (j < *size_a)
		{
			if (a[i] == a[j])
			{
				free(a);
				return (1);
			}
			j++;
		}
		i++;
	}
	free(a);
	return (0);
}
