/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:29:12 by francisco         #+#    #+#             */
/*   Updated: 2023/06/09 00:53:44 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

void	philo_eat(t_data *data, t_philo *philo)
{
	while (philo->fork != 2 && check_all(data, philo))
	{
		check_fork(data, philo, philo->left);
		check_fork(data, philo, philo->right);
	}
	if (check_all(data, philo))
	{
		philo->last_eat = get_time(data);
		if (check_all(data, philo))
			printf("%lld ... %d %s\n", get_time(data), philo->id, EAT);
		philo->eat_counter += 1;
		check_all(data, philo);
		ft_usleep(data->time_eat);
		pthread_mutex_lock(&data->m_fork[philo->left]);
		data->forks[philo->left] = 0;
		pthread_mutex_unlock(&data->m_fork[philo->left]);
		pthread_mutex_lock(&data->m_fork[philo->right]);
		data->forks[philo->right] = 0;
		pthread_mutex_unlock(&data->m_fork[philo->right]);
		philo->fork = 0;
		check_all(data, philo);
	}
}

void	philo_sleep(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&data->m_check_eat);
	if (data->dead_flag == 0 && data->eat_flag != data->num_philos)
	{
		pthread_mutex_unlock(&data->m_check_eat);
		printf("%lld ... %d %s\n", get_time(data), philo->id, SLEEP);
		ft_usleep(data->time_sleep);
	}
	else
		pthread_mutex_unlock(&data->m_check_eat);
}
