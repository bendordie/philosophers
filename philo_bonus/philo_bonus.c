/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 23:02:24 by cshells           #+#    #+#             */
/*   Updated: 2021/06/24 02:01:59 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	killProcesses(pid_t *pid, int philos_num)
{
	int	i;

	i = 0;
	while (i < philos_num)
	{
		kill(pid[i], SIGTERM);
		i++;
	}
}

int	waitProcesses(void)
{
	int	status;

	waitpid(-1, &status, WUNTRACED);
	if (status == 1024)
		waitProcesses();
	else if (!status)
		return (0);
	return (1);
}

int	beginSimulation(t_all *all)
{
	int		i;
	pid_t	*pid;

	i = 0;
	pid = (pid_t *)malloc(sizeof(pid_t) * all->param->num_of_philos);
	while (i < all->param->num_of_philos)
	{
		pid[i] = fork();
		if (pid[i] == 0)
			simulation(all->philo[i]);
		i++;
	}
	if (!waitProcesses())
		killProcesses(pid, all->param->num_of_philos);
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	sem_t	*msg;
	sem_t	*fork;
	sem_t	*death;
	t_all	*all;

	all = (t_all *)malloc(sizeof(t_all));
	all->param = initParams(argc, argv);
	if (!all->param)
		return (0);
	all->philo = initPhilos(all->param);
	initSemaphores(all, &fork, &msg, &death);
	beginSimulation(all);
	return (0);
}
