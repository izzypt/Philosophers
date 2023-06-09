/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 17:50:32 by simao             #+#    #+#             */
/*   Updated: 2023/06/08 18:53:24 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc > 2)
		init_sim(argv);
	while (i < sim()->num_of_philo)
	{
		pthread_join(sim()->threads[i], NULL);
		pthread_join(sim()->philos[i].thread, NULL);
		i++;
	}
	free_and_exit();
	return (0);
}
