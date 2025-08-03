/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 23:59:31 by hounejja          #+#    #+#             */
/*   Updated: 2025/08/02 02:29:59 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_arg(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	if (ac < 5)
	{
		printf("Error\nnumber of args not enough\n");
		return (1);
	}
	while (++i < ac)
	{
		j = -1;
		while (av[i][++j])
		{
			if (ft_isalpha(av[i][j]) || av[i][j] == '-')
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

int	ft_usleep(unsigned long time, t_philo *philo)
{
	unsigned long	start;

	start = time_1();
	while ((time_1() - start) < time)
	{
		pthread_mutex_lock(&philo->arguments->death_lock);
		if (*(philo->arguments->death))
		{
			pthread_mutex_unlock(&philo->arguments->death_lock);
			return (1);
		}
		pthread_mutex_unlock(&philo->arguments->death_lock);
		if (time_1() - start >= time)
			break ;
		usleep(1000);
	}
	return (0);
}
