/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 17:23:12 by simao             #+#    #+#             */
/*   Updated: 2023/06/06 02:50:36 by simao            ###   ########.fr       */
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
	int					lfork;
	int					rfork;
	long int			last_meal;
	int					num_of_meals;
	int					isfull;
	int					is_eating;
	long int			time_limit;
	pthread_t			thread;
	struct s_simulation	*sim;
}	t_philosopher;

typedef struct s_simulation
{
	int				game_on;
	long int		start_time;
	int				num_of_philo;
	int				num_of_forks;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				max_meals;
	int				any_death;
	int				full_philos;
	t_philosopher	*philos;
	pthread_mutex_t	write_mutex;
	pthread_mutex_t	*forks;
	pthread_t		*threads;
}	t_simulation;


/* Struct Getters */

t_simulation	*sim(void);

/* Init Functions */

void			init_sim(char **argv);
void			init_philos(void);
void			init_threads(void);
void			init_forks(int num_of_fork);

/* Init Messages */

void			print_stats(void);
void			print_message(int code, int philo_id);

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