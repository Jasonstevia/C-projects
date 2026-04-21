/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslim <jslim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 15:01:32 by jslim             #+#    #+#             */
/*   Updated: 2026/02/24 13:06:33 by jslim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	handle_sigint(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	exit(130);
}

static void	heredoc_child(int fd, char *delimiter, t_shell *shell, int expand)
{
	char	*line;

	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, SIG_IGN);
	while (1)
	{
		line = readline("> ");
		if (!line || !ft_strcmp(line, delimiter))
			return (free(line), exit(0));
		if (expand)
			expand_heredoc_line(&line, shell);
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
	}
}

static int	fill_heredoc(int fd, char *delimiter, t_shell *shell, int expand)
{
	int		pid;
	int		status;

	pid = fork();
	if (pid < 0)
		return (1);
	if (pid == 0)
		heredoc_child(fd, delimiter, shell, expand);
	close(fd);
	free(delimiter);
	set_signals_parent_waiting();
	waitpid(pid, &status, 0);
	set_signals_interactive();
	if (WIFSIGNALED(status)
		|| (WIFEXITED(status) && WEXITSTATUS(status) == 130))
		return (g_exit_status = 130, 1);
	return (0);
}

int	redir_heredoc(t_redir *r, t_shell *shell)
{
	int		fd;
	char	*filename;
	char	*delimiter;

	if (init_heredoc_io(&filename, &fd))
		return (1);
	delimiter = remove_delimiter_quotes(r->target);
	if (!delimiter)
		return (close(fd), free(filename), 1);
	if (fill_heredoc(fd, delimiter, shell, !is_delimiter_quoted(r->target)))
		return (g_exit_status = 130, unlink(filename), free(filename), 1);
	free(r->target);
	r->target = filename;
	r->type = R_IN;
	return (0);
}

int	process_all_heredocs(t_cmd *cmds, t_shell *shell)
{
	t_cmd	*curr_cmd;
	t_redir	*curr_token;

	curr_cmd = cmds;
	while (curr_cmd)
	{
		curr_token = curr_cmd->redirs;
		while (curr_token)
		{
			if (curr_token->type == R_HEREDOC
				&& redir_heredoc(curr_token, shell))
				return (1);
			curr_token = curr_token->next;
		}
		curr_cmd = curr_cmd->next;
	}
	return (0);
}
