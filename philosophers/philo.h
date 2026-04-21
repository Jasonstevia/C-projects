/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslim <jslim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 10:49:10 by jslim             #+#    #+#             */
/*   Updated: 2026/02/23 13:00:25 by jslim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_sim
{
	int				n;
	long			t_die;
	long			t_eat;
	long			t_sleep;
	int				must_eat;
	long			start_ms;
	int				stop;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mtx;
	pthread_mutex_t	state_mtx;
}	t_sim;

typedef struct s_philo
{
	int			id;
	pthread_t	th;
	int			left;
	int			right;
	long		last_meal_ms;
	int			meals_eaten;
	t_sim		*sim;
}	t_philo;

void	print_state(t_philo *philo, char *msg);
long	ft_atol(const char *ptr);
long	get_ms(void);
void	cleanup(t_philo *philo, t_sim *sim);
int		thread_create(t_philo *philo, t_sim *sim);
int		thread_join(t_philo *philo, t_sim *sim);
int		parsing(int argc, char **argv, t_sim *sim);
int		init_philo(t_philo **philo, t_sim *sim);
int		get_stop(t_sim *sim);
void	take_one_fork(t_philo *philo);
void	run_cycle(t_philo *philo);

#endif
