/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagalha <smagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:03:24 by simao             #+#    #+#             */
/*   Updated: 2023/05/22 20:32:03 by smagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	start_simulation(char **argv)
{
	sim()->number_of_philosophers = ft_atoi(argv[1]);
	sim()->time_to_die = ft_atoi(argv[2]);
	sim()->time_to_eat = ft_atoi(argv[3]);
	sim()->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		sim()->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	printf("Num of philosophers: %d\n", sim()->number_of_philosophers);
	printf("Time to die: %d\n", sim()->time_to_die);
	printf("Time to eat: %d\n", sim()->time_to_sleep);
	printf("Time to sleep: %d\n", sim()->time_to_eat);
}

void	*thread_created(void *arg)
{
	if (arg || !arg)
		printf("New thread created\n");
	return (NULL);
}

void thread_for_each_philo()
{
	int i;
	pthread_t *thread;

	i = 0;
	printf("Cria uma thread por cada filosofo\n");
	thread = malloc(sim()->number_of_philosophers * sizeof(pthread_t));
	while (i < sim()->number_of_philosophers)
	{
		thread[i] = pthread_create(&thread[i], NULL, thread_created, NULL);
		i++;
	}
	i = 0;
	/*while (i < sim()->number_of_philosophers)
	{
		pthread_join(thread[i], NULL);
		i++;
	}*/
}
