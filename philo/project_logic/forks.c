/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 22:06:23 by simao             #+#    #+#             */
/*   Updated: 2023/06/06 21:17:58 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/*
- Esta função deve trancar os garfos correspondentes ao filosofo que a executar.
- Quando o filosofo tiver trancado os garfos, ele deve comer.
*/
void	take_forks(t_philosopher *philo)
{
	if (sim()->num_of_philo == 1)
	{
		sleep_ms(sim()->time_to_die);
		print_message(1, philo->id);
		return ;
	}
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
