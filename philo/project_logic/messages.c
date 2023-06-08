/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:23:13 by simao             #+#    #+#             */
/*   Updated: 2023/06/08 19:40:27 by simao            ###   ########.fr       */
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

void	print_message(int code, t_philosopher *philo)
{
	if (code == 1 && !sim()->any_death)
	{
		printf("%lu %d died.\n", get_time() - sim()->start_time, philo->id);
		sim()->any_death = 1;
	}
	if (code == 2 && !sim()->any_death)
		printf("Philo %d is full.\n", philo->id);
	if (code == 3 && !sim()->any_death)
		printf("%lu %d took forks\n", get_time() - sim()->start_time, philo->id);
	if (code == 4 && !sim()->any_death)
		printf("%lu %d is eating\n", get_time() - sim()->start_time, philo->id);
	if (code == 5 && !sim()->any_death)
		printf("%lu %d sleeping\n", get_time() - sim()->start_time, philo->id);
	if (code == 6 && !sim()->any_death)
		printf("%lu %d thinking\n", get_time() - sim()->start_time, philo->id);
}
