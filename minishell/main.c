/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 15:06:49 by jslim             #+#    #+#             */
/*   Updated: 2026/02/13 15:06:51 by jslim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_exit_status = 0;

void	free_split(char	**str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

char	**copy_env(char **envp)
{
	int		i;
	int		j;
	char	**new_env;

	i = 0;
	j = 0;
	while (envp[i])
		i++;
	new_env = malloc (sizeof(char *) * (i + 1));
	while (j < i)
	{
		new_env[j] = ft_strdup(envp[j]);
		j++;
	}
	new_env[j] = NULL;
	return (new_env);
}

void	update_last_arg(t_shell *shell, t_cmd *cmds)
{
	int		i;
	t_cmd	*last;

	if (!cmds)
		return ;
	last = cmds;
	while (last->next)
		last = last->next;
	if (shell->last_arg)
		free(shell->last_arg);
	shell->last_arg = NULL;
	if (!last->argv || !last->argv[0])
		return ;
	i = 0;
	while (last->argv[i])
		i++;
	shell->last_arg = ft_strdup(last->argv[i - 1]);
	change_env_local(&shell->env, "_=", shell->last_arg);
}

static void	process_input_line(char *line, t_shell *shell)
{
	int	i;

	i = 0;
	while (line[i] && is_space(line[i]))
		i++;
	if (!line[i])
		return (free(line));
	add_history(line);
	execute(line, shell);
	free(line);
}

int	main(int argc, char **argv, char **envp)
{
	char	*line;
	t_shell	shell;

	(void)argc;
	(void)argv;
	shell.env = copy_env(envp);
	shell.cmds = NULL;
	shell.last_arg = NULL;
	set_signals_interactive();
	while (1)
	{
		line = readline("minishell$ ");
		if (!line)
		{
			ft_printf("exit\n");
			break ;
		}
		process_input_line(line, &shell);
	}
	cleanup_shell(&shell);
	return (0);
}
