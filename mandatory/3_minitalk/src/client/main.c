/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:37:32 by adrossig          #+#    #+#             */
/*   Updated: 2021/05/29 11:06:46 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_minitalk.h"

void	decimal_conversion(char ascii, int power, int pid)
{
	if (power > 0)
		decimal_conversion(ascii / 2, power - 1, pid);
	if ((ascii % 2) == 1)
	{
		if (kill(pid, SIGUSR1) == -1)
			error("Error signal!\n");
	}
	else
	{
		if (kill(pid, SIGUSR2) == -1)
			error("Error signal!\n");
	}
	usleep(100);
}

int	send_message(int pid, char *msg)
{
	int	i;

	i = 0;
	while (msg[i] != '\0')
	{
		decimal_conversion(msg[i], 7, pid);
		i++;
	}
	return (0);
}

void	my_handler(int signum)
{
	if (signum == SIGUSR1)
	{
		ft_putstr("Received SIGUSR1!\n");
	}
}

int	main(int ac, char **av)
{
	signal(SIGUSR2, my_handler);
	if (ac != 3)
	{
		ft_putstr("Usage : ./client [PID] [MESSAGE]\n");
		return (0);
	}
	send_message(atoi(av[1]), av[2]);
	while (1)
		pause();
	return (0);
}
