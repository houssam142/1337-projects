/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssam <houssam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 20:00:05 by houssam           #+#    #+#             */
/*   Updated: 2025/07/25 14:19:26 by houssam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	is_dead(t_philo *philo)
{
	int	death;

	pthread_mutex_lock(philo->mutex.p);
	death = (*philo->arguments->death);
	pthread_mutex_unlock(philo->mutex.p);
	return (death);
}

int	has_eaten_enough(t_philo *philo)
{
	int	res;

	pthread_mutex_lock(&philo->eat_count_lock);
	res = (philo->eat_count == philo->arguments->num_of_times_to_eat);
	pthread_mutex_unlock(&philo->eat_count_lock);
	return (res);
}

int	should_stop(t_philo *philo)
{
	return (is_dead(philo) || is_all_full(philo));
}

int	check_if_full_and_died(t_philo *philo)
{
	pthread_mutex_lock(philo->mutex.p);
	if (*(philo->arguments->death))
	{
		pthread_mutex_unlock(philo->mutex.p);
		return (1);
	}
	pthread_mutex_unlock(philo->mutex.p);
	pthread_mutex_lock(&philo->arguments->full_lock);
	if (*(philo->full) == philo->arguments->num_of_philo)
	{
		pthread_mutex_unlock(&philo->arguments->full_lock);
		return (1);
	}
	pthread_mutex_unlock(&philo->arguments->full_lock);
	return (0);
}

int	check_death_of_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->mutex.p);
	if (*(philo->arguments->death))
	{
		pthread_mutex_unlock(philo->mutex.p);
		return (1);
	}
	pthread_mutex_unlock(philo->mutex.p);
	return (0);
}
