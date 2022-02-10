/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:44:18 by arossign          #+#    #+#             */
/*   Updated: 2022/02/10 10:05:36 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static pid_t get_pid(t_prompt *prompt)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		error(prompt, FORKERR, NULL, 1);
		return (-1);
	}
	if (!pid)
		exit(1);
	waitpid(pid, NULL, 0);
	return (pid - 1);
}

static t_prompt	init_vars(t_prompt prompt, char *str, char **av, char **env)
{
	char	*num;

	str = get_cwd(NULL, 0);
	prompt.env = set_env("PWD", str, prompt.env, 3);
	free(str);
	str = mini_getenv("SHLVL", env, 5);
	if (!str || ft_atoi(str) <= 0)
		num = ft_strdup("1");
	else
		num = ft_itoa(ft_atoi(str) + 1);
	free(str);
	prompt.env = set_env("SHLVL", num, prompt.env, 5);
	free(num);
	str = get_env("PATH", prompt.env, 4);
	if (!str)
		prompt.env = set_env("PATH", \
		"/usr/local/sbin:/usr/local/bin:/usr/bin:/bin", prompt.env, 4);
	free(str);
	str = get_env("_", prompt.env, 1);
	if (!str)
		prompt.env = set_env("_", av[0], prompt.env, 1);
	free(str);
	return (prompt);
}

static t_prompt	init_prompt(char **av, char **env)
{
	t_prompt	prompt;
	char		*str;

	str = NULL;
	prompt.cmds = NULL;
	prompt.env = ft_dup_matrix(env);
	prompt.e_status = 0;
	prompt.pid = get_pid(&prompt);
	prompt = init_vars(prompt, str, av, env);
	return (prompt);
}

int	main(int ac, char **av, char **env)
{
	char				*str;
	char				*output;
	t_prompt			prompt;

	prompt = init_prompt(av, env);
	while (av && ac)
	{
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, SIG_IGN);
		str = get_prompt(prompt);
		if (str)
			output = my_readline(&prompt, str);
		else
			output = my_readline(&prompt, "guest@minishell $ ");
		free(str);
		if (!check_args(output, &prompt))
			break ;
	}
	ft_free_matrix(&prompt.env);
	exit(prompt.e_status);
}
