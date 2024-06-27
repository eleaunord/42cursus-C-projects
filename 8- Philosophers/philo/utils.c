/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:56:49 by sycourbi          #+#    #+#             */
/*   Updated: 2023/11/14 15:06:50 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	long	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r')
		|| nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + (nptr[i] - '0');
		i++;
	}
	if ((sign * nb) < INT_MIN || (sign * nb) > INT_MAX)
		return (-1);
	return ((int)sign * nb);
}

long	get_time(long t0)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_usec / 1000 + tv.tv_sec * 1000 - t0);
}

int	check_philo_continue(t_data *data, t_philo *philo)
{
	(void)philo;
	pthread_mutex_lock(&data->mutex_check);
	if (data->someone_died || data->fini == 0)
	{
		pthread_mutex_unlock(&data->mutex_check);
		return (-1);
	}
	pthread_mutex_unlock(&data->mutex_check);
	return (1);
}

void	print_meal(t_philo *philo)
{
	if (check_philo_continue(philo->data, philo) != -1)
	{
		printf("%ld %d has taken a fork\n", philo->last_meal, philo->id);
		printf("%ld %d has taken a fork\n", philo->last_meal, philo->id);
		printf("%ld %d is eating\n", philo->last_meal, philo->id);
	}
}

void	ft_usleep(t_data *data, long time_action)
{
	long	start_t;
	long	cur_t;

	start_t = get_time(0);
	cur_t = start_t;
	while (check_philo_continue(data, &data->philo[0]) != -1
		&& (cur_t - start_t) < time_action)
	{
		usleep(100);
		cur_t = get_time(0);
	}
}
