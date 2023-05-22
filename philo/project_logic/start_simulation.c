/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:03:24 by simao             #+#    #+#             */
/*   Updated: 2023/05/22 13:12:37 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	start_simulation(char **argv)
{
	sim()->number_of_philosophers = ft_atoi(argv[1]);
	sim()->time_to_die = ft_atoi(argv[2]);
	sim()->time_to_eat = ft_atoi(argv[3]);
	sim()->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		sim()->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	printf("Number of philosophers: %d\n", sim()->number_of_philosophers);
	printf("Time to die: %d\n", sim()->time_to_die);
	printf("Time to sleep: %d\n", sim()->time_to_sleep);
	printf("Time to eat: %d\n", sim()->time_to_eat);
}
