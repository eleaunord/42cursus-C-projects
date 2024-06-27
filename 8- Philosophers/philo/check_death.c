/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:16:51 by sycourbi          #+#    #+#             */
/*   Updated: 2023/11/14 15:05:58 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_arg(int argc, char **argv)
{
	int	i;
	int	j;
	int	count_significant_digits;

	i = 1;
	while (i <= argc - 1)
	{
		j = 0;
		count_significant_digits = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		while (argv[i][j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				return (printf("problem args\n"), 1);
			count_significant_digits += argv[i][j] != '0';
			j++;
		}
		if (count_significant_digits > 10)
			return (printf("problem arg\n"), 1);
		i++;
	}
	return (0);
}

void	signal_print_death(t_data *data, int i)
{
	pthread_mutex_lock(&data->mutex_check);
	data->someone_died = 1;
	pthread_mutex_unlock(&data->mutex_check);
	pthread_mutex_lock(&data->write);
	printf("%ld %d died\n", get_time(data->t0), i);
	pthread_mutex_unlock(&data->write);
}

void	check_philo_life(t_data *data)
{
	int	i;
	int	time_last_meal;

	i = 0;
	while (1)
	{
		pthread_mutex_lock(&data->mutex_check);
		time_last_meal = get_time(data->t0) - data->philo[i].last_meal;
		pthread_mutex_unlock(&data->mutex_check);
		if (time_last_meal > data->global_rules.time_to_die)
			return (signal_print_death(data, i + 1));
		pthread_mutex_lock(&data->mutex_check);
		if (data->fini == 0)
		{
			pthread_mutex_unlock(&data->mutex_check);
			return ;
		}
		pthread_mutex_unlock(&data->mutex_check);
		i++;
		i = i % data->global_rules.nbr_philo;
	}
}
