/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 00:05:37 by francisco         #+#    #+#             */
/*   Updated: 2023/06/09 00:50:04 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

/*
- 
-
*/
void	check_fork(t_data *data, t_philo *philo, int pos)
{
	pthread_mutex_lock(&data->m_fork[pos]);
	if (data->forks[pos] == 0)
	{
		data->forks[pos] = 1;
		philo->fork += 1;
		if (check_all(data, philo))
			printf("%lld ... %d %s\n", get_time(data), philo->id, FORK);
	}
	pthread_mutex_unlock(&data->m_fork[pos]);
}

/*
-
-
*/
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

/*
- Verifica se existe algum filosofo morto 
- Verifica se os filosofos ja comeram o maximo de meals.
- Verifica se o tempo limite para o filosofo comer foi ultrupassado.
*/
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

