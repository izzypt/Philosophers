/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 19:26:46 by ncolomer          #+#    #+#             */
/*   Updated: 2023/06/02 16:14:57 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
- Inicia os mutexes da struct state
- Aloca memoria para o mutex de cada garfo e inicia esse mutex.
*/
static int	init_mutexes(t_state *state)
{
	int	i;

	pthread_mutex_init(&state->write_m, NULL);
	pthread_mutex_init(&state->somebody_dead_m, NULL);
	pthread_mutex_lock(&state->somebody_dead_m);
	state->forks_m = \
	(pthread_mutex_t *)malloc(sizeof(*(state->forks_m)) * state->num_philos);
	i = 0;
	while (i < state->num_philos)
		pthread_mutex_init(&state->forks_m[i++], NULL);
	return (0);
}

/*
- Atribui os valores iniciais a cada filosofo
- Tambem inicia os mutexes associados a cada filosofo.
*/
static void	init_philos(t_state *state)
{
	int	i;

	i = 0;
	while (i < state->num_philos)
	{
		state->philos[i].is_eating = 0;
		state->philos[i].position = i;
		state->philos[i].lfork = i;
		state->philos[i].rfork = (i + 1) % state->num_philos;
		state->philos[i].eat_count = 0;
		state->philos[i].state = state;
		pthread_mutex_init(&state->philos[i].mutex, NULL);
		pthread_mutex_init(&state->philos[i].eat_m, NULL);
		pthread_mutex_lock(&state->philos[i].eat_m);
		i++;
	}
}

/*
 - Atribui os valores iniciais à struct state
 - ALoca memoria suficiente para o numero de filosofos.
 - Chama a funcao init_philos
*/
int	init(t_state *state, int argc, char const **argv)
{
	state->num_philos = ft_atoi(argv[1]);
	state->time_to_die = ft_atoi(argv[2]);
	state->time_to_eat = ft_atoi(argv[3]);
	state->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		state->must_eat_count = ft_atoi(argv[5]);
	else
		state->must_eat_count = 0;
	state->forks_m = NULL;
	state->philos = \
	(t_philo *)malloc(sizeof(*(state->philos)) * state->num_philos);
	init_philos(state);
	return (init_mutexes(state));
}
