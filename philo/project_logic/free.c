/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagalha <smagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 22:10:46 by simao             #+#    #+#             */
/*   Updated: 2023/06/06 19:18:42 by smagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	free_and_exit(void)
{
	int	i;

	i = 0;
	while (i < sim()->num_of_philo)
	{
		pthread_mutex_unlock(&sim()->forks[i]);
		pthread_mutex_destroy(&sim()->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&sim()->write_mutex);
	free(sim()->forks);
	free(sim()->philos);
	free(sim()->threads);
	exit(0);
}
