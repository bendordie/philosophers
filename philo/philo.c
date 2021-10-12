/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 23:02:24 by cshells           #+#    #+#             */
/*   Updated: 2021/06/23 23:06:16 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	beginSimulation(t_all *all)
{
	int	i;

	i = 0;
	all->spectator = (pthread_t *)malloc(sizeof(pthread_t));
	while (i < all->param->num_of_philos)
	{
		pthread_create(all->philo[i]->t, 0, simulation, all->philo[i]);
		pthread_detach(*(all->philo[i]->t));
		i++;
	}
	pthread_create(all->spectator, 0, spectating, all);
	pthread_join(*(all->spectator), 0);
	pthread_detach(*(all->spectator));
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	t_all		*all;
	t_mutex		*msg;
	t_mutex		**forks;

	all = (t_all *)malloc(sizeof(t_all));
	all->param = initParams(argc, argv);
	if (!all->param)
		return (0);
	forks = initForks(all->param->num_of_philos);
	msg = initMessageMutex();
	all->philo = initPhilos(all->param, forks, msg);
	beginSimulation(all);
	return (0);
}
