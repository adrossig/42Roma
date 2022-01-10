/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:28:44 by adrossig          #+#    #+#             */
/*   Updated: 2021/11/04 11:28:45 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	ft_atoi(const char *str)
{
	int		i;
	long	sum;

	i = -1;
	sum = 0;
	while (str[++i])
		sum = (sum * 10) + (str[i] - 48);
	return (sum);
}

int	numeric(char **av, int i, int j)
{
	while (av[j])
	{
		while (av[j][i])
		{
			if (av[j][i] < '0' || av[j][i] > '9' || ft_strlen(av[j]) > 10)
				return (0);
			i++;
		}
		i = 0;
		j++;
	}
	return (1);
}

int	parse_args(int ac, char **av, t_p *philo)
{
	if ((ac == 5 || ac == 6) && numeric(av, 0, 1))
	{
		philo->a.total = ft_atoi(av[1]);
		philo->a.die = ft_atoi(av[2]);
		philo->a.eat = ft_atoi(av[3]);
		philo->a.sleep = ft_atoi(av[4]);
		philo->a.m_eat = -1;
		if (ac == 6)
			philo->a.m_eat = ft_atoi(av[5]);
		if (philo->a.total <= 0 || philo->a.die <= 0 || philo->a.eat <= 0 \
			|| philo->a.sleep <= 0)
			return (0);
		return (1);
	}
	return (0);
}
