/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:55:54 by arossign          #+#    #+#             */
/*   Updated: 2022/03/15 09:46:36 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// System libs
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <sys/wait.h>
# include <dirent.h>
# include <sys/ioctl.h>

// Local libs
# include "../libs/libft/includes/libft.h"
# include "colors.h"

// Local defines
# define READ_END 0
# define WRITE_END 1

typedef struct s_prompt
{
	t_list	*cmds;
	char	**env;
	pid_t	pid;
}		t_prompt;

typedef struct s_mini
{
	char	**full_cmd;
	char	*full_path;
	int		infile;
	int		outfile;
}		t_mini;

enum e_error
{
	QUOTE = 1,
	NDIR = 2,
	NPERM = 3,
	NCMD = 6,
	DUPERR = 7,
	FORKERR = 8,
	PIPERR = 9,
	PIPENDERR = 10,
	MEM = 11,
	IS_DIR = 12,
	NOT_DIR = 13,
};

// Function

/* Opens two sets of pipes and checks if they are opened correctly */
void	*my_fd(t_prompt *prompt, int fd[2], int auxfd[2]);

/* Splits command string into manageable matrix to store & exec commands */
void	*check_args(char *output, t_prompt *p);

char	**my_trim(char const *str, char *set);

char	**my_subsplit(char const *str, char *set);

/* Strtrim from all needed quotes in s1 */
char	*my_strtrim(char const *s1, int squote, int dquote);

/* Parses all necessary stuff for a command matrix */
t_list	*fill_nodes(char **args, int i);

/* Function to handle SIGINT signals for main process */
void	handle_sigint(int sig);

//void	*my_perror(t_prompt *prompt, int err_type, char *param, int errno);
void	*error(int err_type, char *param, int err);

/* Returns a colorized string used as prompt for readline */
char	*get_prompt(t_prompt prompt);

/* C implementation of the pwd shell command */
int		minishell_pwd(void);

/* C implementation of the echo shell command */
int		minishell_echo(t_list *cmd);

/* C implementation of the cd shell command */
int		minishell_cd(t_prompt *prompt);

/* C implementation of the export shell command */
int		minishell_export(t_prompt *prompt);

/* C implementation of the unset shell command */
int		minishell_unset(t_prompt *prompt);

/* C implementation of the exit shell command */
int		minishell_exit(t_list *cmd, int *is_exit);

/* Checks for errors and returns whether first arg is a directory */
DIR		*cd_error(char **str[2]);

/* Handles all builtin functions */
int		builtin(t_prompt *prompt, t_list *cmd, int *is_exit, int n);

/* Checks if the first element in full_cmd is a builtin */
int		is_builtin(t_mini *n);

/* Executes a custom command and saves output to string ending in \n */
void	exec_custom(char ***out, char *full, char *args, char **env);

/* Frees all elements in linked list nodes */
void	free_content(void *content);

/* Retrieves a string from standard input, expanding vars when needed */
int		get_hdc(char *str[2], char *aux[2]);

/* Prints a custom error message to standard error */
void	*minishell_perror(int err_type, char *param, int err);

/* Retrieves a string with malloc containing the value of an env var */
char	*minishell_getenv(char	*var, char **env, int n);

/* Sets a new environment variable */
char	**minishell_setenv(char *var, char *value, char **env, int n);

/* Returns a colorized string used as prompt for readline */
char	*minishell_getprompt(t_prompt prompt);

/* Expands environment variables in a string if not in quotes */
char	*expand_vars(char *str, int i, int quotes[2], t_prompt *prompt);

/* Expands "~" to home directory in a string if not in quotes */
char	*expand_path(char *str, int i, int quotes[2], char *var);

/* Tries to open proper file as outfile (> case) */
t_mini	*get_outfile1(t_mini *node, char **args, int *i);

/* Tries to open proper file as outfile (>> case) */
t_mini	*get_outfile2(t_mini *node, char **args, int *i);

/* Tries to open proper file as infile (< case) */
t_mini	*get_infile1(t_mini *node, char **args, int *i);

/* Tries to open read heredoc as infile (<< case) */
t_mini	*get_infile2(t_mini *node, char **args, int *i);

/* Executes a non-builtin command according to the info on our list */
void	*exec_cmd(t_prompt *prompt, t_list *cmd);

/* Checks if conditions are met to perform a fork */
void	*check_fork(t_prompt *prompt, t_list *cmd, int fd[2]);

/* Execute commands inside child process */
void	child_builtin(t_prompt *prompt, t_mini *n, int l, t_list *cmd);

/* Executes a custom command and saves output to string ending in \n */
void	exec_custom(char ***out, char *full, char *args, char **env);

/* Executes a non-builtin command according to the info on our list */
int		exec_builtin(t_prompt *prompt, int (*func)(t_prompt *));

/* Checks if a command is in the PATH variable and retrieves the full_path */
void	get_cmd(t_prompt *prompt, t_list *start, char **split_path, char *path);

/* Opens a file to a file descriptor with the adequate open flags */
int		get_fd(int oldfd, char *path, int flags[2]);

int		env(char *av, char **env, int i[2]);
int		ft_atoi2(const char *nptr, long *nbr);

void    rl_replace_line(const char *text, int clear_undo);

#endif
