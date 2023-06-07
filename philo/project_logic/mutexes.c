/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:32:50 by smagalha          #+#    #+#             */
/*   Updated: 2023/06/07 22:28:54 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/*
- Esta função aloca memoria para o array de mutexes dos garfos.
- Cria e inicia um nº de mutex igual ao nº de filosofos.
*/
void	init_mutexes(int num_of_fork)
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
		pthread_mutex_init(&sim()->philos[i].philo_mutex, NULL);
		i++;
	}
	pthread_mutex_init(&sim()->write_mutex, NULL);
	pthread_mutex_init(&sim()->time_mutex, NULL);
	pthread_mutex_init(&sim()->check_mutex, NULL);
}
