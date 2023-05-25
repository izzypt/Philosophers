/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 17:23:12 by simao             #+#    #+#             */
/*   Updated: 2023/05/25 13:37:22 by simao            ###   ########.fr       */
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

/* Structs */
typedef struct t_philosopher
{
	int			id;
	long int	last_meal;
	int			dead;
}	t_philosopher;

typedef struct s_simulation
{
	long int		start_time;
	int				number_of_philosophers;
	int				number_of_forks;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	pthread_t		*threads;
	t_philosopher	*philosophers;
}	t_simulation;


/* Struct Getters */
t_simulation	*sim(void);

/* Simulation Related Functions */
void			start_simulation(char **argv);
void			create_philos(void);
void			create_threads(void);

/* Util Functions */
int				ft_isdigit(int c);
int				ft_atoi(const char *str);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_calloc(size_t count, size_t size);

/*Time Function*/
long int		get_time(void);
void			sleep_ms(long int ms);

/* Messages */
# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define MEALS "All Philosophers have finished eating"
# define DEAD "is dead"

#endif