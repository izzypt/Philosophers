/*
- Esta função deve trancar os garfos correspondentes ao filosofo que a executar.
- Quando o filosofo tiver trancado os garfos, ele deve comer.
*/
void	take_forks(t_philosopher *philo)
{
	if (sim()->num_of_philo == 1)
	{
		sleep_ms(sim()->time_to_die);
		print_message(1, philo->id);
		return ;
	}
	pthread_mutex_lock(&sim()->forks[philo->rfork]);
	pthread_mutex_lock(&sim()->forks[philo->lfork]);
	pthread_mutex_lock(&philo->philo_mutex);
	philo->time_limit = get_time() + sim()->time_to_die;
	pthread_mutex_unlock(&philo->philo_mutex);
	print_message(3, philo->id);
	eat(philo);
}

void	eat(t_philosopher *philo)
{
	print_message(4, philo->id);
	philo->num_of_meals++;
	sleep_ms(sim()->time_to_eat);
	release_forks(philo);
}

void	release_forks(t_philosopher *philo)
{
	pthread_mutex_unlock(&sim()->forks[philo->lfork]);
	pthread_mutex_unlock(&sim()->forks[philo->rfork]);
	print_message(5, philo->id);
	sleep_ms(sim()->time_to_sleep);
	print_message(6, philo->id);
}


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
	exit(0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 22:06:23 by simao             #+#    #+#             */
/*   Updated: 2023/06/07 22:31:39 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/*
- Esta função deve trancar os garfos correspondentes ao filosofo que a executar.
- Quando o filosofo tiver trancado os garfos, ele deve comer.
*/
void	take_forks(t_philosopher *philo)
{
	if (sim()->num_of_philo == 1)
	{
		sleep_ms(sim()->time_to_die);
		print_message(1, philo->id);
		return ;
	}
	pthread_mutex_lock(&sim()->forks[philo->rfork]);
	pthread_mutex_lock(&sim()->forks[philo->lfork]);
	pthread_mutex_lock(&philo->philo_mutex);
	philo->time_limit = get_time() + sim()->time_to_die;
	pthread_mutex_unlock(&philo->philo_mutex);
	print_message(3, philo->id);
	eat(philo);
}

void	eat(t_philosopher *philo)
{
	print_message(4, philo->id);
	philo->num_of_meals++;
	sleep_ms(sim()->time_to_eat);
	release_forks(philo);
}

void	release_forks(t_philosopher *philo)
{
	pthread_mutex_unlock(&sim()->forks[philo->lfork]);
	pthread_mutex_unlock(&sim()->forks[philo->rfork]);
	print_message(5, philo->id);
	sleep_ms(sim()->time_to_sleep);
	print_message(6, philo->id);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:03:24 by simao             #+#    #+#             */
/*   Updated: 2023/06/07 22:04:14 by simao            ###   ########.fr       */
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

	i = 0;
	sim()->philos = malloc(sizeof(t_philosopher) * sim()->num_of_philo);
	printf("| Creating philos...                                         |\n");
	while (i < sim()->num_of_philo)
	{
		sim()->philos[i].id = i + 1;
		sim()->philos[i].rfork = i;
		sim()->philos[i].lfork = ((i + 1) % sim()->num_of_philo);
		sim()->philos[i].num_of_meals = 0;
		sim()->philos[i].ishappy = 0;
		sim()->philos[i].time_limit = sim()->start_time + sim()->time_to_die;
		i++;
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:23:13 by simao             #+#    #+#             */
/*   Updated: 2023/06/07 23:05:23 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/*
- Print a table with the simulation information when it starts.
*/
void	print_stats(void)
{
	printf("==============================================================\n");
	printf("|                    Philosophers Simulation                 |\n");
	printf("==============================================================\n");
	printf("|                Start : %ld                                   |\n", \
	sim()->start_time - sim()->start_time);
	printf("|                Number of philosophers : %d                  |\n", \
	sim()->num_of_philo);
	printf("|                Time to die : %d                           |\n", \
	sim()->time_to_die);
	printf("|                Time to eat : %d                           |\n", \
	sim()->time_to_eat);
	printf("|                Time to sleep : %d                         |\n", \
	sim()->time_to_sleep);
	printf("==============================================================\n");
}

void	print_message(int code, int philo_id)
{
	pthread_mutex_lock(&sim()->write_mutex);
	if (code == 1 && !sim()->any_death)
	{
		printf("%lu %d died.\n", get_time() - sim()->start_time, philo_id);
		sim()->any_death = 1;
	}
	if (code == 2 && !sim()->any_death)
		printf("Philo %d is full.\n", philo_id);
	if (code == 3 && !sim()->any_death)
		printf("%lu %d took a fork\n", get_time() - sim()->start_time, philo_id);
	if (code == 4 && !sim()->any_death)
		printf("%lu %d is eating\n", get_time() - sim()->start_time, philo_id);
	if (code == 5 && !sim()->any_death)
		printf("%lu %d is sleeping\n", get_time() - sim()->start_time, philo_id);
	if (code == 6 && !sim()->any_death)
		printf("%lu %d is thinking\n", get_time() - sim()->start_time, philo_id);
	pthread_mutex_unlock(&sim()->write_mutex);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:32:50 by smagalha          #+#    #+#             */
/*   Updated: 2023/06/07 22:28:54 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/*
- Esta função aloca memoria para o array de mutexes dos garfos.
- Cria e inicia um nº de mutex igual ao nº de filosofos.
*/
void	init_mutexes(int num_of_fork)
{
	int				i;
	pthread_mutex_t	*forks;

	i = 0;
	printf("| Creating forks...                                          |\n");
	sim()->forks = malloc(num_of_fork * sizeof(pthread_mutex_t));
	forks = sim()->forks;
	while (i < num_of_fork)
	{
		pthread_mutex_init(&forks[i], NULL);
		pthread_mutex_init(&sim()->philos[i].philo_mutex, NULL);
		i++;
	}
	pthread_mutex_init(&sim()->write_mutex, NULL);
	pthread_mutex_init(&sim()->time_mutex, NULL);
	pthread_mutex_init(&sim()->check_mutex, NULL);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 22:05:12 by simao             #+#    #+#             */
/*   Updated: 2023/06/07 23:05:54 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"
/*
- Monitoriza cada um dos filosofos a cada 5 ms.
- Se o tempo actual for superior ao limite para comer o program termina,
*/
void	*monitor(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	while (1)
	{
		pthread_mutex_lock(&philo->philo_mutex);
		if (get_time() > philo->time_limit)
		{
			pthread_mutex_unlock(&philo->philo_mutex);
			pthread_mutex_lock(&philo->philo_mutex);
			if (philo->ishappy)
			{
				pthread_mutex_unlock(&philo->philo_mutex);
				break ;
			}	
			print_message(1, philo->id);
			pthread_mutex_unlock(&philo->philo_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->philo_mutex);
	}
	return (NULL);
}

/*
- This is the thread handler.
- The first function ran when the thread is created.
- It adds a delay to the even number of philosophers.
- Even philosophers threads will arrive later than uneven threads.
*/
void	*t_handler(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	pthread_create(&philo->thread, NULL, monitor, (void *)philo);
	if (philo->id % 2 == 0)
		sleep_ms(10);
	while (1)
	{
		pthread_mutex_lock(&sim()->check_mutex);
		if (sim()->any_death)
		{
			pthread_mutex_unlock(&sim()->check_mutex);
			break ;
		}	
		pthread_mutex_unlock(&sim()->check_mutex);
		if (sim()->max_meals > 0 && (philo->num_of_meals == sim()->max_meals))
		{
			pthread_mutex_lock(&philo->philo_mutex);
			philo->ishappy = 1;
			pthread_mutex_unlock(&philo->philo_mutex);
			pthread_mutex_lock(&sim()->check_mutex);
			sim()->happy_philos += 1;
			pthread_mutex_unlock(&sim()->check_mutex);
			print_message(2, philo->id);
			break ;
		}
		take_forks(philo);
	}	
	return (NULL);
}

/*
- Aloca memoria necessaria para cada thread.
- Cria uma thread por cada filosofo.
- Espera que cada thread termine antes de terminar a execucao.
*/
void	init_threads(void)
{
	int			i;
	pthread_t	*threads;

	printf("| Creating threads...                                        |\n");
	printf("==============================================================\n");
	i = 0;
	sim()->threads = malloc(sim()->num_of_philo * sizeof(pthread_t));
	threads = sim()->threads;
	sim()->start_time = get_time();
	while (i < sim()->num_of_philo)
	{
		pthread_create(&threads[i], NULL, t_handler, (void *)&sim()->philos[i]);
		i++;
	}
}
