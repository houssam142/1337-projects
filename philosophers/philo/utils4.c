/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssam <houssam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 23:59:31 by hounejja          #+#    #+#             */
/*   Updated: 2025/07/19 06:56:43 by houssam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	odd_philo(t_philo *philo, int left, int right)
{
	pthread_mutex_lock(&philo->mutex.fork[left]);
	if (is_dead(philo))
	{
		pthread_mutex_unlock(&philo->mutex.fork[right]);
		pthread_mutex_unlock(&philo->mutex.fork[left]);
		return (1);
	}
	print('F', philo, philo->id);
	pthread_mutex_lock(&philo->mutex.fork[right]);
	if (is_dead(philo))
	{
		pthread_mutex_unlock(&philo->mutex.fork[left]);
		pthread_mutex_unlock(&philo->mutex.fork[right]);
		return (1);
	}
	print('F', philo, philo->id);
	return (0);
}

int	ft_usleep(int time, t_philo *philo)
{
	int	i;

	i = time_1();
	while (time_1() - i < time)
	{
		if (check_if_full_and_died(philo))
			return (1);
		usleep(100);
	}
	return (0);
}
