/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 15:02:25 by jslim             #+#    #+#             */
/*   Updated: 2026/02/13 15:02:27 by jslim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	redir_out(t_redir *r)
{
	int	fd;

	fd = open(r->target, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		return (perror(r->target), 1);
	if (dup2(fd, STDOUT_FILENO) < 0)
		return (close(fd), perror("dup2"), 1);
	close(fd);
	return (0);
}

static int	redir_in(t_redir *r)
{
	int	fd;

	fd = open(r->target, O_RDONLY);
	if (fd < 0)
		return (perror(r->target), 1);
	if (dup2(fd, STDIN_FILENO) < 0)
		return (close(fd), perror("dup2"), 1);
	close(fd);
	return (0);
}

static int	redir_append(t_redir *r)
{
	int	fd;

	fd = open(r->target, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd < 0)
		return (perror(r->target), 1);
	if (dup2(fd, STDOUT_FILENO) < 0)
		return (close(fd), perror("dup2"), 1);
	close(fd);
	return (0);
}

int	redirections(t_redir *r)
{
	while (r)
	{
		if (r->type == R_IN)
		{
			if (redir_in(r))
				return (g_exit_status = 1, 1);
		}
		else if (r->type == R_OUT)
		{
			if (redir_out(r))
				return (g_exit_status = 1, 1);
		}
		else if (r->type == R_APPEND)
		{
			if (redir_append(r))
				return (g_exit_status = 1, 1);
		}
		r = r->next;
	}
	return (0);
}
