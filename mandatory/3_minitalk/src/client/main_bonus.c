/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrienrossignol <adrienrossignol@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:37:32 by adrossig          #+#    #+#             */
/*   Updated: 2022/01/21 15:39:29 by adrienrossi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_minitalk.h"

void	shift(char c, int pid)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & 0x80)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		c <<= 1;
		bit++;
		usleep(500);
	}
}

void	_send(char *message, int pid)
{
	int	i;

	i = 0;
	while (message[i])
	{
		shift(message[i], pid);
		i++;
	}
	shift('\0', pid);
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac > 1 && ac <= 3)
	{
		pid = ft_atoi(av[1]);
		if (pid == 0 || pid < 0)
		{
			ft_putstr(PID_ERR);
			exit(EXIT_FAILURE);
		}
		else
		{
			ft_putendl(SNDING_MSG);
			_send(av[2], pid);
			usleep(100);
			ft_putendl(SENT_SUCCESS);
			exit(EXIT_SUCCESS);
		}
	}
	ft_putstr(ERR_ARG);
}
