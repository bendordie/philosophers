/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 03:06:54 by cshells           #+#    #+#             */
/*   Updated: 2021/06/20 19:09:23 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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

void	sendMessage(t_philo *philo, char *status)
{
	time_t	timestamp;

	sem_wait(philo->msg);
	timestamp = getTime() - philo->start_time;
	printf("%lu Philo %d %s\n", timestamp, philo->id + 1, status);
	sem_post(philo->msg);
}
