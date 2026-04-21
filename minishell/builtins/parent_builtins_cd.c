/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_builtins_cd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslim <jslim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 15:04:46 by jslim             #+#    #+#             */
/*   Updated: 2026/04/07 12:55:23 by jslim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <errno.h>

static char	*get_path(char *directory, t_shell *shell)
{
	int		i;
	int		directory_len;
	char	*path;

	i = 0;
	path = NULL;
	if (!directory)
		return (NULL);
	directory_len = ft_strlen(directory);
	while (shell->env[i])
	{
		if (!ft_strncmp(directory, shell->env[i], directory_len))
		{
			path = shell->env[i] + directory_len;
			break ;
		}
		i++;
	}
	return (path);
}

static int	run_cd(char *direction, t_shell *shell)
{
	char	oldcwd[1024];
	char	cwd[1024];

	if (!direction)
		return (1);
	if (!getcwd(oldcwd, sizeof(oldcwd)))
		return (perror("minishell: cd"), 1);
	if (chdir(direction))
	{
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putstr_fd(direction, 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(strerror(errno), 2);
		return (1);
	}
	if (!getcwd(cwd, sizeof(cwd)))
		return (perror("minishell: cd"), 1);
	change_env_local(&shell->env, "OLDPWD=", oldcwd);
	change_env_local(&shell->env, "PWD=", cwd);
	return (0);
}

static char	*handle_tilde(char *arg, t_shell *shell, int *free_it)
{
	char	*path;

	if (!arg || (arg[0] == '~' && arg[1] == '\0'))
		return (get_path("HOME=", shell));
	else if (arg[0] == '~' && arg[1] == '/')
	{
		path = ft_strjoin(get_path("HOME=", shell), arg + 1);
		*free_it = 1;
		return (path);
	}
	return (arg);
}

static char	*handle_dash(t_shell *shell)
{
	char	*path;

	path = get_path("OLDPWD=", shell);
	if (path)
	{
		write(1, path, ft_strlen(path));
		write(1, "\n", 1);
	}
	else
		ft_putstr_fd("minishell: cd: OLDPWD not set\n", 2);
	return (path);
}

int	builtin_cd(t_cmd *cmds, t_shell *shell)
{
	char	*path;
	int		free_it;
	int		res;

	free_it = 0;
	if (cmds->argv[1] && cmds->argv[1][0] == '-' && cmds->argv[1][1] == '\0')
	{
		path = handle_dash(shell);
		if (!path)
			return (1);
	}
	else
	{
		path = handle_tilde(cmds->argv[1], shell, &free_it);
		if (!path)
			return (ft_putstr_fd("minishell: cd: HOME not set\n", 2), 1);
	}
	res = run_cd(path, shell);
	if (free_it)
		free(path);
	return (res);
}
