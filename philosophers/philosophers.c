/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:30:27 by hounejja          #+#    #+#             */
/*   Updated: 2025/05/04 00:15:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*check_if_death(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (*(philo->arguments->death))
			break;

		if (philo->must_die <= time_1())
		{
			pthread_mutex_lock(philo->mutex.p);
			if (!*(philo->arguments->death))
			{
				print_msg("died\n", time_1() - philo->arguments->this_time, philo->id);
				*(philo->arguments->death) = 1;
			}
			pthread_mutex_unlock(philo->mutex.p);
			break;
		}
		else if (*(philo->full) == philo->arguments->num_of_philo)
			break;
		usleep(10);
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
	while ((*philo->arguments->death) == 0 &&
			*(philo->full) != philo->arguments->num_of_philo)
	{
		pthread_mutex_lock(&philo->mutex.fork[philo->id]);
		print('F', philo, philo->id);
		pthread_mutex_lock(&philo->mutex.fork[(philo->id + 1)
			% philo->arguments->num_of_philo]);
		print('F', philo, philo->id);
		print('E', philo, philo->id);
		philo->must_die = time_1() + philo->arguments->time_to_die;
		usleep(convert_to_misec(philo->arguments->time_to_eat));
		if (philo->arguments->num_of_times_to_eat > 0 &&
			++philo->eat_count == philo->arguments->num_of_times_to_eat)
			*(philo->full) += 1;
		pthread_mutex_unlock(&philo->mutex.fork[philo->id]);
		pthread_mutex_unlock(&philo->mutex.fork[(philo->id + 1)
			% philo->arguments->num_of_philo]);
		print('S', philo, philo->id);
		usleep(convert_to_misec(philo->arguments->time_to_sleep));
		print('T', philo, philo->id);
	}
	pthread_join(philo->alive, NULL);
	return (NULL);
}

void	init_param(t_info *info, t_philo *philo,
	pthread_mutex_t *p, pthread_mutex_t *fork)
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
		philo[i].full = &info->full;
		pthread_create(&philo[i].philo, NULL, exec, &philo[i]);
		usleep(100);
		i++;
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
	arguments.this_time = time_1();
	while (i < arguments.num_of_philo)
		pthread_mutex_init(&fork[i++], NULL);
	init_param(&arguments, philo, &p, fork);
	while (1)
	{
		if (*(philo->arguments->death) == 1	
			|| *(philo->full) == arguments.num_of_philo)
			break ;
		usleep(10);
	}
	i = 0;
	while (i < arguments.num_of_philo)
		pthread_join(philo[i++].philo, NULL);
	destroy_mutex_and_free(philo, fork);
	return (0);
}
