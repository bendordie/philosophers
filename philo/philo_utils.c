/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 03:06:54 by cshells           #+#    #+#             */
/*   Updated: 2021/06/23 23:04:00 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

time_t	getTime(void)
{
	struct timeval	time;

	gettimeofday(&time, 0);
	return ((time_t)(time.tv_sec * 1000 + time.tv_usec / 1000));
}

void	ft_usleep(time_t delay)
{
	time_t	start;

	start = getTime();
	while (getTime() - start < delay)
		usleep(10);
}

void	sendMessage(t_philo *philo, char *status, int var)
{
	time_t	timestamp;

	pthread_mutex_lock(philo->msg);
	timestamp = getTime() - philo->start_time;
	printf("%lu Philo %d %s\n", timestamp, philo->id + 1, status);
	if (var)
		pthread_mutex_unlock(philo->msg);
}

void	takeFork(t_philo *philo, t_mutex *fork_1, t_mutex *fork_2)
{
	if (getTime() - philo->last_eat < philo->time_to_die
		- philo->time_to_sleep + 10)
		ft_usleep(5);
	pthread_mutex_lock(fork_1);
	sendMessage(philo, "had taken 1 fork", 1);
	pthread_mutex_lock(fork_2);
	sendMessage(philo, "had taken 2 fork", 1);
}
