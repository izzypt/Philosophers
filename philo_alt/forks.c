/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 22:40:23 by ncolomer          #+#    #+#             */
/*   Updated: 2023/06/02 17:23:09 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->state->forks_m[philo->lfork]);
	display_message(philo, TYPE_FORK);
	pthread_mutex_lock(&philo->state->forks_m[philo->rfork]);
	display_message(philo, TYPE_FORK);
}

void	clean_forks(t_philo *philo)
{
	display_message(philo, TYPE_SLEEP);
	pthread_mutex_unlock(&philo->state->forks_m[philo->lfork]);
	pthread_mutex_unlock(&philo->state->forks_m[philo->rfork]);
	usleep(philo->state->time_to_sleep * 1000);
}
