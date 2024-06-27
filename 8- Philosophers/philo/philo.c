/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:15:12 by sycourbi          #+#    #+#             */
/*   Updated: 2023/11/06 16:53:37 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_cleanup(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < data->global_rules.nbr_philo)
	{
		if (pthread_mutex_destroy(&data->forks[i]))
			j++;
		i++;
	}
	if (pthread_mutex_destroy(&data->mutex_check))
		j++;
	if (pthread_mutex_destroy(&data->write))
		j++;
	if (data->forks)
		free(data->forks);
	if (data->thread_ids)
		free(data->thread_ids);
	if (data->philo)
		free(data->philo);
	return (j);
}

int	ft_init_and_start(t_data *data)
{
	int	i;

	i = 0;
	data->t0 = get_time(0);
	while (i < data->global_rules.nbr_philo)
	{
		if (pthread_create(&data->thread_ids[i], NULL, &routine,
				&data->philo[i]))
		{
			while (i-- >= 0)
				pthread_join(data->thread_ids[i], NULL);
			return (1);
		}
		i++;
	}
	check_philo_life(data);
	i = 0;
	while (i < data->global_rules.nbr_philo)
	{
		if (pthread_join(data->thread_ids[i], NULL))
			return (2);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		error;

	data.someone_died = 0;
	error = 0;
	if (argc < 5 || argc > 6)
		return (printf("probleme with argument\n"));
	if (check_arg(argc, argv) == 1)
		return (-1);
	if (ft_init(&data, argv) == -1)
		return (-1);
	error = ft_init_and_start(&data);
	if (error == 1)
		printf("problem creat thread\n");
	else if (error == 2)
		printf("problem join threads\n");
	return (ft_cleanup(&data));
}
