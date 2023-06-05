/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 22:06:23 by simao             #+#    #+#             */
/*   Updated: 2023/06/05 17:37:46 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/*
- Esta função aloca memoria para o array de mutexes dos garfos.
- Cria e inicia um nº de mutex igual ao nº de filosofos.
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
	pthread_mutex_lock(&sim()->forks[philo->lfork]);
	pthread_mutex_lock(&sim()->forks[philo->rfork]);
	philo->time_limit = get_time() + sim()->time_to_die;
	philo->last_meal = get_time();
	printf("%lu %d took a fork\n", get_time() - sim()->start_time, philo->id);
	eat(philo);
}

void	eat(t_philosopher *philo)
{
	philo->is_eating = 1;
	printf("%lu %d is eating\n", get_time() - sim()->start_time, philo->id);
	philo->num_of_meals++;
	sleep_ms(sim()->time_to_eat);
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
