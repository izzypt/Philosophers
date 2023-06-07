/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 22:05:12 by simao             #+#    #+#             */
/*   Updated: 2023/06/07 22:30:13 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"
/*
- Monitoriza cada um dos filosofos a cada 5 ms.
- Se o tempo actual for superior ao limite para comer o program termina,
*/
void	*monitor(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	while (1)
	{
		pthread_mutex_lock(&philo->philo_mutex);
		if (get_time() > philo->time_limit)
		{
			pthread_mutex_unlock(&philo->philo_mutex);
			pthread_mutex_lock(&philo->philo_mutex);
			if (philo->ishappy)
			{
				pthread_mutex_unlock(&philo->philo_mutex);
				break ;
			}	
			print_message(1, philo->id);
			pthread_mutex_unlock(&philo->philo_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->philo_mutex);
	}
	return (NULL);
}

/*
- This is the thread handler.
- The first function ran when the thread is created.
- It adds a delay to the even number of philosophers.
- Even philosophers threads will arrive later than uneven threads.
*/
void	*t_handler(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	pthread_create(&philo->thread, NULL, monitor, (void *)philo);
	if (philo->id % 2 == 0)
		sleep_ms(6);
	while (1)
	{
		if (sim()->any_death)
			break ;
		if (sim()->max_meals > 0 && (philo->num_of_meals == sim()->max_meals))
		{
			pthread_mutex_lock(&philo->philo_mutex);
			philo->ishappy = 1;
			pthread_mutex_unlock(&philo->philo_mutex);
			pthread_mutex_lock(&sim()->check_mutex);
			sim()->happy_philos += 1;
			pthread_mutex_unlock(&sim()->check_mutex);
			print_message(2, philo->id);
			break ;
		}
		take_forks(philo);
	}	
	return (NULL);
}

/*
- Aloca memoria necessaria para cada thread.
- Cria uma thread por cada filosofo.
- Espera que cada thread termine antes de terminar a execucao.
*/
void	init_threads(void)
{
	int			i;
	pthread_t	*threads;

	printf("| Creating threads...                                        |\n");
	printf("==============================================================\n");
	i = 0;
	sim()->threads = malloc(sim()->num_of_philo * sizeof(pthread_t));
	threads = sim()->threads;
	sim()->start_time = get_time();
	while (i < sim()->num_of_philo)
	{
		pthread_create(&threads[i], NULL, t_handler, (void *)&sim()->philos[i]);
		i++;
	}
}
