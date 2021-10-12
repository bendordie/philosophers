/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 03:04:25 by cshells           #+#    #+#             */
/*   Updated: 2021/06/23 23:05:48 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_mutex	*initMessageMutex(void)
{
	t_mutex	*msg;

	msg = (t_mutex *)malloc(sizeof(t_mutex));
	pthread_mutex_init(msg, 0);
	return (msg);
}

t_mutex	**initForks(int num_of_philos)
{
	int		i;
	t_mutex	**forks;

	i = 0;
	forks = (t_mutex **)malloc(sizeof(t_mutex *) * num_of_philos);
	if (!forks)
		return (0);
	while (i < num_of_philos)
	{
		forks[i] = (t_mutex *)malloc(sizeof(t_mutex));
		pthread_mutex_init(forks[i], 0);
		i++;
	}
	return (forks);
}

void	initializationCycle(t_philo ***philo, t_param *param,
		t_mutex **forks, t_mutex *msg)
{
	int	i;

	i = 0;
	while (i < param->num_of_philos)
	{
		(*philo)[i] = (t_philo *)malloc(sizeof(t_philo));
		(*philo)[i]->t = (pthread_t *)malloc(sizeof(pthread_t));
		(*philo)[i]->id = i;
		(*philo)[i]->eating = 0;
		(*philo)[i]->l_fork = forks[i];
		if (i == 0)
			(*philo)[i]->r_fork = forks[param->num_of_philos - 1];
		else
			(*philo)[i]->r_fork = forks[i - 1];
		(*philo)[i]->msg = msg;
		(*philo)[i]->start_time = 0;
		(*philo)[i]->out = 0;
		(*philo)[i]->time_to_die = param->time_to_die;
		(*philo)[i]->time_to_eat = param->time_to_eat;
		(*philo)[i]->time_to_sleep = param->time_to_sleep;
		(*philo)[i]->num_of_eat_times = param->num_of_eat_times;
		(*philo)[i]->eat_counter = 0;
		i++;
	}
}

t_philo	**initPhilos(t_param *param, t_mutex **forks, t_mutex *msg)
{
	t_philo	**philo;

	philo = (t_philo **)malloc(sizeof(t_philo *) * (param->num_of_philos + 1));
	initializationCycle(&philo, param, forks, msg);
	return (philo);
}
