/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 01:14:30 by hounejja          #+#    #+#             */
/*   Updated: 2025/04/27 21:41:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	put_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->mutex.fork[philo->id]);
	pthread_mutex_unlock(&philo->mutex.fork[(philo->id + 1)
		% philo->arguments->num_of_philo]);
}

void	one_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex.fork[philo->id]);
	print('F', philo, philo->id);
	usleep(philo->arguments->time_to_die);
	pthread_mutex_unlock(&philo->mutex.fork[philo->id]);
}

int	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex.fork[philo->id]);
	print('F', philo, philo->id);
	pthread_mutex_lock(&philo->mutex.fork
	[(philo->id + 1) % philo->arguments->num_of_philo]);
	if (*(philo->arguments->death))
	{
		pthread_mutex_unlock(&philo->mutex.fork[philo->id]);
		pthread_mutex_unlock(&philo->mutex.fork[(philo->id + 1)
			% philo->arguments->num_of_philo]);
		return (1);
	}
	print('F', philo, philo->id);
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
	printf("%d ms %d %s", time, id, message);
}
