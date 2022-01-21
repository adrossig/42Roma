/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrienrossignol <adrienrossignol@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:08:52 by adrossig          #+#    #+#             */
/*   Updated: 2022/01/21 14:16:54 by adrienrossi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_minitalk.h"

void	my_handler(int sig, siginfo_t *siginfo, void *unused)
{
	static unsigned char c = 0x00;
	static int	cnt = 0;
	static pid_t	client_pid;

	(void)unused;
	if (!client_pid)
		client_pid = siginfo->si_pid;
	c |= (sig == SIGUSR1);
	if (++cnt == 8)
	{
		cnt = 0;
		if (c == 0x00)
		{
			client_pid = 0;
			return ;
		}
		ft_putchar(c);
		c = 0x00;
		kill(client_pid, SIGUSR1);
	}
	else
	{
		c <<= 1;
		kill(client_pid, SIGUSR2);
	}
}

int	main(void)
{
	struct sigaction e;
	write(1, "Server started!\nPID: ", 21);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	e.sa_flags = SA_SIGINFO;
	e.sa_sigaction = my_handler;
	sigaction(SIGUSR1, &e, 0);
	sigaction(SIGUSR2, &e, 0);
	while (1)
		pause();
	return (0);
}
