/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslim <jslim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 10:48:49 by jslim             #+#    #+#             */
/*   Updated: 2026/02/23 14:05:01 by jslim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_valid_number(char *arg)
{
	int	i;

	i = 0;
	if (!arg || !arg[0])
		return (0);
	while (arg[i])
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	check_inputs(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!is_valid_number(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

int	parsing(int argc, char **argv, t_sim *sim)
{
	if ((argc != 5 && argc != 6) || !check_inputs(argc, argv))
		return (1);
	sim->n = ft_atol(argv[1]);
	sim->t_die = ft_atol(argv[2]);
	sim->t_eat = ft_atol(argv[3]);
	sim->t_sleep = ft_atol(argv[4]);
	sim->stop = 0;
	sim->start_ms = get_ms();
	if (argc == 6)
		sim->must_eat = ft_atol(argv[5]);
	else
		sim->must_eat = -1;
	if (sim->n <= 0 || sim->t_die <= 0
		|| sim->t_eat <= 0 || sim->t_sleep <= 0)
		return (1);
	if (argc == 6 && sim->must_eat <= 0)
		return (1);
	return (0);
}

static int	init_sim(t_sim *sim)
{
	int	i;

	i = 0;
	sim->forks = malloc (sizeof(pthread_mutex_t) * sim->n);
	if (!sim->forks)
		return (1);
	while (i < sim->n)
	{
		if (pthread_mutex_init(&sim->forks[i], NULL))
			return (1);
		i++;
	}
	if (pthread_mutex_init(&sim->print_mtx, NULL))
		return (1);
	if (pthread_mutex_init(&sim->state_mtx, NULL))
		return (1);
	return (0);
}

int	init_philo(t_philo **philo, t_sim *sim)
{
	int	i;

	i = 0;
	if (init_sim(sim))
		return (1);
	*philo = malloc (sizeof(t_philo) * sim->n);
	if (!*philo)
		return (1);
	while (i < sim->n)
	{
		(*philo)[i].left = i;
		(*philo)[i].id = i + 1;
		(*philo)[i].right = (i + 1) % sim->n;
		(*philo)[i].last_meal_ms = sim->start_ms;
		(*philo)[i].meals_eaten = 0;
		(*philo)[i].sim = sim;
		i++;
	}
	return (0);
}
