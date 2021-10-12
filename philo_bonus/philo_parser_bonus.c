/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 01:54:50 by cshells           #+#    #+#             */
/*   Updated: 2021/06/20 19:04:55 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	parseArgs(t_param *param, int argc, char **argv)
{
	param->num_of_philos = ft_atoi(argv[1]);
	if (!param->num_of_philos)
	{
		write(1, "Error: Number of philosophers must be nonzero\n", 47);
		return (1);
	}
	param->time_to_die = ft_atoi(argv[2]);
	param->time_to_eat = ft_atoi(argv[3]);
	param->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		param->num_of_eat_times = ft_atoi(argv[5]);
	else
		param->num_of_eat_times = 0;
	if (param->num_of_philos > 200)
	{
		write(1, "Error: Too many philosophers (> 200)\n", 38);
		return (1);
	}
	if (param->time_to_die < 60 || param->time_to_eat < 60
		|| param->time_to_sleep < 60)
	{
		write(1, "Error: Time delay is less than 60 ms\n", 38);
		return (1);
	}
	return (0);
}

int	stringIsDigit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	checkNonDigitArgs(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!stringIsDigit(argv[i]))
		{
			printf("Error: Argument '%s' has invalid character\n", argv[i]);
			return (1);
		}
		i++;
	}
	return (0);
}

t_param	*initParams(int argc, char **argv)
{
	t_param	*param;

	param = (t_param *)malloc(sizeof(t_param));
	if (argc < 5 || argc > 6)
	{
		printf("Error: Wrong argument number: %d (needs 4 or 5)\n", argc - 1);
		return (0);
	}
	if (checkNonDigitArgs(argv))
		return (0);
	if (parseArgs(param, argc, argv))
		return (0);
	return (param);
}
