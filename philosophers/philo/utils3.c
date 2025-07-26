/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 20:00:05 by houssam           #+#    #+#             */
/*   Updated: 2025/07/26 21:28:24 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	is_dead(t_philo *philo)
{
	int	death;

	pthread_mutex_lock(&philo->arguments->death_lock);
	death = (*philo->arguments->death);
	pthread_mutex_unlock(&philo->arguments->death_lock);
	return (death);
}

int	has_eaten_enough(t_philo *philo)
{
	return (philo->eat_count == philo->arguments->num_of_times_to_eat);
}

int	should_stop(t_philo *philo)
{
	return (is_dead(philo) || is_all_full(philo));
}

int	check_if_full_and_died(t_philo *philo)
{
	pthread_mutex_lock(&philo->arguments->death_lock);
	if (*(philo->arguments->death))
	{
		pthread_mutex_unlock(&philo->arguments->death_lock);
		return (1);
	}
	pthread_mutex_unlock(&philo->arguments->death_lock);
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
	pthread_mutex_lock(&philo->arguments->death_lock);
	if (*(philo->arguments->death))
	{
		pthread_mutex_unlock(&philo->arguments->death_lock);
		return (1);
	}
	pthread_mutex_unlock(&philo->arguments->death_lock);
	return (0);
}
