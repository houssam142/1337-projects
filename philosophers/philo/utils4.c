/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 23:59:31 by hounejja          #+#    #+#             */
/*   Updated: 2025/07/19 00:18:47 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// static int	ft_issign(int c)
// {
// 	return ((c == '-'));
// }

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

int	odd_philo(t_philo *philo, int left, int right)
{
	pthread_mutex_lock(&philo->mutex.fork[left]);
	if (is_dead(philo))
		return (pthread_mutex_unlock(&philo->mutex.fork[right]),
			pthread_mutex_unlock(&philo->mutex.fork[left]), 1);
	print('F', philo, philo->id);
	pthread_mutex_lock(&philo->mutex.fork[right]);
	if (is_dead(philo))
		return (pthread_mutex_unlock(&philo->mutex.fork[right]),
			pthread_mutex_unlock(&philo->mutex.fork[left]), 1);
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
