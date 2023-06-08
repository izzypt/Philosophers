/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 00:05:37 by francisco         #+#    #+#             */
/*   Updated: 2023/06/08 23:48:18 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

int	check_eat(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&data->m_check_eat);
	if (philo->eat_lock == 0)
	{
		if (philo->eat_counter == data->max_meals)
		{
			data->eat_flag += 1;
			philo->eat_lock = 1;
		}
		if (data->eat_flag == data->num_philos)
		{
			pthread_mutex_unlock(&data->m_check_eat);
			return (0);
		}
	}
	pthread_mutex_unlock(&data->m_check_eat);
	return (1);
}

int	check_all(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&data->m_dead_philo);
	if (data->dead_flag == 1 || data->eat_flag == data->num_philos)
	{
		pthread_mutex_unlock(&data->m_dead_philo);
		return (0);
	}
	if ((get_time(data) - philo->last_eat) > data->time_die)
	{
		data->dead_flag = 1;
		printf("%lld ... %d %s\n", get_time(data), philo->id, DEAD);
		pthread_mutex_unlock(&data->m_dead_philo);
		return (0);
	}
	if (!check_eat(data, philo))
	{
		pthread_mutex_unlock(&data->m_dead_philo);
		return (0);
	}
	pthread_mutex_unlock(&data->m_dead_philo);
	return (1);
}

void	free_and_destroy(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_philos)
		pthread_mutex_destroy(&data->m_fork[i]);
	pthread_mutex_destroy(&data->m_dead_philo);
	pthread_mutex_destroy(&data->m_check_eat);
	pthread_mutex_destroy(&data->m_counter);
	pthread_mutex_destroy(&data->m_increment);
	free(data->m_fork);
	free(data->forks);
	free(data->philos);
}
