/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:28:37 by adrossig          #+#    #+#             */
/*   Updated: 2021/11/04 11:28:38 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	init_mutex(t_p *philo)
{
	pthread_mutex_init(&philo->a.write_mutex, NULL);
	pthread_mutex_init(&philo->a.dead, NULL);
	pthread_mutex_init(&philo->a.time_eat, NULL);
	pthread_mutex_init(&philo->a.finish, NULL);
}

int	initialize(t_p *philo)
{
	int	i;

	i = 0;
	philo->a.start = actual_time();
	philo->a.stop = 0;
	philo->a.nbr_philo_finish = 0;
	init_mutex(philo);
	while (i < philo->a.total)
	{
		philo->philo[i].id = i + 1;
		philo->philo[i].ms_eat = philo->a.start;
		philo->philo[i].nbr_eat = 0;
		philo->philo[i].finish = 0;
		philo->philo[i].rigth_fork = NULL;
		pthread_mutex_init(&philo->philo[i].left_fork, NULL);
		if (philo->a.total == 1)
			return (1);
		if (i == philo->a.total - 1)
			philo->philo[i].rigth_fork = &philo->philo[0].left_fork;
		else
			philo->philo[i].rigth_fork = &philo->philo[i + 1].left_fork;
		i++;
	}
	return (1);
}
