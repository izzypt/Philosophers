/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 22:59:32 by francisco         #+#    #+#             */
/*   Updated: 2023/06/08 23:37:46 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

/*
- Se houver apenas um filosofo, ele irá morrer por apenas haver 1 garfo.
*/
void	philo_starve(t_data *data, t_philo *philo)
{
	printf("%lld ... %d %s\n", get_time(data), philo->id, FORK);
	ft_usleep(data->time_die);
	printf("%lld ... %d %s\n", get_time(data), philo->id, DEAD);
	pthread_mutex_lock(&data->m_dead_philo);
	data->dead_flag = 1;
	pthread_mutex_unlock(&data->m_dead_philo);
}

/*
- A thread handler for each philo
- Delay the time in which even philosophers reach the table
- Will make the checks before executing any action.
*/
void	*philo_handler(void *arg)
{
	t_data		*data;
	t_philo		*philo;
	static int	i = 0;

	data = (t_data *)arg;
	pthread_mutex_lock(&data->m_increment);
	philo = &data->philos[i++];
	pthread_mutex_unlock(&data->m_increment);
	if (philo->id % 2 == 0)
		ft_usleep(15);
	while (check_all(data, philo))
	{
		if (data->num_philos == 1)
			philo_starve(data, philo);
		else
		{
			if (check_all(data, philo))
				philo_eat(data, philo);
			if (check_all(data, philo))
				philo_sleep(data, philo);
			if (check_all(data, philo))
				printf("%lld ... %d %s\n", get_time(data), philo->id, THINK);
		}
	}
	return (NULL);
}

/*
- Will set the initial time of the simulation
- Will create a thread for each philosopher.
- Will wait for the threads to run and join them to the main thread.
*/
void	run_simulation(t_data *data)
{
	struct timeval	st;
	int				i;

	if (data->max_meals == 0)
		return ;
	gettimeofday(&st, NULL);
	data->start_time = (st.tv_sec * 1000) + (st.tv_usec / 1000);
	i = -1;
	while (++i < data->num_philos)
	{
		data->philos[i].last_eat = data->start_time;
		if (pthread_create(&data->philos[i].philo_thread, NULL, \
		&philo_handler, data))
			return ;
	}
	i = -1;
	while (++i < data->num_philos)
		pthread_join(data->philos[i].philo_thread, NULL);
}
