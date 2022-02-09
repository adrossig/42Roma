/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:44:18 by arossign          #+#    #+#             */
/*   Updated: 2022/02/09 17:54:34 by arossign         ###   ########.fr       */
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

int main(int ac, char **av, char **env)
{
	char		*str;
	char		*output;
	t_prompt	prompt;

	//prompt = init(prompt, str, output, env);
	while (ac && av)
	{
		signal(SIGQUIT, SIG_IGN); // CTRL+D
		signal(SIGINT, SIG_IGN); // CTRL+\
		// send the params to an external function to be able to parse them
		// do an exit
	}
	return (0);
}
