#include "push_swap.h"
#include <stdio.h>

int	parsing(int argc, char *argv[], int	*size_a)
{
	int	i;
	int	*a;

	a = malloc((argc - 1) * sizeof(int));
	if (!a)
		return (*size_a = 0, NULL);
	i = 1;
	while (i < argc)
	{
		a[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	*size_a = argc - 1;
	return (a);
}

int	main (int argc, char *argv[])
{
	int	*a;
	int	size_a;

	a = parsing(argc, argv, &size_a);
	printf("\n");

	return 0;
}