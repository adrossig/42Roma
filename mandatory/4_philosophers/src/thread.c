/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:28:48 by adrossig          #+#    #+#             */
/*   Updated: 2021/11/04 11:28:49 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*is_dead(void *data)
{
	t_philosophers	*philo;

	philo = (t_philosophers *)data;
	ft_usleep(philo->pa->die + 1);
	pthread_mutex_lock(&philo->pa->time_eat);
	pthread_mutex_lock(&philo->pa->finish);
	if (!check_deathp1(philo, 0) && !philo->finish && \
		((actual_time() - philo->ms_eat) >= (long)(philo->pa->die)))
	{
		pthread_mutex_unlock(&philo->pa->time_eat);
		pthread_mutex_unlock(&philo->pa->finish);
		pthread_mutex_unlock(&philo->pa->write_mutex);
		write_status("died\n", philo);
		pthread_mutex_unlock(&philo->pa->write_mutex);
		check_deathp1(philo, 1);
	}
	pthread_mutex_unlock(&philo->pa->time_eat);
	pthread_mutex_unlock(&philo->pa->finish);
	return (NULL);
}

void	*thread(void *data)
{
	t_philosophers	*philo;

	philo = (t_philosophers *)data;
	if (philo->id % 2)
		ft_usleep(philo->pa->eat / 10);
	while (!check_deathp1(philo, 0))
	{
		pthread_create(&philo->thread_death_id, NULL, is_dead, data);
		activity(philo);
		pthread_detach(philo->thread_death_id);
		if ((int)++philo->nbr_eat == philo->pa->m_eat)
		{
			pthread_mutex_lock(&philo->pa->finish);
			philo->finish = 1;
			philo->pa->nbr_philo_finish++;
			if (philo->pa->nbr_philo_finish == philo->pa->total)
			{
				pthread_mutex_unlock(&philo->pa->finish);
				check_deathp1(philo, 2);
			}
			pthread_mutex_unlock(&philo->pa->finish);
			return (NULL);
		}
	}
	return (NULL);
}

int	threading(t_p *philo)
{
	int	i;

	i = -1;
	while (++i < philo->a.total)
	{
		philo->philo[i].pa = &philo->a;
		if (pthread_create(&philo->philo[i].thread_id, NULL, thread, \
			&philo->philo[i]) != 0)
			return (ft_exit("Pthread did not return 0\n"));
	}
	return (1);
}
