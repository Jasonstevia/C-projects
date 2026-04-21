/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghandou <rghandou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:54:48 by rghandou          #+#    #+#             */
/*   Updated: 2026/01/22 10:23:14 by rghandou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_space(char c)
{
	return ((c >= 9 && c <= 14) || c == 32);
}

int	is_separator(char c)
{
	return (c == '|' || c == '>' || c == '<');
}

int	is_redirections(int type)
{
	return (type == R_IN || type == R_APPEND || type == R_OUT
		|| type == R_HEREDOC);
}
