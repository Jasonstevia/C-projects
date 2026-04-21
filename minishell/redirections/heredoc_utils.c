/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghandou <rghandou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 15:57:15 by rghandou          #+#    #+#             */
/*   Updated: 2026/02/05 11:06:22 by rghandou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*remove_delimiter_quotes(char *delimiter)
{
	char	*new;
	int		i;
	int		j;

	new = malloc(ft_strlen(delimiter) + 1);
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	while (delimiter[i])
	{
		if (delimiter[i] != '\'' && delimiter[i] != '"')
			new[j++] = delimiter[i];
		i++;
	}
	new[j] = '\0';
	return (new);
}

int	is_delimiter_quoted(char *delimiter)
{
	int	i;

	i = 0;
	while (delimiter[i])
	{
		if (delimiter[i] == '\'' || delimiter[i] == '"')
			return (1);
		i++;
	}
	return (0);
}

void	expand_heredoc_line(char **line, t_shell *shell)
{
	int		i;
	char	*str;

	if (!line || !*line)
		return ;
	str = *line;
	i = 0;
	while (str[i])
	{
		if (str[i] == '$' && str[i + 1]
			&& (ft_isalnum(str[i + 1]) || str[i + 1] == '_'
				|| str[i + 1] == '?'))
		{
			i += expand_variable(&str, i, shell);
			*line = str;
			continue ;
		}
		i++;
	}
}

int	init_heredoc_io(char **filename, int *fd)
{
	static int	i;
	char		*num;

	num = ft_itoa(i++);
	if (!num)
		return (1);
	*filename = ft_strjoin(".heredoc_tmp_", num);
	free(num);
	if (!*filename)
		return (1);
	*fd = open(*filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (*fd < 0)
		return (free(*filename), perror("heredoc"), 1);
	return (0);
}
