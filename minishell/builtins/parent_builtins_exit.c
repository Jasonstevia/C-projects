/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_builtins_exit.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslim <jslim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 15:05:01 by jslim             #+#    #+#             */
/*   Updated: 2026/02/20 12:33:25 by jslim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	is_digits(char *s)
{
	int	i;

	i = 0;
	if (!s[0])
		return (0);
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	is_overflow(char *s, int sign)
{
	unsigned long long	n;
	unsigned long long	lim;
	int					i;

	i = 0;
	n = 0;
	lim = 9223372036854775807ULL;
	if (sign == -1)
		lim = 9223372036854775808ULL;
	while (s[i])
	{
		if (n > lim / 10 || (n == lim / 10
				&& (unsigned long long)(s[i] - '0') > lim % 10))
			return (1);
		n = n * 10 + (s[i] - '0');
		i++;
	}
	return (0);
}

static int	get_code(char *s, int sign)
{
	unsigned long long	n;
	int					i;

	i = 0;
	n = 0;
	while (s[i])
	{
		n = (n * 10 + (s[i] - '0')) % 256;
		i++;
	}
	if (sign == -1 && n)
		return (256 - n);
	return (n);
}

int	builtin_exit(t_cmd *cmds)
{
	int	i;
	int	sign;
	int	start;

	i = 0;
	while (cmds->argv[i])
		i++;
	if (i > 2)
		return (ft_putstr_fd("minishell: exit: too many arguments\n", 2), 1);
	if (i == 1)
		return (g_exit_status);
	sign = 1;
	start = 0;
	if (cmds->argv[1][start] == '-' || cmds->argv[1][start] == '+')
		if (cmds->argv[1][start++] == '-')
			sign = -1;
	if (!is_digits(cmds->argv[1] + start)
		|| is_overflow(cmds->argv[1] + start, sign))
	{
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd(cmds->argv[1], 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		return (2);
	}
	return (get_code(cmds->argv[1] + start, sign));
}
