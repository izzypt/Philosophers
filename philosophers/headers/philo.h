/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:26:32 by francsan          #+#    #+#             */
/*   Updated: 2023/06/08 23:24:44 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/* libraries */

// memset
# include <string.h>
// printf
# include <stdio.h>
// malloc and free
# include <stdlib.h>
// write and usleep
# include <unistd.h>
// gettimeofday 
# include <sys/time.h>
// pthread_create, pthread_detach, pthread_join,
// pthread_mutex_init, pthread_mutex_destroy,
// pthread_mutex_lock, pthread_mutex_unlock
# include <pthread.h>

/* colors */
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define CYAN "\033[96m"
# define DEFAULT "\033[0m"

/* messages */
# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define MEALS "All Philosophers have finished eating"
# define DEAD "is dead"

/* structs */

typedef struct t_philo
{
	pthread_t	philo_thread;
	long long	last_eat;
	int			id;
	int			eat_counter;
	int			eat_lock;
	int			time_die;
	int			fork;
	int			right;
	int			left;
	int			philo_dead;
}	t_philo;

typedef struct t_data
{
	long long		start_time;
	int				num_philos;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				eat_flag;
	int				dead_flag;
	int				print_flag;
	int				max_meals;
	int				*forks;
	pthread_mutex_t	*m_fork;
	pthread_mutex_t	m_dead_philo;
	pthread_mutex_t	m_check_eat;
	pthread_mutex_t	m_counter;
	pthread_mutex_t	m_increment;
	t_philo			*philos;
}	t_data;

/* sources */

// init_rules.c
int			init_alloc(t_data *data);
void		init_philos(t_data *data);
int			init_mutexes(t_data *data);
int			init_data(t_data *data, char **argv);

// Validators
int			check_args(char **argv);

// actions.c
void		check_fork(t_data *data, t_philo *philo, int pos);
void		philo_eat(t_data *data, t_philo *philo);
void		philo_sleep(t_data *data, t_philo *philo);

// sim_utils.c
long long	get_time(t_data *r);
void		ft_usleep(long long time);
int			check_eat(t_data *r, t_philo *p);
int			check_all(t_data *r, t_philo *p);
void		free_and_destroy(t_data *r);

// simulation.c
void		philo_starve(t_data *r, t_philo *p);
void		*philo_handler(void *arg);
void		run_simulation(t_data *r);

// utils.c
int			ft_isdigit(int c);
int			ft_atoi(const char *str);
void		*ft_memset(void *b, int c, size_t len);
void		*ft_calloc(size_t count, size_t size);

#endif