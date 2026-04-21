/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_syntax.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghandou <rghandou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 08:57:53 by rghandou          #+#    #+#             */
/*   Updated: 2026/01/25 13:14:09 by rghandou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	syntax_error(char	*token)
{
	ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
	ft_putstr_fd(token, 2);
	ft_putstr_fd("`", 2);
	ft_putstr_fd("\n", 2);
	return (1);
}

static int	check_pipes(t_redir *tokens)
{
	t_redir	*curr;

	curr = tokens;
	if (!curr->next)
		return (syntax_error("|"));
	if (curr->next->type == PIPE)
		return (syntax_error("|"));
	return (0);
}

static	int	check_redirections(t_redir	*tokens)
{
	t_redir	*curr;

	curr = tokens;
	if (!curr->next)
		return (syntax_error("newline"));
	if (curr->next->type == PIPE)
		return (syntax_error("|"));
	if (is_redirections(curr->next->type))
		return (syntax_error("newline"));
	return (0);
}

int	syntax_check(t_redir *tokens)
{
	t_redir	*curr;

	if (!tokens)
		return (0);
	if (tokens->type == PIPE)
		return (syntax_error("|"));
	curr = tokens;
	while (curr)
	{
		if (curr->type == PIPE)
		{
			if (check_pipes(curr))
				return (1);
		}
		if (is_redirections(curr->type))
		{
			if (check_redirections(curr))
				return (1);
		}
		curr = curr->next;
	}
	return (0);
}
