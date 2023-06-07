/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:53:55 by smagalha          #+#    #+#             */
/*   Updated: 2023/06/07 23:02:49 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long int	get_time(void)
{
	struct timeval	time;

	pthread_mutex_lock(&sim()->time_mutex);
	gettimeofday(&time, NULL);
	pthread_mutex_unlock(&sim()->time_mutex);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

long int	get_time_ms(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_usec / 1000));
}

/*
- Sleeps by the given time in ms
*/
void	sleep_ms(long int ms)
{
	long int	sleep;

	sleep = ms * 1000;
	usleep(sleep);
}
