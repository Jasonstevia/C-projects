/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_builtins_export.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslim <jslim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 15:05:14 by jslim             #+#    #+#             */
/*   Updated: 2026/04/07 18:30:44 by jslim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	is_valid_identifier(char *arg)
{
	int	i;

	i = 0;
	if (!arg || !arg[0] || arg[0] == '=')
		return (0);
	if (!ft_isalpha(arg[0]) && arg[0] != '_')
		return (0);
	while (arg[i] && arg[i] != '=')
	{
		if (!ft_isalnum(arg[i]) && arg[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

static char	*extract_line(char *arg)
{
	int		i;
	int		arg_len;
	char	*key;

	arg_len = ft_strlen(arg);
	i = 0;
	while (arg[i] && arg[i] != '=')
		i++;
	if (arg[i] == '=')
		return (arg);
	key = ft_substr(arg, 0, i);
	return (key);
}

static int	invalid_identifier(char *arg)
{
	ft_putstr_fd("minishell: export: `", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
	return (1);
}

static int	export_var(t_shell *shell, char *arg)
{
	char	*line;
	int		idx;
	int		has_equal;

	if (!is_valid_identifier(arg))
		return (invalid_identifier(arg));
	has_equal = ft_strchr(arg, '=') != NULL;
	line = extract_line(arg);
	if (!line)
	{
		ft_putstr_fd("minishell: export: malloc error\n", 2);
		return (1);
	}
	idx = find_env_index_local(arg, shell->env);
	if (idx == -1)
		shell->env = env_append_local(shell->env, line);
	else if (has_equal)
	{
		free(shell->env[idx]);
		shell->env[idx] = ft_strdup(line);
	}
	free(line);
	return (0);
}

int	builtin_export(t_cmd *cmds, t_shell *shell)
{
	int	i;
	int	status;

	if (!cmds->argv[1] && !ft_strchr(cmds->argv[0], '='))
		return (builtin_export_view(shell));
	i = 1;
	status = 0;
	if (ft_strchr(cmds->argv[0], '='))
		i = 0;
	while (cmds->argv[i])
	{
		if (export_var(shell, cmds->argv[i]))
			status = 1;
		i++;
	}
	return (status);
}
