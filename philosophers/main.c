/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslim <jslim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 10:48:59 by jslim             #+#    #+#             */
/*   Updated: 2026/02/23 12:58:51 by jslim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	set_stop(t_sim *sim)
{
	pthread_mutex_lock(&sim->state_mtx);
	sim->stop = 1;
	pthread_mutex_unlock(&sim->state_mtx);
}

static int	check_philo(t_philo *philo, int *count)
{
	long	last_meal_ms;
	int		meals_eaten;

	pthread_mutex_lock(&philo->sim->state_mtx);
	last_meal_ms = philo->last_meal_ms;
	meals_eaten = philo->meals_eaten;
	pthread_mutex_unlock(&philo->sim->state_mtx);
	if ((get_ms() - last_meal_ms) >= philo->sim->t_die)
		return (set_stop(philo->sim), print_state(philo, "died"), 1);
	if (philo->sim->must_eat != -1 && meals_eaten >= philo->sim->must_eat)
		(*count)++;
	return (0);
}

void	monitor(t_philo *philo, t_sim *sim)
{
	int	i;
	int	count;

	while (!get_stop(sim))
	{
		i = 0;
		count = 0;
		while (i < sim->n)
			if (check_philo(&philo[i++], &count))
				return ;
		if (sim->must_eat != -1 && count == sim->n)
			return (set_stop(sim));
		usleep(1000);
	}
}

int	main(int argc, char **argv)
{
	t_sim	sim;
	t_philo	*philo;

	if (parsing(argc, argv, &sim))
		return (1);
	if (init_philo(&philo, &sim))
		return (1);
	if (thread_create(philo, &sim))
		return (1);
	monitor(philo, &sim);
	if (thread_join(philo, &sim))
		return (1);
	cleanup(philo, &sim);
	return (0);
}
