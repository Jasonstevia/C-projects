/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslim <jslim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 15:03:45 by jslim             #+#    #+#             */
/*   Updated: 2026/02/13 15:21:23 by jslim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	find_env_index_local(char *arg, char **env)
{
	int	i;
	int	key_len;

	i = 0;
	key_len = 0;
	if (!arg || !env)
		return (-1);
	while (arg[key_len] && arg[key_len] != '=')
		key_len++;
	while (env[i])
	{
		if (!ft_strncmp(env[i], arg, key_len)
			&& (env[i][key_len] == '=' || env[i][key_len] == '\0'))
			return (i);
		i++;
	}
	return (-1);
}

char	**env_append_local(char **env, char *newline)
{
	int		i;
	int		j;
	char	**copy_env;

	j = 0;
	while (env && env[j])
		j++;
	copy_env = malloc((j + 2) * sizeof(char *));
	if (!copy_env)
		return (NULL);
	i = 0;
	while (i < j)
	{
		copy_env[i] = env[i];
		i++;
	}
	copy_env[j] = ft_strdup(newline);
	copy_env[j + 1] = NULL;
	free(env);
	return (copy_env);
}

void	change_env_local(char ***env, char *key, char *value)
{
	int		idx;
	char	*newline;

	idx = find_env_index_local(key, *env);
	if (idx != -1)
	{
		free((*env)[idx]);
		(*env)[idx] = ft_strjoin(key, value);
	}
	else
	{
		newline = ft_strjoin(key, value);
		*env = env_append_local(*env, newline);
		free(newline);
	}
}
