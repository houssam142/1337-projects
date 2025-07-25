/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssam <houssam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 23:59:31 by hounejja          #+#    #+#             */
/*   Updated: 2025/07/26 16:21:52 by houssam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_arg(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	if (ac < 5 || ac > 6)
	{
		printf("Error: wrong number of arguments\n");
		return (1);
	}
	while (++i < ac)
	{
		j = -1;
		while (av[i][++j])
		{
			if (ft_isalpha(av[i][j]))
			{
				printf("Error: arguments must be numbers\n");
				return (1);
			}
			else if (av[i][j] == '-')
				return (printf("Error: arguments must be positive\n"), 1);
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
	while (time_1() - i < time)
	{
		if (check_if_full_and_died(philo))
			return (1);
		usleep(100);
	}
	return (0);
}
