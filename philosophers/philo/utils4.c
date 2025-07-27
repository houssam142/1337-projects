/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssam <houssam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 23:59:31 by hounejja          #+#    #+#             */
/*   Updated: 2025/07/27 10:11:38 by houssam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_arg(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (++i <= ac)
	{
		while (av[i][++j])
		{
			if (ft_isalpha(av[i][j]))
				return (1);
		}
	}
	return (0);
}

int	even_philo(t_philo *philo, int left, int right)
{
	pthread_mutex_lock(&philo->mutex.fork[right]);
	if (is_dead(philo))
	{
		pthread_mutex_unlock(&philo->mutex.fork[right]);
		return (1);
	}
	print('F', philo, philo->id);
	pthread_mutex_lock(&philo->mutex.fork[left]);
	if (is_dead(philo))
	{
		pthread_mutex_unlock(&philo->mutex.fork[left]);
		pthread_mutex_unlock(&philo->mutex.fork[right]);
		return (1);
	}
	print('F', philo, philo->id);
	return (0);
}

int	odd_philo(t_philo *philo, int left, int right)
{
	pthread_mutex_lock(&philo->mutex.fork[left]);
	if (is_dead(philo))
	{
		pthread_mutex_unlock(&philo->mutex.fork[left]);
		return (1);
	}
	print('F', philo, philo->id);
	pthread_mutex_lock(&philo->mutex.fork[right]);
	if (is_dead(philo))
	{
		pthread_mutex_unlock(&philo->mutex.fork[right]);
		pthread_mutex_unlock(&philo->mutex.fork[left]);
		return (1);
	}
	print('F', philo, philo->id);
	return (0);
}

int	ft_usleep(int time, t_philo *philo)
{
	int	i;

	i = time_1();
	while ((time_1() - i) < time)
	{
		if (is_dead(philo))
			return (1);
		usleep(100);
	}
	return (0);
}
