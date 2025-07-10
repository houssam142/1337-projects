/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssam <houssam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:30:27 by hounejja          #+#    #+#             */
/*   Updated: 2025/07/10 17:42:59 by houssam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*check_if_death(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		pthread_mutex_lock(philo->mutex.p);
		if (*(philo->arguments->death))
		{
			pthread_mutex_unlock(philo->mutex.p);
			break ;
		}
		pthread_mutex_unlock(philo->mutex.p);
		pthread_mutex_lock(&philo->arguments->full_lock);
		if (*(philo->full) == philo->arguments->num_of_philo)
		{
			pthread_mutex_unlock(&philo->arguments->full_lock);
			break ;
		}
		pthread_mutex_unlock(&philo->arguments->full_lock);
		pthread_mutex_lock(&philo->must_die_lock);
		if (philo->must_die <= time_1())
		{
			pthread_mutex_unlock(&philo->must_die_lock);
			pthread_mutex_lock(philo->mutex.p);
			if (!*(philo->arguments->death))
			{
				print_msg("died\n", time_1() - philo->arguments->this_time,
					philo->id);
				*(philo->arguments->death) = 1;
			}
			pthread_mutex_unlock(philo->mutex.p);
			break ;
		}
		pthread_mutex_unlock(&philo->must_die_lock);
		usleep(100);
	}
	return (NULL);
}

void	death_events(t_philo *philo)
{
	philo->must_die = time_1() + philo->arguments->time_to_die;
	pthread_create(&philo->alive, NULL, check_if_death, philo);
}

void	*exec(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	death_events(philo);
	if (philo->arguments->num_of_philo == 1)
		return (one_philo(philo), NULL);
	while ((*philo->arguments->death) == 0 && !is_all_full(philo))
	{
		if (take_forks(philo))
			break ;
		update_eating(philo);
		put_forks(philo);
		if (philo->eat_count == philo->arguments->num_of_times_to_eat
			|| *(philo->arguments->death))
			break ;
		print('S', philo, philo->id);
		usleep(convert_to_misec(philo->arguments->time_to_sleep));
		if (*(philo->arguments->death))
			break ;
		print('T', philo, philo->id);
		if (*(philo->arguments->death))
			break ;
	}
	return (pthread_join(philo->alive, NULL), NULL);
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
		philo[i].id = i;
		philo[i].mutex.fork = fork;
		philo[i].mutex.p = p;
		philo[i].arguments->death = &info->died;
		pthread_mutex_init(&philo[i].must_die_lock, NULL);
		philo[i].full = &info->full;
		i++;
	}
	i = -1;
	while (++i < info->num_of_philo)
	{
		pthread_create(&philo[i].philo, NULL, exec, &philo[i]);
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
	pthread_mutex_init(&arguments.full_lock, NULL);
	while (i < arguments.num_of_philo)
		pthread_mutex_init(&fork[i++], NULL);
	init_param(&arguments, philo, &p, fork);
	while (1)
	{
		pthread_mutex_lock(&philo->arguments->full_lock);
		if (*(philo->arguments->death) == 1
			|| *(philo->full) == arguments.num_of_philo)
		{
			pthread_mutex_unlock(&philo->arguments->full_lock);
			break ;
		}
		pthread_mutex_unlock(&philo->arguments->full_lock);
		usleep(10);
	}
	i = -1;
	while (++i < arguments.num_of_philo)
		pthread_join(philo[i].philo, NULL);
	return (destroy_mutex_and_free(philo, fork), 0);
}
