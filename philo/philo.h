/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 17:23:12 by simao             #+#    #+#             */
/*   Updated: 2023/05/22 13:08:43 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <limits.h>
# include <pthread.h>

/* STRUCTS */
typedef struct s_simulation
{
	int	number_of_philosophers;
	int	number_of_forks;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philosopher_must_eat;
}	t_simulation;

typedef struct t_philosopher
{
	int	num;
}	t_philosopher;

/* Fetch structs */
t_simulation	*sim(void);
/* Simulation related */
void			start_simulation(char **argv);
/* Utils */
int				ft_isdigit(int c);
int				ft_atoi(const char *str);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_calloc(size_t count, size_t size);

#endif