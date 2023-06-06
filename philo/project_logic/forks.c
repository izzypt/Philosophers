/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagalha <smagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 22:06:23 by simao             #+#    #+#             */
/*   Updated: 2023/06/06 17:09:44 by smagalha         ###   ########.fr       */
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
	pthread_mutex_lock(&sim()->forks[philo->rfork]);
	pthread_mutex_lock(&sim()->forks[philo->lfork]);
	philo->time_limit = get_time() + sim()->time_to_die;
	print_message(3, philo->id);
	eat(philo);
}

void	eat(t_philosopher *philo)
{
	print_message(4, philo->id);
	philo->num_of_meals++;
	sleep_ms(sim()->time_to_eat);
	release_forks(philo);
}

void	release_forks(t_philosopher *philo)
{
	pthread_mutex_unlock(&sim()->forks[philo->lfork]);
	pthread_mutex_unlock(&sim()->forks[philo->rfork]);
	print_message(5, philo->id);
	sleep_ms(sim()->time_to_sleep);
	print_message(6, philo->id);
}
