/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_routine_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslim <jslim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 10:52:58 by jslim             #+#    #+#             */
/*   Updated: 2026/02/23 13:18:35 by jslim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*start_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if ((philo->id % 2) == 0)
		usleep((philo->sim->t_eat / 2) * 1000);
	while (1)
	{
		if (get_stop(philo->sim))
			break ;
		if (philo->sim->n == 1)
			return (take_one_fork(philo), NULL);
		run_cycle(philo);
	}
	return (NULL);
}

int	thread_create(t_philo *philo, t_sim *sim)
{
	int	i;

	i = 0;
	while (i < sim->n)
	{
		if (pthread_create(&philo[i].th, NULL, start_routine, &philo[i]))
			return (1);
		i++;
	}
	return (0);
}

int	thread_join(t_philo *philo, t_sim *sim)
{
	int	i;

	i = 0;
	while (i < sim->n)
	{
		if (pthread_join(philo[i].th, NULL))
			return (1);
		i++;
	}
	return (0);
}
