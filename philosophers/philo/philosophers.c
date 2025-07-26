/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:30:27 by hounejja          #+#    #+#             */
/*   Updated: 2025/07/26 21:35:59 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*check_if_death(void *arg)
{
	t_philo *philo;
	int		i;

	philo = (t_philo *)arg;
	while (1)
	{
		i = -1;
		while (++i < philo->arguments->num_of_philo)
		{
			if (check_if_full_and_died(&philo[i]))
				return (NULL);
			pthread_mutex_lock(&philo[i].must_die_lock);
			if (philo[i].must_die <= time_1())
			{
				pthread_mutex_unlock(&philo[i].must_die_lock);
				pthread_mutex_lock(philo[i].mutex.p);
				print_msg("died\n", time_1() - philo->arguments->this_time,
					philo[i].id);
				pthread_mutex_unlock(philo[i].mutex.p);
				pthread_mutex_lock(&philo->arguments->death_lock);
				*(philo->arguments->death) = 1;
				pthread_mutex_unlock(&philo->arguments->death_lock);
				return (NULL);
			}
			pthread_mutex_unlock(&philo[i].must_die_lock);
			usleep(100);
		}
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
	// if (philo->arguments->num_of_philo == 1)
	// 	return (one_philo(philo), NULL);
	while (!should_stop(philo))
	{
		if (take_forks(philo))
			return (NULL);
		update_eating(philo);
		put_forks(philo);
		if (has_eaten_enough(philo) || is_dead(philo))
			return (NULL);
		print('S', philo, philo->id);
		ft_usleep(philo->arguments->time_to_sleep, philo);
		// usleep(700);
		if (is_dead(philo))
			return (NULL);
		print('T', philo, philo->id);
		if (is_dead(philo))
			return (NULL);
	}
	return (NULL);
}

void	init_param(t_info *info, t_philo *philo, pthread_mutex_t *p,
		pthread_mutex_t *fork)
{
	int	i;

	i = 0;
	pthread_mutex_init(p, NULL);
	while (i < info->num_of_philo)
	{
		philo[i].eat_count = 0;
		philo[i].arguments = info;
		philo[i].id = i + 1;
		philo[i].mutex.fork = fork;
		philo[i].mutex.p = p;
		philo[i].arguments->death = &info->died;
		philo[i].must_die = time_1() + info->time_to_die;
		pthread_mutex_init(&philo[i].must_die_lock, NULL);
		philo[i].full = &info->full;
		i++;
	}
	i = -1;
	while (++i < info->num_of_philo)
	{
		if (pthread_create(&philo[i].philo, NULL, exec, &philo[i]))
			return ;
		// usleep(100);
	}
	death_events(philo);
	
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
	pthread_mutex_init(&arguments.full_lock, NULL);
	pthread_mutex_init(&arguments.death_lock, NULL);
	while (i < arguments.num_of_philo)
		pthread_mutex_init(&fork[i++], NULL);
	init_param(&arguments, philo, &p, fork);
	// check_philo(philo);
	pthread_create(&arguments.alive, NULL, check_if_death, philo);
	pthread_join(arguments.alive, NULL);
	i = -1;
	while (++i < arguments.num_of_philo)
		pthread_join(philo[i].philo, NULL);
	destroy_mutex_and_free(philo, fork);
	return (0);
}
