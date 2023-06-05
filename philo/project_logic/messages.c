/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagalha <smagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:23:13 by simao             #+#    #+#             */
/*   Updated: 2023/06/05 20:25:16 by smagalha         ###   ########.fr       */
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
	if (code == 1)
	{
		printf("%lu %d died.\n", get_time() - sim()->start_time, philo_id);
		free_and_exit();
	}
	if (code == 2)
		printf("Philo %d is full.\n", philo_id);
	if (code == 3)
	{
		printf("%lu %d took a fork\n", \
		get_time() - sim()->start_time, philo_id);
	}
	if (code == 4)
	{
		printf("%lu %d is eating\n", get_time() - sim()->start_time, philo_id);
	}
	if (code == 5)
	{
		printf("%lu %d is sleeping\n", \
		get_time() - sim()->start_time, philo_id);
	}
	if (code == 6)
		printf("%lu %d is thinking\n", get_time() - sim()->start_time, philo_id);
}
