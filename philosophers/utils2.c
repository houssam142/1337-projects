/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:03:04 by hounejja          #+#    #+#             */
/*   Updated: 2025/07/15 00:31:57 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_philo(t_philo *philo)
{
	int	death_val;
	int	full_val;
	int	i;

	while (1)
	{
		pthread_mutex_lock(philo->mutex.p);
		death_val = *(philo->arguments->death);
		pthread_mutex_unlock(philo->mutex.p);
		pthread_mutex_lock(&philo->arguments->full_lock);
		full_val = *(philo->full);
		pthread_mutex_unlock(&philo->arguments->full_lock);
		if (death_val == 1 || full_val == philo->arguments->num_of_philo)
			return (1);
		usleep(10);
	}
	return (0);
}

int	is_all_full(t_philo *philo)
{
	int	res;

	pthread_mutex_lock(&philo->arguments->full_lock);
	res = (*(philo->full) == philo->arguments->num_of_philo);
	pthread_mutex_unlock(&philo->arguments->full_lock);
	return (res);
}

void	update_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->must_die_lock);
	philo->must_die = time_1() + philo->arguments->time_to_die;
	pthread_mutex_unlock(&philo->must_die_lock);
	print('E', philo, philo->id);
	ft_usleep(philo->arguments->time_to_eat, philo);
	if (++philo->eat_count == philo->arguments->num_of_times_to_eat)
		increment_full(philo);
}

int	ft_isspace(char c)
{
	return (c == '\t' || c == '\r' || c == '\f' || c == '\v' || c == 32
		|| c == '\n');
}

long	ft_atoi(const char *str)
{
	int		x;
	int		sign;
	long	res;

	x = 0;
	sign = 1;
	res = 0;
	while (ft_isspace(str[x]))
		x++;
	if (str[x] == '-' || str[x] == '+')
	{
		if (str[x] == '-')
			sign *= -1;
		x++;
	}
	while (str[x] >= '0' && str[x] <= '9')
	{
		res = (res * 10) + (str[x] - 48);
		x++;
	}
	return ((res * sign));
}
