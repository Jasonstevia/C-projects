/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghandou <rghandou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 12:29:54 by rghandou          #+#    #+#             */
/*   Updated: 2026/02/03 09:49:40 by rghandou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

t_redir	*token_new(char	*content, t_redirtype	type)
{
	t_redir	*new_node;

	new_node = malloc (sizeof(t_redir));
	if (! new_node)
		return (NULL);
	new_node->type = type;
	new_node->target = content;
	new_node->next = NULL;
	return (new_node);
}

void	token_add_back(t_redir **heap, t_redir *new_node)
{
	t_redir	*temp;

	if (!heap || !new_node)
		return ;
	if (!(*heap))
	{
		*heap = new_node;
		return ;
	}
	temp = *heap;
	while (temp->next)
		temp = temp->next;
	temp->next = new_node;
}

void	cmd_add_back(t_cmd **heap, t_cmd *new_node)
{
	t_cmd	*curr;

	if (!heap || !new_node)
		return ;
	if (!(*heap))
	{
		*heap = new_node;
		return ;
	}
	curr = *heap;
	while (curr->next)
		curr = curr->next;
	curr->next = new_node;
}

void	trim_empty_argv(char **argv)
{
	int	i;

	while (argv && argv[0] && !argv[0][0] && argv[1])
	{
		free(argv[0]);
		i = 0;
		while (argv[i + 1])
		{
			argv[i] = argv[i + 1];
			i++;
		}
		argv[i] = NULL;
	}
}
