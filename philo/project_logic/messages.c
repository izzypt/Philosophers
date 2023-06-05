/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:23:13 by simao             #+#    #+#             */
/*   Updated: 2023/06/05 18:40:02 by simao            ###   ########.fr       */
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
