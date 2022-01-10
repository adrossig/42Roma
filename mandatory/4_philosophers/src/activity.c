/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:28:33 by adrossig          #+#    #+#             */
/*   Updated: 2021/11/04 11:28:34 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	write_status(char *str, t_philosophers *philo)
{
	long int	time;

	time = -1;
	time = actual_time() - philo->pa->start;
	if (time >= 0 && time <= 2147483647 && !check_deathp1(philo, 0))
	{
		printf("%ld ", time);
		printf("Philo %d %s", philo->id, str);
	}
}

void	sleep_think(t_philosophers *philo)
{
	pthread_mutex_lock(&philo->pa->write_mutex);
	write_status("is sleeping\n", philo);
	pthread_mutex_unlock(&philo->pa->write_mutex);
	ft_usleep(philo->pa->sleep);
	pthread_mutex_lock(&philo->pa->write_mutex);
	write_status("is thinking\n", philo);
	pthread_mutex_unlock(&philo->pa->write_mutex);
}

void	activity(t_philosophers *philo)
{
	pthread_mutex_lock(&philo->left_fork);
	pthread_mutex_lock(&philo->pa->write_mutex);
	write_status("has taken a fork\n", philo);
	pthread_mutex_unlock(&philo->pa->write_mutex);
	if (!philo->rigth_fork)
	{
		ft_usleep(philo->pa->die * 2);
		return ;
	}
	pthread_mutex_lock(philo->rigth_fork);
	pthread_mutex_lock(&philo->pa->write_mutex);
	write_status("has taken a fork\n", philo);
	pthread_mutex_unlock(&philo->pa->write_mutex);
	pthread_mutex_lock(&philo->pa->write_mutex);
	write_status("is eating\n", philo);
	pthread_mutex_lock(&philo->pa->time_eat);
	philo->ms_eat = actual_time();
	pthread_mutex_unlock(&philo->pa->time_eat);
	pthread_mutex_unlock(&philo->pa->write_mutex);
	ft_usleep(philo->pa->eat);
	pthread_mutex_unlock(philo->rigth_fork);
	pthread_mutex_unlock(&philo->left_fork);
	sleep_think(philo);
}
