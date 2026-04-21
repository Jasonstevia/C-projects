/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_export_view.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslim <jslim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 20:30:00 by jslim             #+#    #+#             */
/*   Updated: 2026/02/19 20:30:00 by jslim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	env_size(char **env)
{
	int	i;

	i = 0;
	while (env && env[i])
		i++;
	return (i);
}

static char	**copy_env_refs(char **env, int n)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (n + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < n)
	{
		copy[i] = env[i];
		i++;
	}
	copy[n] = NULL;
	return (copy);
}

static void	sort_env_refs(char **arr, int n)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (i < n - 1)
	{
		j = i + 1;
		while (j < n)
		{
			if (ft_strcmp(arr[i], arr[j]) > 0)
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

static void	print_export_line(char *line)
{
	int	i;

	i = 0;
	ft_putstr_fd("declare -x ", 1);
	while (line[i] && line[i] != '=')
		write(1, &line[i++], 1);
	if (!line[i])
		return ((void)write(1, "\n", 1));
	ft_putstr_fd("=\"", 1);
	ft_putstr_fd(line + i + 1, 1);
	ft_putstr_fd("\"\n", 1);
}

int	builtin_export_view(t_shell *shell)
{
	char	**arr;
	int		i;
	int		n;

	n = env_size(shell->env);
	arr = copy_env_refs(shell->env, n);
	if (!arr)
		return (1);
	sort_env_refs(arr, n);
	i = 0;
	while (i < n)
		print_export_line(arr[i++]);
	free(arr);
	return (0);
}
