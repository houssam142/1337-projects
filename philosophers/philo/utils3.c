/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssam <houssam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 21:25:50 by hounejja          #+#    #+#             */
/*   Updated: 2025/08/13 15:31:26 by houssam          ###   ########.fr       */
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
