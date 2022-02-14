/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 10:18:29 by arossign          #+#    #+#             */
/*   Updated: 2022/02/11 22:47:22 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

extern int	g_fds[2][2];

void	handle_sigint(int sig)
{

	int	err;

	if (sig == SIGINT)
	{
		err = 130;
		write(1, "\n", 1);
		close(g_fds[0][READ_END]);
		close(g_fds[0][WRITE_END]);
		close(g_fds[1][READ_END]);
		write(g_fds[1][WRITE_END], &err, sizeof(int));
		close(g_fds[1][WRITE_END]);
		exit(0);
	}
}

void	handle_sigint_child(int sig)
{
	if (sig == SIGINT)
		write(1, "\n", 1);
}

void	handle_sigquit(int sig)
{
	if (sig == SIGQUIT)
		write(2, "Quit: 3\n", 8);
}
