/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslim <jslim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 15:35:21 by jslim             #+#    #+#             */
/*   Updated: 2025/10/07 16:26:37 by jslim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	str_to_long(long *a, char **str, int index)
{
	int	j;

	j = 0;
	while (str[j])
	{
		a[index++] = ft_atol(str[j]);
		free(str[j]);
		j++;
	}
	free(str);
	return (index);
}

long	*parsing_long(int argc, char *argv[], int *size_a)
{
	int		i;
	long	*a;
	char	**str;
	int		count;
	int		index;

	count = ft_count(argc, argv);
	a = malloc((count) * sizeof(long));
	if (!a)
		return (*size_a = 0, NULL);
	i = 1;
	index = 0;
	while (i < argc)
	{
		str = ft_split(argv[i], ' ');
		index = str_to_long(a, str, index);
		i++;
	}
	*size_a = index;
	return (a);
}

int	int_exceeding_limit(int argc, char *argv[], int *size_a)
{
	long	*a;
	int		i;

	a = parsing_long(argc, argv, size_a);
	i = 0;
	while (i < *size_a)
	{
		if (a[i] < -2147483648 || a[i] > 2147483647)
		{
			free(a);
			return (1);
		}
		i++;
	}
	free(a);
	return (0);
}

int	check_errors(int argc, char *argv[], int *size_a)
{
	if (check_for_char(argc, argv) || check_for_duplicates(argc, argv, size_a)
		|| int_exceeding_limit(argc, argv, size_a))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	else
		return (0);
}
