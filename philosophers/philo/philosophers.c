/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssam <houssam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:30:27 by hounejja          #+#    #+#             */
/*   Updated: 2025/07/26 16:38:12 by houssam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*check_if_death(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (check_if_full_and_died(philo))
			break ;
		pthread_mutex_lock(&philo->must_die_lock);
		if (philo->must_die <= time_1())
		{
			pthread_mutex_unlock(&philo->must_die_lock);
			pthread_mutex_lock(&philo->arguments->died_lock);
			if (!*(philo->arguments->death))
			{
				pthread_mutex_lock(philo->mutex.p);
				print_msg("died\n", philo, philo->id);
				*(philo->arguments->death) = 1;
				pthread_mutex_unlock(philo->mutex.p);
			}
			pthread_mutex_unlock(&philo->arguments->died_lock);
			break ;
		}
		pthread_mutex_unlock(&philo->must_die_lock);
		usleep(100);
	}
	return (NULL);
}

void	death_events(t_philo *philo)
{
	pthread_mutex_lock(&philo->must_die_lock);
	philo->must_die = time_1() + philo->arguments->time_to_die;
	pthread_mutex_unlock(&philo->must_die_lock);
}

void	*exec(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	death_events(philo);
	if (philo->arguments->num_of_philo == 1)
	return (one_philo(philo), NULL);
	while (!should_stop(philo))
	{
		if (philo->id % 2 == 1)
			usleep(1000);
		if (take_forks(philo))
			break ;
		update_eating(philo);
		put_forks(philo);
		if (has_eaten_enough(philo) || is_dead(philo))
			break ;
		print('S', philo, philo->id);
		ft_usleep(philo->arguments->time_to_sleep, philo);
		usleep(700);
		if (is_dead(philo))
			break ;
		print('T', philo, philo->id);
		if (is_dead(philo))
			break ;
	}
	return (NULL);
}

void	init_param(t_info *info, t_philo *philo, pthread_mutex_t *p,
		pthread_mutex_t *fork)
{
	int	i;

	pthread_mutex_init(p, NULL);
	pthread_mutex_init(&info->full_lock, NULL);
	pthread_mutex_init(&info->died_lock, NULL);
	i = 0;
	info->full = 0;
	info->died = 0;
	while (i < info->num_of_philo)
	{
		philo[i].eat_count = 0;
		philo[i].arguments = info;
		philo[i].id = i;
		philo[i].mutex.fork = fork;
		philo[i].mutex.p = p;
		pthread_mutex_init(&philo[i].must_die_lock, NULL);
		pthread_mutex_init(&philo[i].eat_count_lock, NULL);
		philo[i].arguments->death = &info->died;
		pthread_mutex_lock(&philo->must_die_lock);
		philo[i].must_die = time_1() + info->time_to_die;
		pthread_mutex_unlock(&philo->must_die_lock);
		philo[i].full = &info->full;
		i++;
	}
	i = -1;
	while (++i < info->num_of_philo)
	{
		pthread_create(&philo[i].philo, NULL, exec, &philo[i]);
		pthread_create(&philo[i].alive, NULL, check_if_death, &philo[i]);
		usleep(100);
	}
}

int	main(int ac, char **av)
{
	t_info			arguments;
	t_philo			*philo;
	pthread_mutex_t	*fork;
	pthread_mutex_t	p;
	int				i;

	i = 0;
	if (handle_arg(&arguments, av, ac))
		return (1);
	philo = malloc(sizeof(t_philo) * arguments.num_of_philo);
	fork = malloc(sizeof(pthread_mutex_t) * (arguments.num_of_philo));
	if (!fork || !philo)
		return (1);
	while (i < arguments.num_of_philo)
		pthread_mutex_init(&fork[i++], NULL);
	init_param(&arguments, philo, &p, fork);
	check_philo(philo);
	i = -1;
	while (++i < arguments.num_of_philo)
	{
		pthread_join(philo[i].philo, NULL);
		pthread_join(philo[i].alive, NULL);
	}
	destroy_mutex_and_free(philo, fork);
	return (0);
}
