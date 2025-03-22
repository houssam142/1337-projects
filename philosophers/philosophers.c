/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:30:27 by hounejja          #+#    #+#             */
/*   Updated: 2025/03/22 01:35:15 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*check_if_death(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	while (1)
	{
		if (philo->must_die + 5 <= time_1())
		{
			*(philo->arguments->death) = 1;
			print('D', philo, philo->id);
			exit(1);
		}
		else if (*philo->full == philo->arguments->num_of_philo)
			return (NULL);
		usleep(10);
	}
	return (NULL);
}

void	death_events(t_philo *philo)
{
	philo->must_die = time_1() + philo->arguments->time_to_die;
	pthread_create(&philo->health, NULL, check_if_death, philo);
}

void	*exec(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	death_events(philo);
	while (1)
	{
		pthread_mutex_lock(&philo->mutex.fork[philo->id]);
		print('F', philo, philo->id);
		pthread_mutex_lock(&philo->mutex.fork[(philo->id + 1)
			% philo->arguments->num_of_philo]);
		print('F', philo, philo->id);
		print('E', philo, philo->id);
		philo->must_die = time_1() + philo->arguments->time_to_die;
		usleep(convert_to_misec(philo->arguments->time_to_eat));
		if (*philo->full == philo->arguments->num_of_philo)
			return (NULL);
		pthread_mutex_unlock(&philo->mutex.fork[philo->id]);
		pthread_mutex_unlock(&philo->mutex.fork[(philo->id + 1)
			% philo->arguments->num_of_philo]);
		print('S', philo, philo->id);
		usleep(convert_to_misec(philo->arguments->time_to_sleep));
		print('T', philo, philo->id);
	}
	return (NULL);
}

void	init_param(t_info *info, t_philo *philo, pthread_mutex_t *fork,
		pthread_mutex_t *p)
{
	int	i;
	int	died;
	int	all_full;

	i = 0;
	died = 0;
	all_full = 0;
	pthread_mutex_init(p, NULL);
	while (i < info->num_of_philo)
	{
		philo[i].eat_count = 0;
		philo[i].arguments = info;
		philo[i].id = i;
		philo[i].mutex.fork = fork;
		philo[i].mutex.p = p;
		philo[i].arguments->death = &died;
		philo[i].full = &all_full;
		pthread_create(&philo[i].philo, NULL, exec, &philo[i]);
		usleep(100);
		i++;
	}
	i = 0;
	while (i < info->num_of_philo)
		pthread_join(philo[i++].philo, NULL);
}

int	main(int ac, char **av)
{
	t_philo			*philo;
	t_info			info;
	pthread_mutex_t	*fork;
	pthread_mutex_t	p;
	int				i;

	i = 0;
	if (handle_arg(&info, av, ac))
		return (1);
	philo = malloc(sizeof(t_philo) * info.num_of_philo);
	fork = malloc(sizeof(pthread_mutex_t) * (info.num_of_philo));
	if (!philo || !fork)
		return (1);
	info.this_time = time_1();
	while (i < info.num_of_philo)
		pthread_mutex_init(&fork[i++], NULL);
	init_param(&info, philo, &p, fork);
	while (1)
	{
		if (*(philo->arguments->death) == 1
			|| *(philo->full) == info.num_of_philo)
			break ;
		usleep(10);
	}
	return (destroy_mutex_and_free(philo, fork, philo), 0);
}
