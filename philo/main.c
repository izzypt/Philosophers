/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 17:50:32 by simao             #+#    #+#             */
/*   Updated: 2023/05/25 13:30:55 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"



int	main(int argc, char **argv)
{
	if (argc > 2)
		start_simulation(argv);
	create_threads();
	//printf("time : %ld", get_time());
	/*pthread_t	t1;
	pthread_t	t2;

	pthread_create(&t1, NULL, &routine, NULL);
	pthread_create(&t2, NULL, &routine, NULL);
	pthread_join(t1, NULL);
	pthread_join(t1, NULL);*/
	return (0);
}
