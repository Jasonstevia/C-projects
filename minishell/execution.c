/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslim <jslim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 15:06:07 by jslim             #+#    #+#             */
/*   Updated: 2026/02/24 14:44:47 by jslim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_exit_status(pid_t pid[], int N)
{
	int	i;
	int	status;

	i = 0;
	while (i < N)
	{
		waitpid(pid[i], &status, 0);
		if (WIFSIGNALED(status) && WTERMSIG(status) == SIGQUIT)
			write(2, "Quit (core dumped)\n", 19);
		if (i == N - 1)
		{
			if (WIFEXITED(status))
				g_exit_status = WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
				g_exit_status = 128 + WTERMSIG(status);
			else
				g_exit_status = 1;
		}
		i++;
	}
	return (g_exit_status);
}

char	**split_env_path(t_shell shell)
{
	int		i;
	char	**env;
	char	*path;

	i = 0;
	env = NULL;
	while (shell.env[i])
	{
		if (!ft_strncmp(shell.env[i], "PATH=", 5))
		{
			path = shell.env[i] + 5;
			env = ft_split(path, ':');
			break ;
		}
		i++;
	}
	return (env);
}

static char	*find_exec_path(char **dirs, char *cmd_name)
{
	char	*path;
	char	*full;
	int		i;

	i = 0;
	while (dirs && dirs[i])
	{
		full = ft_strjoin(dirs[i], "/");
		path = ft_strjoin(full, cmd_name);
		free(full);
		if (access(path, X_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	return (NULL);
}

void	resolve_path(char **cmd_name, t_shell shell)
{
	char	**dirs;
	char	*path;

	dirs = split_env_path(shell);
	if (!ft_strnstr(*cmd_name, "/", ft_strlen(*cmd_name) + 1))
	{
		path = find_exec_path(dirs, *cmd_name);
		if (path)
		{
			free(*cmd_name);
			*cmd_name = path;
		}
	}
	if (dirs)
		free_split(dirs);
}

int	execute_cmds(t_cmd *cmds, t_shell *shell)
{
	int	pb;

	trim_empty_argv(cmds->argv);
	if ((!cmds->argv || !cmds->argv[0] || !cmds->argv[0][0]) && cmds->redirs)
		return (exec_pipeline(cmds, shell));
	if (!cmds->argv || !cmds->argv[0] || !cmds->argv[0][0])
		return (0);
	if (exit_paren_syntax(cmds))
		return (2);
	pb = -1;
	if (!cmds->next)
		pb = exec_parent_builtin(cmds, shell);
	if (!cmds->next && !ft_strcmp(cmds->argv[0], "exit"))
		return (ft_putstr_fd("exit\n", 1), free_command_table(cmds),
			cleanup_shell(shell), exit(pb), 0);
	if (cmds->next || (pb == -1))
		return (exec_pipeline(cmds, shell));
	return (pb);
}
