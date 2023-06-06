/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagalha <smagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 17:50:32 by simao             #+#    #+#             */
/*   Updated: 2023/06/06 17:45:57 by smagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc > 2)
		init_sim(argv);
	while (1)
	{
		if (sim()->any_death || sim()->happy_philos == sim()->num_of_philo)
		{
			free_and_exit();
			break ;
		}
	}	
	return (0);
}
