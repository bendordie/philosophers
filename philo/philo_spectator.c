/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_spectator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 03:02:06 by cshells           #+#    #+#             */
/*   Updated: 2021/06/20 18:28:34 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	spectating_cycle(t_all *all, int *num_wellfed)
{
	int		i;
	time_t	diff;

	i = 0;
	while (i < all->param->num_of_philos)
	{
		if (!all->philo[i]->out && !all->philo[i]->eating)
		{
			diff = getTime() - all->philo[i]->last_eat;
			if (diff > all->philo[i]->time_to_die)
			{
				sendMessage(all->philo[i], RED"had died"RESET, 0);
				return (1);
			}
		}
		if (all->param->num_of_eat_times
			&& all->philo[i]->eat_counter == all->param->num_of_eat_times)
			(*num_wellfed)++;
		i++;
	}
	return (0);
}

void	*spectating(void *data)
{
	int		num_wellfed;
	int		res;
	t_all	*all;

	all = (t_all *)data;
	num_wellfed = 0;
	while (1)
	{
		res = spectating_cycle(all, &num_wellfed);
		if (res)
			return (0);
		if (all->param->num_of_eat_times
			&& num_wellfed == all->param->num_of_philos)
			return (0);
		else
			num_wellfed = 0;
	}
}
