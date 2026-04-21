/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 15:06:24 by jslim             #+#    #+#             */
/*   Updated: 2026/02/13 15:06:26 by jslim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	execution(t_cmd *cmds, t_shell *shell)
{
	if (ft_strchr(cmds->argv[0], '/'))
	{
		execve(cmds->argv[0], cmds->argv, shell->env);
		perror("minishell");
		if (access(cmds->argv[0], F_OK) == -1)
			return (cleanup_shell_child(shell), (void)exit(127));
		return (cleanup_shell_child(shell), (void)exit(126));
	}
	resolve_path(&cmds->argv[0], *shell);
	execve(cmds->argv[0], cmds->argv, shell->env);
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmds->argv[0], 2);
	ft_putstr_fd(": command not found\n", 2);
	cleanup_shell_child(shell);
	exit(127);
}

static void	setup_child_pipes(int *meta, int pipefd[1024][2])
{
	if (meta[0] > 0)
	{
		close(pipefd[meta[0] - 1][1]);
		dup2(pipefd[meta[0] - 1][0], STDIN_FILENO);
		close(pipefd[meta[0] - 1][0]);
	}
	if (meta[0] < meta[1] - 1)
	{
		close(pipefd[meta[0]][0]);
		dup2(pipefd[meta[0]][1], STDOUT_FILENO);
		close(pipefd[meta[0]][1]);
	}
}

static void	pipe_child_execution(t_cmd *cmds, t_shell *shell,
		int *meta, int pipefd[1024][2])
{
	int	b;
	int	pb;

	set_signals_child_exec();
	setup_child_pipes(meta, pipefd);
	if (redirections(cmds->redirs))
		return (cleanup_shell_child(shell), (void)exit(g_exit_status));
	if (!cmds->argv || !cmds->argv[0] || !cmds->argv[0][0])
		return (cleanup_shell_child(shell), (void)exit(0));
	change_env_local(&shell->env, "_=", cmds->argv[0]);
	b = exec_builtin(cmds, shell);
	pb = exec_parent_builtin(cmds, shell);
	if (b == -1 && pb == -1)
		execution(cmds, shell);
	if (pb != -1)
		return (cleanup_shell_child(shell), (void)exit(pb));
	cleanup_shell_child(shell);
	exit(b);
}

static pid_t	exec_pipe_step(t_cmd *cmds, t_shell *shell, int *meta,
		int pipefd[1024][2])
{
	pid_t	pid;

	meta[0] = meta[2];
	set_signals_parent_waiting();
	pid = fork();
	if (pid == 0)
		pipe_child_execution(cmds, shell, meta, pipefd);
	if (meta[2] > 0)
	{
		close(pipefd[meta[2] - 1][0]);
		close(pipefd[meta[2] - 1][1]);
	}
	return (pid);
}

int	exec_pipeline(t_cmd *cmds, t_shell *shell)
{
	int				n;
	static int		pipefd[1024][2];
	pid_t			pid[1024];
	int				meta[3];

	n = cmd_count(cmds);
	meta[1] = n;
	meta[2] = 0;
	while (meta[2] < n)
	{
		if (meta[2] < n - 1 && pipe(pipefd[meta[2]]))
			return (perror("Pipe failed"), 1);
		pid[meta[2]] = exec_pipe_step(cmds, shell, meta, pipefd);
		meta[2]++;
		cmds = cmds->next;
	}
	g_exit_status = get_exit_status(pid, n);
	set_signals_interactive();
	return (g_exit_status);
}
