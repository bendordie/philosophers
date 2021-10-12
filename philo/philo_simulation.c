/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 03:05:31 by cshells           #+#    #+#             */
/*   Updated: 2021/06/20 18:23:27 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philo *philo)
{
	if (philo->id % 2 == 0)
		takeFork(philo, philo->r_fork, philo->l_fork);
	else
		takeFork(philo, philo->l_fork, philo->r_fork);
	sendMessage(philo, "is ready to eat", 1);
	philo->eating = 1;
	ft_usleep(philo->time_to_eat);
	philo->eating = 0;
	philo->last_eat = getTime();
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	sendMessage(philo, GRN"had eaten"RESET, 1);
	philo->eat_counter++;
}

void	sleeping(t_philo *philo)
{
	sendMessage(philo, "had gone to sleep", 1);
	ft_usleep(philo->time_to_sleep);
}

void	thinking(t_philo *philo)
{
	sendMessage(philo, "had begun think", 1);
}

void	*simulation(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	philo->start_time = getTime();
	philo->last_eat = getTime();
	while (1)
	{
		eating(philo);
		if (philo->num_of_eat_times
			&& philo->eat_counter == philo->num_of_eat_times)
		{
			philo->out = 1;
			return (0);
		}
		sleeping(philo);
		thinking(philo);
	}
}
