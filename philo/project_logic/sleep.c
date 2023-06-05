/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 21:28:12 by smagalha          #+#    #+#             */
/*   Updated: 2023/06/04 15:58:15 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	philo_zZz(t_philosopher *philo)
{
	printf("%lu %d is sleeping\n", get_time() - sim()->start_time, philo->id);
	sleep_ms(sim()->time_to_sleep);
	printf("%lu %d is thinking\n", get_time() - sim()->start_time, philo->id);
}
