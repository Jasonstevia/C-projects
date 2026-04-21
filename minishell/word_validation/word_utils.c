/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghandou <rghandou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 16:11:24 by rghandou          #+#    #+#             */
/*   Updated: 2026/01/30 16:15:07 by rghandou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_env_value(char **env, char *name)
{
	int		i;
	int		len;

	if (!env || !name)
		return (NULL);
	len = ft_strlen(name);
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], name, len) == 0 && env[i][len] == '=')
			return (ft_strdup(env[i] + len + 1));
		i++;
	}
	return (NULL);
}

int	should_expand(char *str, int i, int in_squote)
{
	if (str[i] == '$' && !in_squote && str[i + 1]
		&& (ft_isalnum(str[i + 1]) || str[i + 1] == '_'
			|| str[i + 1] == '?'))
		return (1);
	return (0);
}

static void	copy_without_quotes(char *new, char *old, int *i, int *j)
{
	char	quote_char;

	quote_char = old[(*i)++];
	while (old[*i] && old[*i] != quote_char)
		new[(*j)++] = old[(*i)++];
	if (old[*i] == quote_char)
		(*i)++;
}

void	remove_quotes(char **str)
{
	char	*new;
	char	*old;
	int		i;
	int		j;

	if (!str || !*str)
		return ;
	old = *str;
	new = malloc(sizeof(char) * (ft_strlen(old) + 1));
	if (!new)
		return ;
	i = 0;
	j = 0;
	while (old[i])
	{
		if (old[i] == '\'' || old[i] == '"')
			copy_without_quotes(new, old, &i, &j);
		else
			new[j++] = old[i++];
	}
	new[j] = '\0';
	free(old);
	*str = new;
}
