/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:02:04 by arossign          #+#    #+#             */
/*   Updated: 2022/02/08 15:14:35 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	my_readline_bis(t_prompt *prompt, char *str, char *output, int isNull)
{
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, SIG_IGN);
	close(g_fds[0][READ_END]);
	close(g_fds[1][READ_END]);
	output = readline(str);
	write(g_fds[0][WRITE_END], output, ft_strlen(output));
	isNull = !output;
	write(g_fds[1][WRITE_END], &prompt->e_status, sizeof(int));
	free(output);
	close(g_fds[0][WRITE_END]);
	close(g_fds[1][WRITE_END]);
	exit(isNull);
}

/* Uses readline inside a child process and returns the read line */
char	*my_readline(t_prompt *prompt, char *str)
{
	pid_t	pid;
	int		isNull;
	char	*output;

	isNull = 0;
	output = NULL;
	if (!my_fd(prompt, g_fds[0], g_fds[1]))
		return (NULL);
	pid = fork();
	if (pid == -1)
		error(prompt, FORKERROR, NULL, 1);
	if (!pid)
		my_readline_bis(prompt, str, output, isNull);
	close(g_fds[0][WRITTE_END]);
	close(g_fds[1][WRITTE_END]);
	waitpid(pid, &isNull, 0);
	output = get_next_line(g_fds[0][READ_END]);
	if (!isNull && !output)
		output = ft_strdup("");
	read(g_fds[1][READ_END], &prompt->e_status, sizeof(int));
	close(g_fds[0]READ_END);
	close(g_fds[1][READ_END]);p
	return (output);
}
