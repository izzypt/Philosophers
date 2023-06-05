/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 22:06:23 by simao             #+#    #+#             */
/*   Updated: 2023/06/05 13:02:53 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/*
- Esta função aloca memoria para o array de mutexes dos garfos.
- Inicia um nº de mutex igual ao nº de filosofos.
*/
void	init_forks(int num_of_fork)
{
	int				i;
	pthread_mutex_t	*forks;

	i = 0;
	printf("| Creating forks...                                          |\n");
	sim()->forks = malloc(num_of_fork * sizeof(pthread_mutex_t));
	forks = sim()->forks;
	while (i < num_of_fork)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

/*
- Esta função deve trancar os garfos correspondentes ao filosofo que a executar.
- Quando o filosofo tiver trancado os garfos, ele deve comer.
*/
void	take_forks(t_philosopher *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&sim()->forks[philo->rfork]);
		pthread_mutex_lock(&sim()->forks[philo->lfork]);
	}
	else
	{
		pthread_mutex_lock(&sim()->forks[philo->lfork]);
		pthread_mutex_lock(&sim()->forks[philo->rfork]);
	}
	philo->time_limit = get_time() + sim()->time_to_eat + sim()->time_to_die;
	philo->last_meal = get_time() + sim()->time_to_eat;
	eat(philo);
	printf("%lu %d took a fork\n", get_time() - sim()->start_time, philo->id);
}

void	eat(t_philosopher *philo)
{
	philo->is_eating = 1;
	printf("%lu %d is eating\n", get_time() - sim()->start_time, philo->id);
	sleep_ms(sim()->time_to_eat);
	printf("%lu %d last meal was %lu and next meal should be until %lu\n", get_time() - sim()->start_time, philo->id, philo->last_meal - sim()->start_time ,philo->time_limit - sim()->start_time);
	philo->is_eating = 0;
	release_forks(philo);
}

void	release_forks(t_philosopher *philo)
{
	pthread_mutex_unlock(&sim()->forks[philo->lfork]);
	pthread_mutex_unlock(&sim()->forks[philo->rfork]);
	printf("%lu %d is sleeping\n", get_time() - sim()->start_time, philo->id);
	sleep_ms(sim()->time_to_sleep);
	printf("%lu %d is thinking\n", get_time() - sim()->start_time, philo->id);
}
