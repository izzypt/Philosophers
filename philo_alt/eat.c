/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 22:41:58 by ncolomer          #+#    #+#             */
/*   Updated: 2023/06/02 17:05:07 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
- Funcao que trata da logica quando o filosofo come.
- Tranca o mutex do filosofo para que outras threads nao possam aceder.
- Muda o estado do filosofo para 1 e indica que ele esta a comer.
- Redefine o valor da ultima refeicao.
- Redefine o valor do limite para a proxima refeicao.
- Dorme a quantidade de tempo definida para a refeicao.
- Passado esse tempo destranca o mutex.
*/
void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex);
	philo->is_eating = 1;
	philo->last_eat = get_time();
	philo->limit = philo->last_eat + philo->state->time_to_die;
	display_message(philo, TYPE_EAT);
	usleep(philo->state->time_to_eat * 1000);
	philo->eat_count++;
	philo->is_eating = 0;
	pthread_mutex_unlock(&philo->mutex);
	pthread_mutex_unlock(&philo->eat_m);
}
