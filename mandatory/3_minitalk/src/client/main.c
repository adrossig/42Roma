/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrienrossignol <adrienrossignol@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:37:32 by adrossig          #+#    #+#             */
/*   Updated: 2022/01/21 14:19:29 by adrienrossi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_minitalk.h"

void	connection_terminate(pid_t server_pid)
{
	int	i;

	i = 8;
	while (i--)
	{
		usleep(50);
		kill(server_pid, SIGUSR2);
	}
	exit(0);
}

void	send_bit(char *s, pid_t pid)
{
	static int				i = 8;
	static unsigned char	c;
	static char				*str;
	static pid_t			server_pid;

	if (s)
	{
		str = s;
		server_pid = pid;
		c = *str;
	}
	if (!i)
	{
		i = 8;
		c = *(++str);
		if (!c)
			connection_terminate(server_pid);
	}
	if (c && c >> --i & 0x01)
		kill(server_pid, SIGUSR1);
	else if (c)
		kill(server_pid, SIGUSR2);
}

void	sig_handler(int sig, siginfo_t *siginfo, void *unused)
{
	static int	recv_bytes = 0;

	(void)siginfo;
	(void)unused;
	if (sig == SIGUSR1)
	{
		ft_putstr("\rReceive Acks : ");
		ft_putnbr(++recv_bytes);
	}
	send_bit(0, 0);
}

int	main(int argc, char **argv)
{
	struct sigaction	e;

	if (argc != 3 || !(100 <= ft_atoi(argv[1]) && ft_atoi(argv[1]) <= 99998))
	{
		ft_putstr("Usage : ./client [99 < Server PID < 99999] [Message]");
		return (1);
	}
	if (!ft_strlen(argv[2]))
		exit(0);
	e.sa_flags = SA_SIGINFO;
	e.sa_sigaction = sig_handler;
	sigaction(SIGUSR1, &e, 0);
	sigaction(SIGUSR2, &e, 0);
	ft_putstr("Send Bytes   : ");
	ft_putnbr(ft_strlen(argv[2]));
	ft_putchar('\n');
	send_bit(argv[2], ft_atoi(argv[1]));
	while (1)
		pause();
	return (0);
}