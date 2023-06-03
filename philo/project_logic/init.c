/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagalha <smagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:03:24 by simao             #+#    #+#             */
/*   Updated: 2023/06/03 21:09:51 by smagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/*
- Esta função inicia a simulação.
- Guarda os valores dos argumentos na struct.
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
	if (argv[5])
		sim()->max_meals = ft_atoi(argv[5]);
	printf("Checking if args were correctly stored in struct: \n");
	printf("================================================================\n");
	printf("start_time = %ld\n", sim()->start_time);
	printf("num_of_philo = %d\n", sim()->num_of_philo);
	printf("time_to_eat = %d\n", sim()->time_to_eat);
	printf("time_to_sleep = %d\n", sim()->time_to_sleep);
	printf("time_to_die = %d\n", sim()->time_to_die);
	printf("time limit = %ld\n", sim()->start_time + sim()->time_to_eat);
	printf("================================================================\n");
	init_forks(sim()->num_of_philo);
	init_philos();
}

/*
- Esta função aloca memoria necessaria para o array de filosofos.
- Atribui a cada filo um id, os garfos que pode segurar e o nº de refeicoes.
- No, fim chama a função necessaria para criar as threads.
*/
void	init_philos(void)
{
	int	i;

	i = 0;
	sim()->philos = malloc(sizeof(t_philosopher) * sim()->num_of_philo);
	printf("Creating philos...\n");
	while (i < sim()->num_of_philo)
	{
		sim()->philos[i].id = i + 1;
		sim()->philos[i].lfork = i;
		sim()->philos[i].rfork = ((i + 1) % sim()->num_of_philo);
		sim()->philos[i].num_of_meals = 0;
		sim()->philos[i].time_limit = sim()->start_time + sim()->time_to_eat;
		i++;
	}
	init_threads();
}

/*
- Esta função aloca memoria para o array de mutexes dos garfos.
- Inicia um nº de mutex igual ao nº de filosofos.
*/
void	init_forks(int num_of_fork)
{
	int				i;
	pthread_mutex_t	*forks;

	i = 0;
	printf("Creating forks...\n");
	sim()->forks = malloc(num_of_fork * sizeof(pthread_mutex_t));
	forks = sim()->forks;
	while (i < num_of_fork)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}
