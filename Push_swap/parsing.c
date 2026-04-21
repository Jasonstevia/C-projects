/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:53:56 by jslim             #+#    #+#             */
/*   Updated: 2025/10/06 16:53:57 by jslim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count(int argc, char *argv[])
{
	int		i;
	int		j;
	int		count;
	char	**str;

	i = 1;
	count = 0;
	while (i < argc)
	{
		str = ft_split(argv[i], ' ');
		j = 0;
		while (str[j])
		{
			count++;
			free(str[j]);
			j++;
		}
		free(str);
		i++;
	}
	return (count);
}

int	str_to_int(int *a, char **str, int index)
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

int	*parsing(int argc, char *argv[], int *size_a)
{
	int		i;
	int		*a;
	char	**str;
	int		count;
	int		index;

	count = ft_count(argc, argv);
	a = malloc((count) * sizeof(int));
	if (!a)
		return (*size_a = 0, NULL);
	i = 1;
	index = 0;
	while (i < argc)
	{
		str = ft_split(argv[i], ' ');
		index = str_to_int(a, str, index);
		i++;
	}
	*size_a = index;
	return (a);
}
