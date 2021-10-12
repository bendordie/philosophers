/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_spectator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 03:02:06 by cshells           #+#    #+#             */
/*   Updated: 2021/06/24 02:02:28 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*spectating(void *data)
{
	time_t	diff;
	t_philo	*philo;

	philo = (t_philo *)data;
	while (1)
	{
		diff = getTime() - philo->last_eat;
		if (diff > philo->time_to_die)
		{
			sem_wait(philo->death);
			sendMessage(philo, RED"had died"RESET);
			exit(0);
		}
	}
}
