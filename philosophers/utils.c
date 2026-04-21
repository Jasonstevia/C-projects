/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslim <jslim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 10:49:29 by jslim             #+#    #+#             */
/*   Updated: 2026/02/23 12:59:54 by jslim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_atol(const char *ptr)
{
	long	i;
	long	sign;
	long	result;

	i = 0;
	result = 0;
	sign = 1;
	while (ptr[i] == ' ' || ptr[i] == '\f' || ptr[i] == '\n'
		|| ptr[i] == '\r' || ptr[i] == '\t' || ptr[i] == '\v')
		i++;
	if (ptr[i] == '-' || ptr[i] == '+')
	{
		if (ptr[i] == '-')
			sign = -1;
		i++;
	}
	while (ptr[i] >= '0' && ptr[i] <= '9')
	{
		result = result * 10 + ptr[i] - '0';
		i++;
	}
	return (result * sign);
}

long	get_ms(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (0);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	cleanup(t_philo *philo, t_sim *sim)
{
	int	i;

	i = 0;
	while (i < sim->n)
	{
		pthread_mutex_destroy(&sim->forks[i]);
		i++;
	}
	free(sim->forks);
	pthread_mutex_destroy(&sim->print_mtx);
	pthread_mutex_destroy(&sim->state_mtx);
	free(philo);
}
