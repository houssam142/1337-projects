/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 21:25:50 by hounejja          #+#    #+#             */
/*   Updated: 2025/08/11 21:25:52 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	is_dead(t_philo *philo)
{
	int	death;

	pthread_mutex_lock(&philo->arguments->death_lock);
	death = *(philo->arguments->death);
	pthread_mutex_unlock(&philo->arguments->death_lock);
	return (death);
}

int	has_eaten_enough(t_philo *philo)
{
	return (philo->eat_count == philo->arguments->num_of_times_to_eat);
}

int	check_if_full_and_died(t_philo *philo)
{
	t_info	*info;

	info = philo[0].arguments;
	if (info->num_of_times_to_eat > 0)
	{
		pthread_mutex_lock(&info->full_lock);
		if (info->full == info->num_of_philo)
		{
			pthread_mutex_unlock(&info->full_lock);
			pthread_mutex_lock(&info->death_lock);
			*(info->death) = 1;
			pthread_mutex_unlock(&info->death_lock);
			return (1);
		}
		pthread_mutex_unlock(&info->full_lock);
	}
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
