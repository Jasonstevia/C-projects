/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_routine_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslim <jslim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 10:54:40 by jslim             #+#    #+#             */
/*   Updated: 2026/02/23 13:18:19 by jslim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_state(t_philo *philo, char *msg)
{
	int	stop;

	pthread_mutex_lock(&philo->sim->state_mtx);
	stop = philo->sim->stop;
	pthread_mutex_unlock(&philo->sim->state_mtx);
	if (stop && msg[0] != 'd')
		return ;
	pthread_mutex_lock(&philo->sim->print_mtx);
	printf("%ld %d %s\n", get_ms() - philo->sim->start_ms, philo->id, msg);
	pthread_mutex_unlock(&philo->sim->print_mtx);
}

void	take_one_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->sim->forks[philo->left]);
	print_state(philo, "has taken a fork");
	pthread_mutex_unlock(&philo->sim->forks[philo->left]);
	usleep(philo->sim->t_die * 1000);
}

int	get_stop(t_sim *sim)
{
	int	stop;

	pthread_mutex_lock(&sim->state_mtx);
	stop = sim->stop;
	pthread_mutex_unlock(&sim->state_mtx);
	return (stop);
}

static void	take_forks(t_philo *philo)
{
	if ((philo->id % 2) == 0)
	{
		pthread_mutex_lock(&philo->sim->forks[philo->right]);
		print_state(philo, "has taken a fork");
		pthread_mutex_lock(&philo->sim->forks[philo->left]);
		print_state(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(&philo->sim->forks[philo->left]);
		print_state(philo, "has taken a fork");
		pthread_mutex_lock(&philo->sim->forks[philo->right]);
		print_state(philo, "has taken a fork");
	}
}

void	run_cycle(t_philo *philo)
{
	take_forks(philo);
	pthread_mutex_lock(&philo->sim->state_mtx);
	philo->last_meal_ms = get_ms();
	pthread_mutex_unlock(&philo->sim->state_mtx);
	print_state(philo, "is eating");
	usleep(philo->sim->t_eat * 1000);
	pthread_mutex_lock(&philo->sim->state_mtx);
	philo->meals_eaten += 1;
	pthread_mutex_unlock(&philo->sim->state_mtx);
	pthread_mutex_unlock(&philo->sim->forks[philo->left]);
	pthread_mutex_unlock(&philo->sim->forks[philo->right]);
	print_state(philo, "is sleeping");
	usleep(philo->sim->t_sleep * 1000);
	print_state(philo, "is thinking");
	if ((philo->sim->n % 2) == 1)
		usleep((philo->sim->t_eat / 2) * 1000);
}
