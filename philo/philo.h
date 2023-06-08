/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 17:23:12 by simao             #+#    #+#             */
/*   Updated: 2023/06/08 19:14:27 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/* Libraries */

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <limits.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdint.h>

struct	s_simulation;

/* Structs */

typedef struct t_philosopher
{
	int					id;
	int					rfork;
	int					lfork;
	int					num_of_meals;
	int					ishappy;
	long int			time_limit;
	pthread_mutex_t		philo_mutex;
	pthread_t			thread;
}	t_philosopher;

typedef struct s_simulation
{
	long int		start_time;
	int				num_of_philo;
	int				num_of_forks;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				max_meals;
	int				any_death;
	int				happy_philos;
	t_philosopher	*philos;
	pthread_mutex_t	write_mutex;
	pthread_mutex_t	time_mutex;
	pthread_mutex_t	check_mutex;
	pthread_mutex_t	*forks;
	pthread_t		*threads;
}	t_simulation;


/* Struct Getters */

t_simulation	*sim(void);

/* Init Functions */

void			init_sim(char **argv);
void			init_philos(void);
void			init_threads(void);
void			init_mutexes(int num_of_fork);

/* Init Messages */

void			print_stats(void);
void			print_message(int code, t_philosopher *philo);

/* Fork Related*/

void			take_forks(t_philosopher *philo);
void			release_forks(t_philosopher *philo);
void			eat(t_philosopher *philo);

/* Sleep Related*/

void			philo_zZz(t_philosopher *philo);

/* Util Functions */

int				ft_isdigit(int c);
int				ft_atoi(const char *str);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_calloc(size_t count, size_t size);

/*Time Function*/

long int		get_time(void);
long int		get_time_ms(void);
void			sleep_ms(long int ms);

/* Memory Related*/

void			free_and_exit(void);

/* Messages */

# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define MEALS "All Philosophers have finished eating"
# define DEAD "is dead"

#endif