/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 03:04:25 by cshells           #+#    #+#             */
/*   Updated: 2021/06/24 02:04:57 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	initSemaphores(t_all *all, sem_t **fork, sem_t **msg, sem_t **death)
{
	int	i;

	i = 0;
	sem_unlink("fork");
	sem_unlink("msg");
	sem_unlink("death");
	*fork = sem_open("fork", O_CREAT | O_EXCL, 0755,
			all->param->num_of_philos / 2);
	*msg = sem_open("msg", O_CREAT | O_EXCL, 0755, 1);
	*death = sem_open("death", O_CREAT | O_EXCL, 0755, 1);
	while (i < all->param->num_of_philos)
	{
		all->philo[i]->msg = *msg;
		all->philo[i]->death = *death;
		all->philo[i]->fork = *fork;
		i++;
	}
}

t_philo	**initPhilos(t_param *param)
{
	int		i;
	t_philo	**philo;

	i = -1;
	philo = (t_philo **)malloc(sizeof(t_philo *) * (param->num_of_philos + 1));
	while (++i < param->num_of_philos)
	{
		philo[i] = (t_philo *)malloc(sizeof(t_philo));
		philo[i]->t = (pthread_t *)malloc(sizeof(pthread_t));
		philo[i]->id = i;
		philo[i]->start_time = 0;
		philo[i]->out = 0;
		philo[i]->time_to_die = param->time_to_die;
		philo[i]->time_to_eat = param->time_to_eat;
		philo[i]->time_to_sleep = param->time_to_sleep;
		philo[i]->num_of_eat_times = param->num_of_eat_times;
		philo[i]->eat_counter = 0;
	}
	return (philo);
}
