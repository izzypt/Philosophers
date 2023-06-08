/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 21:12:52 by francsan          #+#    #+#             */
/*   Updated: 2023/06/08 23:48:30 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

/*
- Verifica o input inicial e os argumentos.
- Aloca memoria para a struct data e inicia.
- Começa a correr a simulacao.
*/
int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc == 5 || argc == 6)
	{
		if (check_args(argv))
			return (1);
	}
	else
		return (2);
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (3);
	if (init_data(data, argv))
		return (4);
	run_simulation(data);
	if (data->eat_flag == data->num_philos)
		printf("%lld ... %s\n", get_time(data), MEALS);
	free_and_destroy(data);
	return (0);
}
