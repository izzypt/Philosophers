/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 17:50:32 by simao             #+#    #+#             */
/*   Updated: 2023/06/06 03:33:57 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	if (argc > 2)
		init_sim(argv);
	while (1)
	{
		if (!sim()->game_on || sim()->full_philos == sim()->num_of_philo)
		{
			free_and_exit();
			break ;
		}
	}	
	return (0);
}
