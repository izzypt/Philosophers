/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:04:28 by simao             #+#    #+#             */
/*   Updated: 2023/05/22 12:54:55 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	long int	i;
	long int	j;

	i = 1;
	j = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			i = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		j = (*str - 48) + (j * 10);
		str++;
		if (i * j > 2147483647)
			return (-1);
		if (i * j < -2147483648)
			return (-1);
	}
	return (i * j);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;

	str = (unsigned char *)b;
	while (len > 0)
	{
		*str = (unsigned char)c;
		str++;
		len--;
	}
	return (b);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total_size;
	void	*dst;

	total_size = size * count;
	dst = malloc(total_size);
	if (dst == NULL)
		return (0);
	ft_memset(dst, 0, total_size);
	return (dst);
}
