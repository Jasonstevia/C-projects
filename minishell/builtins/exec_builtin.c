/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslim <jslim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 15:03:57 by jslim             #+#    #+#             */
/*   Updated: 2026/04/07 12:56:38 by jslim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	exit_paren_syntax(t_cmd *cmds)
{
	size_t	len;

	if (cmds->next || ft_strcmp(cmds->argv[0], "exit") || !cmds->argv[1])
		return (0);
	if (!ft_strchr(cmds->argv[1], '(') && !ft_strchr(cmds->argv[1], ')'))
		return (0);
	ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
	len = ft_strlen(cmds->argv[1]);
	if (!ft_strcmp(cmds->argv[1], "(") && cmds->argv[2])
	{
		len = ft_strlen(cmds->argv[2]);
		if (len && cmds->argv[2][len - 1] == ')')
			write(2, cmds->argv[2], len - 1);
		else
			ft_putstr_fd(cmds->argv[2], 2);
	}
	else if (cmds->argv[1][0] == '('
		&& len > 2 && cmds->argv[1][len - 1] == ')')
		write(2, cmds->argv[1] + 1, len - 2);
	else
		ft_putstr_fd(cmds->argv[1], 2);
	ft_putstr_fd("'\n", 2);
	return (1);
}

int	exec_parent_builtin(t_cmd *cmds, t_shell *shell)
{
	if (!cmds->argv[0])
		return (-1);
	if (ft_strchr(cmds->argv[0], '=') && !cmds->argv[1])
		return (builtin_export(cmds, shell));
	if (!ft_strcmp(cmds->argv[0], "cd"))
	{
		if (cmds->argv[1] && cmds->argv[2])
			return (ft_putstr_fd("minishell: cd: too many arguments\n", 2), 1);
		return (builtin_cd(cmds, shell));
	}
	else if (!ft_strcmp(cmds->argv[0], "export"))
		return (builtin_export(cmds, shell));
	else if (!ft_strcmp(cmds->argv[0], "unset"))
		return (builtin_unset(cmds, shell));
	else if (!ft_strcmp(cmds->argv[0], "exit"))
		return (builtin_exit(cmds));
	return (-1);
}

int	exec_builtin(t_cmd *cmds, t_shell *shell)
{
	if (!ft_strcmp(cmds->argv[0], "echo"))
		return (builtin_echo(cmds));
	else if (!ft_strcmp(cmds->argv[0], "env"))
		return (builtin_env(shell));
	else if (!ft_strcmp(cmds->argv[0], "pwd"))
		return (builtin_pwd());
	return (-1);
}
