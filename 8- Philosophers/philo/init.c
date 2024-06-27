/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:26:24 by sycourbi          #+#    #+#             */
/*   Updated: 2023/11/13 19:31:44 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free(t_data *data)
{
	if (data->philo)
		free(data->philo);
	if (data->thread_ids)
		free(data->thread_ids);
	if (data->forks)
		free(data->forks);
}

int	init_malloc(t_data *data)
{
	data->philo = malloc(sizeof(t_philo) * data->global_rules.nbr_philo);
	if (!data->philo)
		return (1);
	data->thread_ids = malloc(sizeof(pthread_t) * data->global_rules.nbr_philo);
	if (!data->philo)
		return (free(data->philo), 1);
	data->forks = malloc(sizeof(pthread_mutex_t)
			* data->global_rules.nbr_philo);
	if (!data->forks)
		return (free(data->philo), free(data->thread_ids), 1);
	return (0);
}

void	init_phi(t_data *data, char **argv)
{
	int	i;

	i = 0;
	while (i < data->global_rules.nbr_philo)
	{
		data->philo[i].data = data;
		data->philo[i].id = i + 1;
		data->philo[i].last_meal = 0;
		data->philo[i].rules = data->global_rules;
		if (argv[5])
			data->philo[i].reste_meal = ft_atoi(argv[5]);
		else
			data->philo[i].reste_meal = -1;
		i++;
	}
}

int	init_mutex(t_data *data)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&data->write, NULL))
		return (1);
	if (pthread_mutex_init(&data->mutex_check, NULL))
		return (pthread_mutex_destroy(&data->write), 1);
	while (i < data->global_rules.nbr_philo)
	{
		if (pthread_mutex_init(&data->forks[i], NULL))
		{
			while (i-- >= 0)
				pthread_mutex_destroy(&data->forks[i]);
			return (pthread_mutex_destroy(&data->write),
				pthread_mutex_destroy(&data->mutex_check), 1);
		}
		i++;
	}
	return (0);
}

int	ft_init(t_data *data, char **argv)
{
	t_rules	rules;

	rules.nbr_philo = ft_atoi(argv[1]);
	rules.time_to_die = ft_atoi(argv[2]) - 1;
	rules.time_to_eat = ft_atoi(argv[3]);
	rules.time_to_sleep = ft_atoi(argv[4]);
	rules.time_to_think = (rules.time_to_die - rules.time_to_eat
			- rules.time_to_sleep) * 0.75;
	data->global_rules = rules;
	if (rules.nbr_philo <= 0 || rules.time_to_die <= 0 || rules.time_to_eat <= 0
		|| rules.time_to_sleep <= 0)
		return (printf("Probleme with argument \n"), -1);
	data->fini = rules.nbr_philo;
	if (init_malloc(data) == 1)
		return (printf("probleme with allocation\n"), -1);
	if (init_mutex(data) == 1)
		return (ft_free(data), -1);
	return (init_phi(data, argv), 1);
}
