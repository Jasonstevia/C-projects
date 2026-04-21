/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 15:03:14 by jslim             #+#    #+#             */
/*   Updated: 2026/02/13 15:03:16 by jslim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	builtin_env(t_shell *shell)
{
	int	i;
	int	j;

	i = 0;
	while (shell->env[i])
	{
		j = 0;
		while (shell->env[i][j])
		{
			if (shell->env[i][j] == '=')
			{
				write(1, shell->env[i], ft_strlen(shell->env[i]));
				write(1, "\n", 1);
				break ;
			}
			j++;
		}
		i++;
	}
	return (0);
}
