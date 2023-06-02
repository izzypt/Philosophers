/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:03:24 by simao             #+#    #+#             */
/*   Updated: 2023/06/02 17:24:57 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	start_simulation(char **argv)
{
	sim()->start_time = get_time();
	sim()->number_of_philosophers = ft_atoi(argv[1]);
	sim()->time_to_die = ft_atoi(argv[2]);
	sim()->time_to_eat = ft_atoi(argv[3]);
	sim()->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		sim()->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	printf("Starting time: %ld\n", sim()->start_time);
	printf("Num of philosophers: %d\n", sim()->number_of_philosophers);
	printf("Time to die: %d\n", sim()->time_to_die);
	printf("Time to eat: %d\n", sim()->time_to_sleep);
	printf("Time to sleep: %d\n", sim()->time_to_eat);
	sleep_ms(600);
	printf("Time elapsed: %ld\n", get_time() - sim()->start_time);
}

void	*thread_created(void *arg)
{
	pthread_t	tid;

	tid = pthread_self();
	if (arg || !arg)
		printf("New thread created, id : %lu\n", tid);
	return (NULL);
}

void	create_philos(void)
{
	int	i;

	i = 0;
	sim()->philosophers = malloc(sizeof(t_philosopher) \
	* sim()->number_of_philosophers);

	while (i < sim()->number_of_philosophers)
	{
		sim()->philosophers[i].id = i;
		i++;
	}
}

void	create_threads(void)
{
	int			i;
	pthread_t	*threads;

	i = 0;
	sim()->threads = malloc(sim()->number_of_philosophers * sizeof(pthread_t));
	threads = sim()->threads;
	while (i < sim()->number_of_philosophers)
	{
		pthread_create(&threads[i], NULL, thread_created, NULL);
		pthread_join(threads[i], NULL);
		printf("i = %d\n", i);
		i++;
	}
}

void	create_forks(void)
{
	int				i;
	pthread_mutex_t	*forks;

	i = 0;
	sim()->forks = \
	malloc(sim()->number_of_philosophers * sizeof(pthread_mutex_t));
	forks = sim()->forks;
	while (i < sim()->number_of_philosophers)
	{
		pthread_mutex_init(&forks[i], NULL);
	}
}
