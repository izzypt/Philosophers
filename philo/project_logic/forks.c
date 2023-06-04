/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 22:06:23 by simao             #+#    #+#             */
/*   Updated: 2023/06/04 01:07:02 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	take_forks(t_philosopher *philo)
{
	pthread_mutex_lock(&sim()->forks[philo->lfork]);
	pthread_mutex_lock(&sim()->forks[philo->rfork]);
	if (get_time() > philo->time_limit)
	{
		printf("Filo %d dead\n", philo->id);
		printf("time limit was %lu\n", philo->time_limit);
		sim()->any_death = 1;
		exit(0);
	}
	printf("%lu %d has taken a fork\n", get_time(), philo->id);
	philo->is_eating = 1;
	philo->last_meal = get_time();
	philo->time_limit = philo->last_meal + sim()->time_to_die;
	printf("%lu %d is eating\n", get_time(), philo->id);
	sleep_ms(sim()->time_to_eat);
	philo->is_eating = 0;
	pthread_mutex_unlock(&sim()->forks[philo->lfork]);
	pthread_mutex_unlock(&sim()->forks[philo->rfork]);
	philo_zZz(philo);
}
