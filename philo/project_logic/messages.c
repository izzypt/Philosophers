/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:23:13 by simao             #+#    #+#             */
/*   Updated: 2023/06/07 23:05:23 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/*
- Print a table with the simulation information when it starts.
*/
void	print_stats(void)
{
	printf("==============================================================\n");
	printf("|                    Philosophers Simulation                 |\n");
	printf("==============================================================\n");
	printf("|                Start : %ld                                   |\n", \
	sim()->start_time - sim()->start_time);
	printf("|                Number of philosophers : %d                  |\n", \
	sim()->num_of_philo);
	printf("|                Time to die : %d                           |\n", \
	sim()->time_to_die);
	printf("|                Time to eat : %d                           |\n", \
	sim()->time_to_eat);
	printf("|                Time to sleep : %d                         |\n", \
	sim()->time_to_sleep);
	printf("==============================================================\n");
}

void	print_message(int code, int philo_id)
{
	pthread_mutex_lock(&sim()->write_mutex);
	if (code == 1 && !sim()->any_death)
	{
		printf("%lu %d died.\n", get_time() - sim()->start_time, philo_id);
		sim()->any_death = 1;
	}
	if (code == 2 && !sim()->any_death)
		printf("Philo %d is full.\n", philo_id);
	if (code == 3 && !sim()->any_death)
		printf("%lu %d took a fork\n", get_time() - sim()->start_time, philo_id);
	if (code == 4 && !sim()->any_death)
		printf("%lu %d is eating\n", get_time() - sim()->start_time, philo_id);
	if (code == 5 && !sim()->any_death)
		printf("%lu %d is sleeping\n", get_time() - sim()->start_time, philo_id);
	if (code == 6 && !sim()->any_death)
		printf("%lu %d is thinking\n", get_time() - sim()->start_time, philo_id);
	pthread_mutex_unlock(&sim()->write_mutex);
}
