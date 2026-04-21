/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghandou <rghandou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 08:57:47 by rghandou          #+#    #+#             */
/*   Updated: 2026/02/03 09:48:23 by rghandou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	handel_redirect(char *str, int *i, t_redir **heap)
{
	if (str[*i +1] == '>')
	{
		token_add_back(heap, token_new(ft_strdup(">>"), R_APPEND));
		(*i) += 2;
	}
	else
	{
		token_add_back(heap, token_new(ft_strdup(">"), R_OUT));
		(*i)++;
	}
}

void	handler_seperator(char	*str, int *i, t_redir **heap)
{
	if (str[*i] == '|')
	{
		token_add_back(heap, token_new(ft_strdup("|"), PIPE));
		(*i)++;
	}
	else if (str[*i] == '>')
	{
		handel_redirect(str, i, heap);
	}
	else if (str[*i] == '<')
	{
		if (str[*i +1] == '<')
		{
			token_add_back(heap, token_new(ft_strdup("<<"), R_HEREDOC));
			(*i) += 2;
		}
		else
		{
			token_add_back(heap, token_new(ft_strdup("<"), R_IN));
			(*i)++;
		}
	}
}

void	handler_word(char	*str, int *i, t_redir **heap)
{
	int		start;
	char	*word;
	char	quote;

	start = *i;
	quote = 0;
	while (str[*i])
	{
		if (!quote && (str[*i] == '\'' || str[*i] == '"'))
			quote = str[*i];
		else if (quote && str[*i] == quote)
			quote = 0;
		if (!quote && (is_space(str[*i]) || is_separator(str[*i])))
			break ;
		(*i)++;
	}
	word = ft_substr(str, start, *i - start);
	token_add_back(heap, token_new(word, WORD));
}

t_redir	*ft_tokenize(char *str)
{
	t_redir	*head;
	int		i;

	head = NULL;
	i = 0;
	while (str[i])
	{
		if (is_space(str[i]))
			i++;
		else if (is_separator(str[i]))
			handler_seperator(str, &i, &head);
		else if (str[i])
			handler_word(str, &i, &head);
	}
	return (head);
}
