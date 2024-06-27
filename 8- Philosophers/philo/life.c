/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:57:48 by sycourbi          #+#    #+#             */
/*   Updated: 2023/11/14 15:43:21 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action_and_wait(t_philo *philo, char *action, int time_action)
{
	pthread_mutex_lock(&philo->data->write);
	if (check_philo_continue(philo->data, philo) != -1
		&& philo->rules.nbr_philo > 1)
	{
		printf(action, get_time(philo->data->t0), philo->id);
	}
	pthread_mutex_unlock(&philo->data->write);
	ft_usleep(philo->data, time_action);
}

void	eating(t_philo *philo, int first_fork, int second_fork)
{
	if (!pthread_mutex_lock(&philo->data->forks[first_fork])
		&& !pthread_mutex_lock(&philo->data->forks[second_fork]))
	{
		pthread_mutex_lock(&philo->data->mutex_check);
		philo->last_meal = get_time(philo->data->t0);
		pthread_mutex_unlock(&philo->data->mutex_check);
		pthread_mutex_lock(&philo->data->write);
		print_meal(philo);
		pthread_mutex_unlock(&philo->data->write);
		ft_usleep(philo->data, philo->rules.time_to_eat);
		pthread_mutex_lock(&philo->data->mutex_check);
		philo->reste_meal--;
		if (philo->reste_meal == 0)
			philo->data->fini--;
		pthread_mutex_unlock(&philo->data->mutex_check);
	}
	pthread_mutex_unlock(&philo->data->forks[first_fork]);
	pthread_mutex_unlock(&philo->data->forks[second_fork]);
}

void	init_eating_proces(t_philo *philo)
{
	int	first_fork;
	int	second_fork;

	first_fork = 0;
	second_fork = 0;
	if (philo->rules.nbr_philo == 1)
		return ;
	if (philo->id % 2 == 0)
	{
		first_fork = philo->id - 1;
		second_fork = philo->id % philo->rules.nbr_philo;
	}
	else if (philo->id % 2 != 0)
	{
		first_fork = philo->id % philo->rules.nbr_philo;
		second_fork = philo->id - 1;
	}
	eating(philo, first_fork, second_fork);
}

void	*routine(void *perso)
{
	t_philo	*philo;

	philo = (t_philo *) perso;
	if (philo->id % 2 == 0)
		print_action_and_wait(philo, "%ld %d is thinking\n",
			philo->rules.time_to_think);
	else if (philo->id == philo->rules.nbr_philo)
		print_action_and_wait(philo, "%ld %d is thinking\n",
			philo->rules.time_to_eat);
	while (1)
	{
		init_eating_proces(philo);
		print_action_and_wait(philo, "%ld %d is sleeping\n",
			philo->rules.time_to_sleep);
		print_action_and_wait(philo, "%ld %d is thinking\n",
			philo->rules.time_to_think);
		if (check_philo_continue(philo->data, philo) == -1)
			return ((void *) 0);
	}
}
