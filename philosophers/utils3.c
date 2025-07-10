/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssam <houssam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 20:00:05 by houssam           #+#    #+#             */
/*   Updated: 2025/07/10 20:04:28 by houssam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_death_of_philo(t_philo *philo, int left, int right)
{
	pthread_mutex_lock(philo->mutex.p);
	if (*(philo->arguments->death))
	{
		pthread_mutex_unlock(philo->mutex.p);
		pthread_mutex_unlock(&philo->mutex.fork[left]);
		pthread_mutex_unlock(&philo->mutex.fork[right]);
		return (1);
	}
	pthread_mutex_unlock(philo->mutex.p);
	return (0);
}
