/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:08:52 by adrossig          #+#    #+#             */
/*   Updated: 2021/05/29 10:56:23 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_minitalk.h"

void	my_handler(int signum)
{
	static int	ascii = 0;
	static int	power = 0;

	if (signum == SIGUSR1)
		ascii += 1 << (7 - power);
	power += 1;
	if (power == 8)
	{
		write(1, &ascii, 1);
		power = 0;
		ascii = 0;
	}
}

int	main(void)
{
	write(1, "Server started!\nPID: ", 21);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	signal(SIGUSR1, my_handler);
	signal(SIGUSR2, my_handler);
	while (1)
		pause();
}
