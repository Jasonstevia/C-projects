/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslim <jslim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 11:19:13 by rghandou          #+#    #+#             */
/*   Updated: 2026/02/18 13:42:51 by jslim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_tokenize(t_redir *token)
{
	t_redir		*current;
	t_redir		*next;

	current = token;
	while (current)
	{
		next = current->next;
		if (current->target)
			free(current->target);
		free(current);
		current = next;
	}
}

void	free_command_table(t_cmd	*cmd_table)
{
	t_cmd	*tmp;
	t_cmd	*next;
	int		i;

	tmp = cmd_table;
	while (tmp)
	{
		next = tmp->next;
		i = 0;
		while (tmp->argv[i])
		{
			free(tmp->argv[i]);
			i++;
		}
		free(tmp->argv);
		free_tokenize(tmp->redirs);
		free(tmp);
		tmp = next;
	}
}

void	cleanup_shell_child(t_shell *shell)
{
	if (!shell)
		return ;
	if (shell->cmds)
		free_command_table(shell->cmds);
	shell->cmds = NULL;
	if (shell->last_arg)
		free(shell->last_arg);
	shell->last_arg = NULL;
	if (shell->env)
		free_split(shell->env);
	shell->env = NULL;
}

void	cleanup_shell(t_shell *shell)
{
	if (!shell)
		return ;
	if (shell->last_arg)
		free(shell->last_arg);
	shell->last_arg = NULL;
	if (shell->env)
		free_split(shell->env);
	shell->env = NULL;
	rl_clear_history();
}
