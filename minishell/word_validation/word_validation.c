/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslim <jslim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 08:58:13 by rghandou          #+#    #+#             */
/*   Updated: 2026/02/24 10:54:56 by jslim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*write_expanded(char *old_string, int start, int len, char *value)
{
	char	*before;
	char	*after;
	char	*tmp;
	char	*new;
	int		end;

	end = start + 1 + len;
	before = ft_substr(old_string, 0, start);
	after = ft_substr(old_string, end, ft_strlen(old_string) - end);
	if (!before || !after)
		return (free(before), free(after), NULL);
	tmp = ft_strjoin(before, value);
	free(before);
	if (!tmp)
		return (free(after), NULL);
	new = ft_strjoin(tmp, after);
	free(after);
	free(tmp);
	return (new);
}

static char	*special_variable_value(char *str, int i, t_shell *shell, int *len)
{
	if (str[i + 1] == '?')
		return (*len = 1, ft_itoa(g_exit_status));
	if (str[i + 1] == '_')
	{
		*len = 1;
		if (shell->last_arg)
			return (ft_strdup(shell->last_arg));
		return (ft_strdup(""));
	}
	return (NULL);
}

static char	*get_variable_value(char *str, int i, t_shell *shell, int *len)
{
	char	*name;
	char	*value;

	*len = 0;
	value = special_variable_value(str, i, shell, len);
	if (value)
		return (value);
	while (str[i + 1 + *len]
		&& (ft_isalnum(str[i + 1 + *len]) || str[i + 1 + *len] == '_'))
		(*len)++;
	if (*len == 0)
		return (ft_strdup("$"));
	name = ft_substr(str, i + 1, *len);
	if (!name)
		return (NULL);
	value = get_env_value(shell->env, name);
	free(name);
	if (!value)
		return (ft_strdup(""));
	return (value);
}

int	expand_variable(char **str, int i, t_shell *shell)
{
	char	*value;
	char	*new;
	char	*old;
	int		len;
	int		value_len;

	value = get_variable_value(*str, i, shell, &len);
	if (!value)
		return (0);
	old = *str;
	new = write_expanded(*str, i, len, value);
	if (!new)
		return (free(value), 0);
	*str = new;
	value_len = ft_strlen(value);
	free(value);
	free(old);
	return (value_len);
}

void	process_token_string(t_redir *token, t_shell *shell)
{
	int	i;
	int	in_squote;
	int	in_dquote;

	i = 0;
	in_squote = 0;
	in_dquote = 0;
	if (token->type != WORD)
		return ;
	while (token->target[i])
	{
		if (token->target[i] == '\'' && !in_dquote)
			in_squote = !in_squote;
		else if (token->target[i] == '"' && !in_squote)
			in_dquote = !in_dquote;
		else if (should_expand(token->target, i, in_squote))
		{
			i += expand_variable(&token->target, i, shell);
			continue ;
		}
		i++;
	}
	remove_quotes(&token->target);
}
