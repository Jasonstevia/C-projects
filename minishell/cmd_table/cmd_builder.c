/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_builder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghandou <rghandou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 13:19:38 by rghandou          #+#    #+#             */
/*   Updated: 2026/01/30 15:28:44 by rghandou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	count_args(t_redir *token)
{
	int	count;

	count = 0;
	while (token && token->type != PIPE)
	{
		if (token->type == WORD)
			count++;
		else if (is_redirections(token->type))
		{
			if (token->next)
				token = token->next;
		}
		token = token->next;
	}
	return (count);
}

static t_cmd	*cmd_new(t_redir	*token)
{
	t_cmd	*new_node;

	if (!token)
		return (NULL);
	new_node = malloc(sizeof(t_cmd));
	if (!new_node)
		return (NULL);
	new_node->argv = malloc(sizeof(char *) * (count_args(token) + 1));
	if (!new_node->argv)
		return (free(new_node), NULL);
	new_node->argv[0] = NULL;
	new_node->redirs = NULL;
	new_node->next = NULL;
	return (new_node);
}

static void	fill_args(t_cmd *cmd, t_redir *token)
{
	int		i;
	t_redir	*new;

	i = 0;
	while (token && token->type != PIPE)
	{
		if (token->type == WORD)
			cmd->argv[i++] = ft_strdup(token->target);
		else if (is_redirections(token->type))
		{
			new = token_new(NULL, token->type);
			if (!new)
				return ;
			if (token->next && token->next->type == WORD)
			{
				new->target = ft_strdup(token->next->target);
				token = token->next;
			}
			else
				new->target = NULL;
			token_add_back(&cmd->redirs, new);
		}
		token = token->next;
	}
	cmd->argv[i] = NULL;
}

void	build_command_table(t_cmd **cmds, t_redir *token)
{
	t_cmd	*new;

	while (token)
	{
		new = cmd_new(token);
		fill_args(new, token);
		cmd_add_back(cmds, new);
		while (token && token->type != PIPE)
			token = token->next;
		if (token && token->type == PIPE)
			token = token->next;
	}
}
