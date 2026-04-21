/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_pwd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 15:03:27 by jslim             #+#    #+#             */
/*   Updated: 2026/02/13 15:03:29 by jslim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	builtin_pwd(void)
{
	char	cwd[1024];

	if (!getcwd (cwd, sizeof(cwd)))
		return (perror("getcwd() error"), 1);
	write(1, cwd, ft_strlen(cwd));
	write(1, "\n", 1);
	return (0);
}
