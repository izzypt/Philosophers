/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:30:46 by ncolomer          #+#    #+#             */
/*   Updated: 2023/06/02 17:00:32 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
- Esta função apenas vai ser chamada se state->must_eat_count for maior que 0.
- Isto é, se for definido um limite para o nº de vezes que cada philo deve comer.
- Vai trancar o eat_mutex de cada filosofo esse numero de vezes.
- Contabilize o nº de refeicoes.
*/
static void	*monitor_count(void *state_v)
{
	t_state	*state;
	int		i;
	int		total;

	state = (t_state *)state_v;
	total = 0;
	while (total < state->must_eat_count)
	{
		i = 0;
		while (i < state->num_philos)
			pthread_mutex_lock(&state->philos[i++].eat_m);
		total++;
	}
	display_message(&state->philos[0], TYPE_OVER);
	pthread_mutex_unlock(&state->somebody_dead_m);
	return ((void *)0);
}

/*
- Esta função é chamada pela routine().
- Verifica a cada segundo se o filosofo nao esta a comer
- E verifica se ainda está dentro do tempo limite para comer.
- Caso o tempo limite para comer tenha sido excedido, o loop quebra.
*/
static void	*monitor(void *philo_v)
{
	t_philo		*philo;

	philo = (t_philo *)philo_v;
	while (1)
	{
		pthread_mutex_lock(&philo->mutex);
		if (!philo->is_eating && get_time() > philo->limit)
		{
			display_message(philo, TYPE_DIED);
			pthread_mutex_unlock(&philo->mutex);
			pthread_mutex_unlock(&philo->state->somebody_dead_m);
			return ((void *)0);
		}
		pthread_mutex_unlock(&philo->mutex);
		usleep(1000);
	}
}

/*
- 1ª funcao a ser chamada quando iniciamos a thread.
- Define a ultima vez em que o filosofo comeu.
- Define o tempo limite ate ao qual o filosofo tem que voltar a comer.
- Cria uma nova thread em paralelo que verifica se o filosofo ainda pode comer.
*/
static void	*routine(void *philo_v)
{
	t_philo		*philo;
	pthread_t	tid;

	philo = (t_philo *)philo_v;
	philo->last_eat = get_time();
	philo->limit = philo->last_eat + philo->state->time_to_die;
	pthread_create(&tid, NULL, &monitor, philo_v);
	pthread_detach(tid);
	while (1)
	{
		take_forks(philo);
		eat(philo);
		clean_forks(philo);
		display_message(philo, TYPE_THINK);
	}
	return ((void *)0);
}

/*
- Define o tempo de inicio da simulação em "state->start = get_time();"
- Cria uma nova thread por cada filosofo que vai correr a funcao routine().
- Se definido um limite de refeicoes, corre monitor_count() tambem.
*/
static int	start_threads(t_state *state)
{
	int			i;
	pthread_t	tid;
	void		*philo;

	state->start = get_time();
	if (state->must_eat_count > 0)
	{
		if (pthread_create(&tid, NULL, &monitor_count, (void *)state) != 0)
			return (1);
		pthread_detach(tid);
	}
	i = 0;
	while (i < state->num_philos)
	{
		philo = (void *)(&state->philos[i]);
		pthread_create(&tid, NULL, &routine, philo);
		pthread_detach(tid);
		usleep(100);
		i++;
	}
	return (0);
}

/*
Main:
- verifica se o nº de argumentos fornecido ao programa é o esperado.
- Inicia a struct state e fornece-lhe os valores dos argumentos -> init().
- Inicia as threads - uma por cada filósofo -> start_threads().
*/
int	main(int argc, char const **argv)
{
	t_state	state;

	if (argc < 5 || argc > 6)
		return (exit_error("error: bad arguments\n"));
	init(&state, argc, argv);
	start_threads(&state);
	pthread_mutex_lock(&state.somebody_dead_m);
	pthread_mutex_unlock(&state.somebody_dead_m);
	clear_state(&state);
	return (0);
}
