/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_builtins_unset.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 15:05:25 by jslim             #+#    #+#             */
/*   Updated: 2026/02/13 15:05:26 by jslim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	find_index_env(char *arg, char **env)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(arg);
	while (env[i])
	{
		if (!ft_strncmp(env[i], arg, len) && env[i][len] == '=')
			return (i);
		i++;
	}
	return (-1);
}

static void	env_unset(char ***env, char *arg)
{
	int	i;
	int	idx;

	idx = find_index_env(arg, *env);
	if (idx == -1)
		return ;
	free((*env)[idx]);
	i = idx;
	while ((*env)[i + 1])
	{
		(*env)[i] = (*env)[i + 1];
		i++;
	}
	(*env)[i] = NULL;
}

int	builtin_unset(t_cmd *cmds, t_shell *shell)
{
	int	i;

	i = 1;
	while (cmds->argv[i])
	{
		env_unset(&shell->env, cmds->argv[i]);
		i++;
	}
	return (0);
}
