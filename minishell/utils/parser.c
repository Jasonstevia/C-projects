/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghandou <rghandou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 09:19:42 by rghandou          #+#    #+#             */
/*   Updated: 2026/02/03 10:27:12 by rghandou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	parse_input(char *input, t_shell *shell)
{
	t_redir	*token;
	t_redir	*curr;

	if (!input || !*input)
		return (0);
	token = ft_tokenize(input);
	if (!token)
		return (0);
	if (syntax_check(token))
	{
		free_tokenize(token);
		return (0);
	}
	curr = token;
	while (curr)
	{
		if (curr->type == WORD)
			process_token_string(curr, shell);
		curr = curr->next;
	}
	shell->cmds = NULL;
	build_command_table(&shell->cmds, token);
	free_tokenize(token);
	return (1);
}

void	execute(char *input, t_shell *shell)
{
	if (parse_input(input, shell))
	{
		if (process_all_heredocs(shell->cmds, shell))
		{
			free_command_table(shell->cmds);
			shell->cmds = NULL;
			return ;
		}
		g_exit_status = execute_cmds(shell->cmds, shell);
		update_last_arg(shell, shell->cmds);
		free_command_table(shell->cmds);
		shell->cmds = NULL;
	}
	else
		g_exit_status = 2;
}
