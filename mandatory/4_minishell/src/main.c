/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:44:18 by arossign          #+#    #+#             */
/*   Updated: 2022/03/14 10:44:17 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

extern int	g_status;

/**
 * A function that forks a child process and waits for it to finish.
 *
 * @param prompt The prompt to use when printing messages.
 *
 * @returns The pid of the child process.
**/
static void	get_pid(t_prompt *prompt)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		error(FORKERR, NULL, 1);
		ft_free_matrix(&prompt->env);
		exit(1);
	}
	if (!pid)
	{
		ft_free_matrix(&prompt->env);
		exit(1);
	}
	waitpid(pid, NULL, 0);
	prompt->pid = pid - 1;
}

/**
 * Initializes the prompt.
 *
 * @param prompt The prompt to initialize.
 * @param str The current working directory.
 * @param av The arguments to the program.
 * @param env The environment variables.
 *
 * @returns The initialized prompt.
**/
static t_prompt	init_vars(t_prompt prompt, char *str, char **av)
{
	char	*num;

	str = getcwd(NULL, 0);
	prompt.env = minishell_setenv("PWD", str, prompt.env, 3);
	free(str);
	str = minishell_getenv("SHLVL", prompt.env, 5);
	if (!str || ft_atoi(str) <= 0)
		num = ft_strdup("1");
	else
		num = ft_itoa(ft_atoi(str) + 1);
	free(str);
	prompt.env = minishell_setenv("SHLVL", num, prompt.env, 5);
	free(num);
	str = minishell_getenv("PATH", prompt.env, 4);
	if (!str)
		prompt.env = minishell_setenv("PATH", \
		"/usr/local/sbin:/usr/local/bin:/usr/bin:/bin", prompt.env, 4);
	free(str);
	str = minishell_getenv("_", prompt.env, 1);
	if (!str)
		prompt.env = minishell_setenv("_", av[0], prompt.env, 1);
	free(str);
	return (prompt);
}

/**
 * Initializes the prompt struct.
 *
 * @param av The arguments passed to the program.
 * @param env The environment variables.
 *
 * @returns The prompt struct.
**/
static t_prompt	init_prompt(char **av, char **env)
{
	t_prompt	prompt;
	char		*str;

	str = NULL;
	prompt.cmds = NULL;
	prompt.env = ft_dup_matrix(env);
	g_status = 0;
	get_pid(&prompt);
	prompt = init_vars(prompt, str, av);
	return (prompt);
}

/**
 * The main function of the minishell.
 *
 * @param ac The number of arguments.
 * @param av The arguments.
 * @param env The environment.
 *
 * @returns The exit status of the program.
 */
int	main(int ac, char **av, char **env)
{
	char				*str;
	char				*out;
	t_prompt			prompt;

	prompt = init_prompt(av, env);
	while (av && ac)
	{
		signal(SIGINT, handle_sigint);
		signal(SIGQUIT, SIG_IGN);
		str = get_prompt(prompt);
		if (str)
			out = readline(str);
		else
			out = readline("guest@minishell $ ");
		free(str);
		if (!check_args(out, &prompt))
			break ;
	}
	exit(g_status);
}
