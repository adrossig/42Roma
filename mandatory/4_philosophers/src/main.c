/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:28:41 by adrossig          #+#    #+#             */
/*   Updated: 2021/11/04 11:28:42 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	ft_exit(char *str)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(str, 2);
	return (0);
}

int	check_deathp2(t_p *philo)
{
	pthread_mutex_lock(&philo->a.dead);
	if (philo->a.stop)
	{
		pthread_mutex_unlock(&philo->a.dead);
		return (1);
	}
	pthread_mutex_unlock(&philo->a.dead);
	return (0);
}

void	stop(t_p *philo)
{
	int	i;

	i = -1;
	while (!check_deathp2(philo))
		ft_usleep(1);
	while (++i < philo->a.total)
		pthread_join(philo->philo[i].thread_id, NULL);
	pthread_mutex_destroy(&philo->a.write_mutex);
	i = -1;
	while (++i < philo->a.total)
		pthread_mutex_destroy(&philo->philo[i].left_fork);
	if (philo->a.stop == 2)
		printf("Each philosopher ate %d time(s)\n", philo->a.m_eat);
	free(philo->philo);
}

int	main(int ac, char **av)
{
	t_p	philo;

	if (!(parse_args(ac, av, &philo)))
		return (ft_exit("Invalid arguments\n"));
	philo.philo = malloc(sizeof(t_philosophers) * philo.a.total);
	if (!philo.philo)
		return (ft_exit("Malloc return NULL\n"));
	if (!initialize(&philo) || !threading(&philo))
	{
		free(philo.philo);
		return (0);
	}
	stop(&philo);
}
