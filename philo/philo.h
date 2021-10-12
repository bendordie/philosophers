/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 17:01:07 by cshells           #+#    #+#             */
/*   Updated: 2021/06/20 18:08:47 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define RED        "\x1B[31m"
# define WTH        "\x1B[38m"
# define GRN        "\x1B[32m"
# define YEL        "\x1B[33m"
# define BLU        "\x1B[34m"
# define MAG        "\x1B[35m"
# define CYN        "\x1B[36m"
# define RESET      "\x1B[0m"

typedef pthread_mutex_t	t_mutex;

typedef struct s_philo {
	int			id;
	int			out;
	int			eating;
	int			left_fork;
	int			right_fork;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			num_of_eat_times;
	int			eat_counter;
	t_mutex		*msg;
	t_mutex		*l_fork;
	t_mutex		*r_fork;
	time_t		start_time;
	time_t		last_eat;
	pthread_t	*t;
}				t_philo;

typedef struct s_param
{
	int			num_of_philos;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			num_of_eat_times;
}				t_param;

typedef struct s_all
{
	t_philo		**philo;
	t_param		*param;
	pthread_t	*spectator;
}				t_all;

int				ft_atoi(const char *str);
void			ft_usleep(time_t delay);
void			sendMessage(t_philo *philo, char *status, int var);
void			*simulation(void *data);
void			*spectating(void *data);
void			takeFork(t_philo *philo, t_mutex *fork_1, t_mutex *fork_2);
time_t			getTime(void);
t_mutex			**initForks(int num_of_philos);
t_mutex			*initMessageMutex(void);
t_param			*initParams(int argc, char **argv);
t_philo			**initPhilos(t_param *param, t_mutex **forks, t_mutex *msg);

#endif
