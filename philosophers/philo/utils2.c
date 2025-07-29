/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssam <houssam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:03:04 by hounejja          #+#    #+#             */
/*   Updated: 2025/07/29 19:43:20 by houssam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	thinking_exec(t_philo *philo)
{
	int	think_time;

	print('T', philo, philo->id);
	think_time = philo->arguments->time_to_die - (philo->arguments->time_to_eat
			+ philo->arguments->time_to_sleep);
	if (think_time > 60)
		ft_usleep((unsigned long)think_time - 10, philo);
}

int	is_all_full(t_philo *philo)
{
	int	full;

	pthread_mutex_lock(&philo->arguments->full_lock);
	full = philo->arguments->full >= philo->arguments->num_of_philo;
	pthread_mutex_unlock(&philo->arguments->full_lock);
	return (full);
}

void	update_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->last_meal_lock);
	philo->last_meal = time_1();
	pthread_mutex_unlock(&philo->last_meal_lock);
	print('E', philo, philo->id);
	ft_usleep((unsigned long)philo->arguments->time_to_eat, philo);
	philo->eat_count++;
	if (philo->eat_count >= philo->arguments->num_of_times_to_eat)
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
