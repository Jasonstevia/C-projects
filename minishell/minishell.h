/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslim <jslim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 15:23:47 by jslim             #+#    #+#             */
/*   Updated: 2026/02/24 11:58:47 by jslim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "ft_printf/libft/libft.h"
# include "ft_printf/ft_printf.h"

extern int	g_exit_status;

typedef enum e_redirtype
{
	R_IN,
	R_OUT,
	R_APPEND,
	R_HEREDOC,
	WORD,
	PIPE
}	t_redirtype;

typedef struct s_redir
{
	t_redirtype		type;
	char			*target;
	struct s_redir	*next;
}	t_redir;

typedef struct s_cmd
{
	char			**argv;
	t_redir			*redirs;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_shell
{
	char	**env;
	t_cmd	*cmds;
	char	*last_arg;
}	t_shell;

int				builtin_echo(t_cmd *cmds);
int				builtin_env(t_shell *shell);
int				builtin_export_view(t_shell *shell);
int				builtin_pwd(void);
int				builtin_exit(t_cmd *cmds);
int				builtin_cd(t_cmd *cmds, t_shell *shell);
int				builtin_export(t_cmd *cmds, t_shell *shell);
int				builtin_unset(t_cmd *cmds, t_shell *shell);
int				exec_parent_builtin(t_cmd *cmds, t_shell *shell);
int				exec_builtin(t_cmd *cmds, t_shell *shell);
int				exit_paren_syntax(t_cmd *cmds);
int				find_env_index_local(char *arg, char **env);
char			**env_append_local(char **env, char *newline);
void			change_env_local(char ***env, char *key, char *value);

int				redirections(t_redir *r);
int				redir_heredoc(t_redir *r, t_shell *shell);
void			token_add_back(t_redir **heap, t_redir *new_node);
t_redir			*token_new(char *content, t_redirtype type);
t_redir			*ft_tokenize(char *str);
void			process_token_string(t_redir *token, t_shell *shell);
int				expand_variable(char **str, int i, t_shell *shell);
int				should_expand(char *str, int i, int in_squote);
void			update_last_arg(t_shell *shell, t_cmd *cmds);
void			execute(char *line, t_shell *shell);
int				is_space(char c);
int				is_redirections(int type);
int				ft_strcmp(const char *s1, const char *s2);

void			print_cmd_table(t_cmd *head);
int				is_separator(char c);
int				syntax_check(t_redir *tokens);

void			cmd_add_back(t_cmd **heap, t_cmd *new_node);
int				count_args(t_redir *token);
void			build_command_table(t_cmd **heap, t_redir *token);
void			remove_quotes(char **str);

char			*get_env_value(char **env, char *name);
void			resolve_path(char **cmd_name, t_shell shell);

void			free_command_table(t_cmd *cmd_table);
void			free_tokenize(t_redir *token);
void			cleanup_shell_child(t_shell *shell);
void			cleanup_shell(t_shell *shell);

void			process_heredoc(t_redir *token, t_shell *shell);
int				process_all_heredocs(t_cmd *cmds, t_shell *shell);
char			*remove_delimiter_quotes(char *delimiter);
int				is_delimiter_quoted(char *delimiter);
void			expand_heredoc_line(char **line, t_shell *shell);
int				init_heredoc_io(char **filename, int *fd);
char			**split_env_path(t_shell shell);
int				parse_input(char *input, t_shell *shell);
int				execute_cmds(t_cmd *cmds, t_shell *shell);
int				get_exit_status(pid_t pid[], int N);
int				exec_pipeline(t_cmd *cmds, t_shell *shell);
int				cmd_count(t_cmd *cmds);
void			free_split(char	**str);
void			trim_empty_argv(char **argv);
void			set_signals_interactive(void);
void			set_signals_parent_waiting(void);
void			set_signals_child_exec(void);

#endif
