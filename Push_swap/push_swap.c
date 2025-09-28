#include "push_swap.h"

int	is_sorted_from_index(int *a, int start, int size)
{
	int	i;

	i = start;
	while (i < size - 1)
	{
		if (a[i] > a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	check_sorted(int *a, int size)
{
	int	i;

	if (is_sorted_from_index(a, 0, size))
		return (0);
	i = 1;
	while (i < size - 1)
	{
		if (is_sorted_from_index(a, i, size))
			return (i);
		i++;
	}
	return (-1);
}

char	*decide(int *a, int *b, int *size_a, int *size_b)
{
	int	i;
	int	cost_ra;
	int	cost_rra;

	i = check_sorted(a, *size_a);
	if (i == 0)
		return ("DO_NOTHING");
	else if (i > 0)
	{
		cost_ra = i;
		cost_rra = *size_a - i;
		if (cost_ra > cost_rra)
			return(rra(a, *size_a), "DO_RRA");
		else
			return (ra(a, *size_a), "DO_RA");
	}
	else if (i == -1)
		{
			if (a[0] > a[1])
				return (sa(a, *size_a), "DO_SA");
			else if (a[0] < a[1])
				return (pb(a, b, size_a, size_b), "DO_PB");
		}
}

void	action(int *a, int *b, int *size_a, int *size_b)
{
	char	*action;
	print_stacks(a, *size_a, b, *size_b);
	while (1)
	{
		action = decide(a, b, size_a, size_b);
		if (!strcmp(action, "DO_NOTHING") && *size_b == 0)
			break;
		else if (!strcmp(action, "DO_NOTHING") && *size_b <= 2)
		{
			if (b[0] > b[1])
				sa(b, size_b);
			else if (b[0] < b[1])
				pb(b, a, size_b, size_a);
		}
		else if (!(strcmp(action, "DO_NOTHING")) && *size_b > 2)
			action = decide(b, a, size_b, size_a);
	}
	print_stacks(a, *size_a, b, *size_b);
}

int main()
{
	int a[16] = {4, 1, 2, 3};
	int b[16] = {};
	int size_a = 4;
	int size_b = 0;
	action(a, b, &size_a, &size_b);
	return 0;
}