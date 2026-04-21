/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_echo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 15:02:58 by jslim             #+#    #+#             */
/*   Updated: 2026/02/13 15:02:59 by jslim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	n_flag(char *arg)
{
	int	i;

	if (!arg || ft_strlen(arg) < 2)
		return (0);
	if (arg[0] != '-' || arg[1] != 'n')
		return (0);
	i = 2;
	while (arg[i])
	{
		if (arg[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

int	builtin_echo(t_cmd *cmds)
{
	int	i;
	int	print_newline;

	i = 1;
	print_newline = 1;
	while (cmds->argv[i] && n_flag(cmds->argv[i]))
	{
		print_newline = 0;
		i++;
	}
	while (cmds->argv[i])
	{
		write(1, cmds->argv[i], ft_strlen(cmds->argv[i]));
		if (cmds->argv[i + 1])
			write(1, " ", 1);
		i++;
	}
	if (print_newline == 1)
		write(1, "\n", 1);
	return (0);
}
