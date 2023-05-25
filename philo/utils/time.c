/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:53:55 by smagalha          #+#    #+#             */
/*   Updated: 2023/05/25 12:27:15 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long int	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	sleep_ms(long int ms)
{
	long int	sleep;

	sleep = ms * 1000;
	usleep(sleep);
}
