/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:03:24 by simao             #+#    #+#             */
/*   Updated: 2023/06/08 19:00:37 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/*
- Inicia a simulação.
- Guarda os valores dos argumentos na struct.
- Imprime os valores iniciais da simulação.
- Chama a funçao necessaria para criar os forks.
- Chama a função necessária para criar os filosofos.
*/
void	init_sim(char **argv)
{
	sim()->start_time = get_time();
	sim()->num_of_philo = ft_atoi(argv[1]);
	sim()->num_of_forks = ft_atoi(argv[1]);
	sim()->time_to_die = ft_atoi(argv[2]);
	sim()->time_to_eat = ft_atoi(argv[3]);
	sim()->time_to_sleep = ft_atoi(argv[4]);
	sim()->happy_philos = 0;
	sim()->any_death = 0;
	if (argv[5])
		sim()->max_meals = ft_atoi(argv[5]);
	else
		sim()->max_meals = 0;
	print_stats();
	init_philos();
	init_mutexes(sim()->num_of_philo);
	init_threads();
}

/*
- Aloca memoria necessaria para o array de filosofos.
- Atribui a cada filo um id
- Define os garfos que pode segurar, o nº de refeicoes, etc...
- No, fim chama a função necessaria para criar as threads.
*/
void	init_philos(void)
{
	int	i;
	int	tmp;

	i = 0;
	sim()->philos = malloc(sizeof(t_philosopher) * sim()->num_of_philo);
	printf("| Creating philos...                                         |\n");
	while (i < sim()->num_of_philo)
	{
		sim()->philos[i].id = i + 1;
		sim()->philos[i].rfork = i;
		sim()->philos[i].lfork = ((i + 1) % sim()->num_of_philo);
		if (sim()->philos[i].rfork > sim()->philos[i].lfork)
		{
			tmp = sim()->philos[i].rfork;
			sim()->philos[i].rfork = sim()->philos[i].lfork;
			sim()->philos[i].lfork = tmp;
		}
		sim()->philos[i].num_of_meals = 0;
		sim()->philos[i].ishappy = 0;
		sim()->philos[i].time_limit = sim()->start_time + sim()->time_to_die;
		i++;
	}
}
