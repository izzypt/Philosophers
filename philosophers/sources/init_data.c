/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 22:16:50 by francisco         #+#    #+#             */
/*   Updated: 2023/06/08 22:46:19 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

int	check_args(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = -1;
		while (argv[i][++j])
			if (!ft_isdigit(argv[i][j]))
				return (1);
		i++;
	}
	if (ft_atoi(argv[1]) < 1 || ft_atoi(argv[2]) < 0
		|| ft_atoi(argv[3]) < 0 || ft_atoi(argv[4]) < 0)
		return (2);
	return (0);
}

int	init_alloc(t_data *data)
{
	data->forks = ft_calloc(data->num_philos, sizeof(int));
	if (!data->forks)
		return (1);
	data->philos = ft_calloc(data->num_philos, sizeof(t_philo));
	if (!data->philos)
		return (2);
	data->m_fork = ft_calloc(data->num_philos, sizeof(pthread_mutex_t));
	if (!data->m_fork)
		return (3);
	return (0);
}

void	init_philos(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_philos)
	{
		data->philos[i].id = i + 1;
		data->philos[i].time_die = data->time_die;
		data->philos[i].eat_counter = 0;
		data->philos[i].eat_lock = 0;
		data->philos[i].last_eat = 0;
		data->philos[i].philo_dead = 0;
		data->philos[i].fork = 0;
		if (i < data->num_philos)
		{
			data->philos[i].left = i;
			data->philos[i].right = (i + 1) % data->num_philos;
		}
	}
}

int	init_mutexes(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_philos)
	{
		if (pthread_mutex_init(&data->m_fork[i], NULL) != 0)
			return (1);
	}
	if (pthread_mutex_init(&data->m_dead_philo, NULL) != 0)
		return (2);
	if (pthread_mutex_init(&data->m_check_eat, NULL) != 0)
		return (3);
	if (pthread_mutex_init(&data->m_counter, NULL) != 0)
		return (4);
	if (pthread_mutex_init(&data->m_increment, NULL) != 0)
		return (5);
	return (0);
}

int	init_data(t_data *data, char **argv)
{
	data->num_philos = ft_atoi(argv[1]);
	data->time_die = ft_atoi(argv[2]);
	data->time_eat = ft_atoi(argv[3]);
	data->time_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data->max_meals = ft_atoi(argv[5]);
	else
		data->max_meals = -1;
	if (init_alloc(data))
		return (1);
	init_philos(data);
	init_mutexes(data);
	return (0);
}
