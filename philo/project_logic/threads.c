/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagalha <smagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 22:05:12 by simao             #+#    #+#             */
/*   Updated: 2023/06/03 21:11:55 by smagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/*
- This is the thread handler.
- The first function ran when the thread is created.
*/
void	*t_handler(void *arg)
{
	t_philosopher	philo;

	philo = *(t_philosopher *)arg;
	while (!sim()->any_death)
	{
		take_forks(&philo);
		usleep(50);
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

	printf("Creating threads...\n");
	printf("================================================================\n");
	i = 0;
	sim()->threads = malloc(sim()->num_of_philo * sizeof(pthread_t));
	threads = sim()->threads;
	sim()->start_time = get_time();
	while (i < sim()->num_of_philo)
	{
		pthread_create(&threads[i], NULL, t_handler, (void *)&sim()->philos[i]);
		i++;
	}
	i = 0;
	while (i < sim()->num_of_philo)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
}
