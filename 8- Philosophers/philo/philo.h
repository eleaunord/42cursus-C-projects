/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:17:01 by sycourbi          #+#    #+#             */
/*   Updated: 2023/11/13 19:30:44 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <pthread.h>
# include <time.h>
# include <unistd.h>
# include <errno.h>
# include <sys/time.h>

typedef struct s_rules
{
	int	nbr_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	time_to_think;
}	t_rules;

typedef struct s_philo
{
	int				first_fork;
	int				second_fork;
	int				id;
	long			last_meal;
	int				reste_meal;
	t_rules			rules;
	struct s_data	*data;	
}	t_philo;

typedef struct s_data
{
	long long		t0;
	int				fini;
	int				someone_died;
	pthread_mutex_t	mutex_check;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write;
	pthread_t		*thread_ids;
	t_philo			*philo;
	t_rules			global_rules;
}	t_data;

/* init.c*/
int		ft_init(t_data *data, char **argv);
/*utils.c*/
long	get_time(long t0);
int		ft_atoi(const char *nptr);
int		check_philo_continue(t_data *data, t_philo *philo);
void	print_meal(t_philo *philo);
void	ft_usleep(t_data *data, long time_action);
/*life*/
void	*routine(void *perso);
/*check_death*/
void	check_philo_life(t_data *data);
int		check_arg(int argc, char **argv);

#endif