/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 23:12:10 by simao             #+#    #+#             */
/*   Updated: 2023/06/09 12:06:52 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

/*
- Returns the time in milliseconds.
*/
long long	get_time(t_data *data)
{
	struct timeval	time;
	long long		current;

	(void)data;
	gettimeofday(&time, NULL);
	current = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (current - data->start_time);
}

/*
- Sleeps in miliseconds by the given amount.
*/
void	ft_usleep(long long time)
{
	struct timeval	s_time;
	struct timeval	c_time;
	long long		start;
	long long		current;

	gettimeofday(&s_time, NULL);
	start = ((s_time.tv_usec / 1000) + (s_time.tv_sec * 1000));
	while (1)
	{
		gettimeofday(&c_time, NULL);
		current = ((c_time.tv_usec / 1000) + (c_time.tv_sec * 1000));
		if (current - start >= time)
			break ;
		usleep(50);
	}
}
