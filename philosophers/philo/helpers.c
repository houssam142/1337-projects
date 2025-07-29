/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssam <houssam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 01:14:30 by hounejja          #+#    #+#             */
/*   Updated: 2025/07/29 18:52:53 by houssam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	take_forks(t_philo *philo)
{
	int	left;
	int	right;

	left = philo->id;
	right = (philo->id + 1) % philo->arguments->num_of_philo;
	if (philo->id % 2 == 0)
	{
		if (even_philo(philo, left, right))
			return (1);
	}
	else
	{
		usleep(100);
		if (odd_philo(philo, left, right))
			return (1);
	}
	return (0);
}

void	put_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->mutex.fork[philo->id]);
	pthread_mutex_unlock(&philo->mutex.fork[(philo->id + 1)
		% philo->arguments->num_of_philo]);
}

void	one_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->last_meal_lock);
	philo->last_meal = time_1();
	pthread_mutex_unlock(&philo->last_meal_lock);
	pthread_mutex_lock(&philo->mutex.fork[philo->id]);
	print('F', philo, philo->id);
	ft_usleep(philo->arguments->time_to_die, philo);
	pthread_mutex_unlock(&philo->mutex.fork[philo->id]);
}

unsigned long	time_1(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (((tv.tv_sec * 1000) + (tv.tv_usec / 1000)));
}

void	print_msg(char *message, int time, int id)
{
	printf("%d %d %s", time, id + 1, message);
}
