/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 22:10:46 by simao             #+#    #+#             */
/*   Updated: 2023/06/08 19:20:27 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	free_and_exit(void)
{
	int	i;

	i = 0;
	while (i < sim()->num_of_philo)
	{
		pthread_mutex_destroy(&sim()->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&sim()->write_mutex);
	free(sim()->forks);
	free(sim()->philos);
	free(sim()->threads);
}
