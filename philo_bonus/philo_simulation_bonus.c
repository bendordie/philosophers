/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 03:05:31 by cshells           #+#    #+#             */
/*   Updated: 2021/06/20 19:07:24 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	eating(t_philo *philo)
{
	if (getTime() - philo->last_eat < philo->time_to_die
		- philo->time_to_sleep + 10)
		ft_usleep(5);
	sem_wait(philo->fork);
	sendMessage(philo, "had taken 1 fork");
	sendMessage(philo, "had taken 2 fork");
	sendMessage(philo, "is ready to eat");
	philo->eating = 1;
	philo->last_eat = getTime();
	ft_usleep(philo->time_to_eat);
	sem_post(philo->fork);
	philo->eating = 0;
	sendMessage(philo, GRN"had eaten"RESET);
	philo->eat_counter++;
	if (philo->num_of_eat_times
		&& philo->eat_counter == philo->num_of_eat_times)
		exit(4);
}

void	sleeping(t_philo *philo)
{
	sendMessage(philo, "had gone to sleep");
	ft_usleep(philo->time_to_sleep);
}

void	thinking(t_philo *philo)
{
	sendMessage(philo, "is thinking");
}

void	*simulation(void *data)
{
	t_philo		*philo;
	pthread_t	spectator;

	philo = (t_philo *)data;
	philo->start_time = getTime();
	philo->last_eat = getTime();
	pthread_create(&spectator, 0, spectating, philo);
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
