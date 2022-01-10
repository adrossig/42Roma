/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:28:56 by adrossig          #+#    #+#             */
/*   Updated: 2021/11/04 11:28:57 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	check_deathp1(t_philosophers *philo, int i)
{
	pthread_mutex_lock(&philo->pa->dead);
	if (i)
		philo->pa->stop = i;
	if (philo->pa->stop)
	{
		pthread_mutex_unlock(&philo->pa->dead);
		return (1);
	}
	pthread_mutex_unlock(&philo->pa->dead);
	return (0);
}

long int	actual_time(void)
{
	long int		time;
	struct timeval	current_time;

	time = 0;
	if (gettimeofday(&current_time, NULL) == -1)
		ft_exit("Gettimeofday returned -1\n");
	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (time);
}

void	ft_usleep(long int time_in_ms)
{
	long int	start_time;

	start_time = 0;
	start_time = actual_time();
	while ((actual_time() - start_time) < time_in_ms)
		usleep(time_in_ms / 10);
}
