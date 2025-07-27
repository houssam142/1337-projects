/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssam <houssam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 01:14:30 by hounejja          #+#    #+#             */
/*   Updated: 2025/07/27 10:34:33 by houssam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	put_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->mutex.fork[philo->id - 1]);
	pthread_mutex_unlock(&philo->mutex.fork[(philo->id)
		% philo->arguments->num_of_philo]);
}

void	one_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->must_die_lock);
	philo->must_die = time_1() + philo->arguments->time_to_die;
	pthread_mutex_unlock(&philo->must_die_lock);
	pthread_mutex_lock(&philo->mutex.fork[philo->id - 1]);
	print('F', philo, philo->id);
	ft_usleep(philo->arguments->time_to_die, philo);
	pthread_mutex_unlock(&philo->mutex.fork[philo->id - 1]);
}

int	take_forks(t_philo *philo)
{
	int	left;
	int	right;

	left = philo->id - 1;
	right = philo->id % philo->arguments->num_of_philo;
	if (philo->id % 2 == 0)
	{
		if (even_philo(philo, left, right))
			return (1);
	}
	else
	{
		if (odd_philo(philo, left, right))
			return (1);
	}
	if (check_death_of_philo(philo))
	{
		pthread_mutex_unlock(&philo->mutex.fork[left]);
		pthread_mutex_unlock(&philo->mutex.fork[right]);
		return (1);
	}
	return (0);
}

int	time_1(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	print_msg(char *message, int time, int id)
{
	printf("%d %d %s", time, id + 1, message);
}
