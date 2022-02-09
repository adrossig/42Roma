/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:55:54 by arossign          #+#    #+#             */
/*   Updated: 2022/02/08 15:26:59 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL_H
# define FT_MINISHELL_H

// System libs
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <sys/wait.h>
# include <dirent.h>

// Local libs
# include "../libs/libft/includes/libft.h"

typedef struct s_prompt
{
	t_list	*cmds;
	char	**envp;
	pid_t	pid;
	int	e_status;
}		t_prompt;

typedef struct s_mini
{
	char	**full_cmd;
	char	*full_path;
	int	infile;
	int	outfile;
}		t_mini;

// Function

char	*my_readline(t_prompt *prompt, char *str);

/* Opens two sets of pipes and checks if they are opened correctly */
void	*my_fd(t_prompt *prompt, int fd[2], int auxfd[2]);

/* Splits command string into manageable matrix to store & exec commands */
void	*check_args(char *output, t_prompt *p);

char	**my_trim(char const *str, char *set);

char	**my_subsplit(char const *str, char *set);

/* Strtrim from all needed quotes in s1 */
char	*my_strtrim(char const *s1, int squote, int dquote);

/* Parses all necessary stuff for a command matrix */
t_list	*fill_nodes(t_prompt *prompt, char **args, int i);

/* Function to handle SIGINT signals for main process */
void	handle_sigint(int sig);

/* Function to handle SIGINT signals for child process */
void	handle_sigint_child(int sig);

/* Function to handle SIGQUIT signals for child process */
void	handle_sigquit(int sig);

void	*mini_perror(t_prompt *prompt, int err_type, char *param, int errno);

#endif
