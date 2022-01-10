/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:28:26 by adrossig          #+#    #+#             */
/*   Updated: 2021/11/04 11:28:27 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_args
{
	int				total;
	int				die;
	int				eat;
	int				sleep;
	int				m_eat;
	int				nbr_philo_finish;
	int				stop;
	long int		start;
	pthread_mutex_t	write_mutex;
	pthread_mutex_t	dead;
	pthread_mutex_t	time_eat;
	pthread_mutex_t	finish;

}				t_args;

typedef struct s_philosophers
{
	int				id;
	int				finish;
	long int		ms_eat;
	unsigned int	nbr_eat;
	pthread_t		thread_id;
	pthread_t		thread_death_id;
	pthread_mutex_t	*rigth_fork;
	pthread_mutex_t	left_fork;
	t_args			*pa;
}			t_philosophers;

typedef struct s_p
{
	t_args			a;
	t_philosophers	*philo;
}				t_p;

int			ft_exit(char *str);
int			check_deathp1(t_philosophers *philo, int i);
int			initialize(t_p *philo);
int			parse_args(int ac, char **av, t_p *philo);
int			threading(t_p *philo);
int			ft_strlen(char *str);
void		write_status(char *str, t_philosophers *philo);
void		activity(t_philosophers *philo);
void		ft_putstr_fd(char *s, int fd);
void		ft_usleep(long int time_in_ms);
long int	actual_time(void);

#endif
