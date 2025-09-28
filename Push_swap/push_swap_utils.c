#include "push_swap.h"
#include <stdio.h>
void	sa(int *a, int size)
{
	int	temp;

	if (size < 2)
		return;

	temp = a[0];
	a[0] = a[1];
	a[1] = temp;
}

void	ra(int *a, int size)
{
	int	i;
	int temp;

	if (size < 2)
		return;
	i = 0;
	temp = a[0];
	while (i < size - 1)
	{
		a[i] = a[i + 1];
		i++;
	}
	a[size - 1] = temp;
}

void	rra(int *a, int size)
{
	int	i;
	int	temp;

	if (size < 2)
		return;
	i = size - 1;
	temp = a[i];
	while (i > 0)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[0] = temp;
}

void	pa(int *a, int *b, int *size_a, int *size_b)
{
	int i;
	int j;

	if (*size_b == 0)
		return;
	j = 0;
	(*size_a)++;
	i = *size_a - 1;
	while (i > 0)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[0] = b[0];
	while (j < *size_b - 1)
	{
		b[j] = b[j + 1];
		j++;
	}
	(*size_b)--;
}

void	pb(int *a, int *b, int *size_a, int *size_b)
{
	int	i;
	int	j;

	if (*size_a == 0)
		return;
	j = 0;
	(*size_b)++;
	i = *size_b - 1;
	while (i > 0)
	{
		b[i] = b[i - 1];
		i--;
	}
	b[0] = a[0];
	while (j < *size_a - 1)
	{
		a[j] = a[j + 1];
		j++;
	}
	(*size_a)--;
}

void	print_stacks(int *a, int size_a, int *b, int size_b)
{
	int	i;
	int	h;

	if (size_a > size_b)
		h = size_a;
	else
		h = size_b;
	i = 0;
	printf("A\tB\n");
	while (i < h)
	{
		if (i < size_a)
			printf("%d", a[i]);
		else
			printf(" ");
		printf("\t");
		if (i < size_b)
			printf("%d", b[i]);
		else
			printf(" ");
		printf("\n");
		i++;
	}
	printf("\n");
}
