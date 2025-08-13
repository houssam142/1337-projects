/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssam <houssam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 02:12:24 by hounejja          #+#    #+#             */
/*   Updated: 2025/08/13 10:43:35 by houssam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	monitor_helper(t_philo *philo, int i)
{
	pthread_mutex_lock(philo->mutex.p);
	pthread_mutex_lock(&philo->arguments->death_lock);
	if (!(*philo->arguments->death))
	{
		print_msg("died\n", time_1() - philo->arguments->this_time,
			philo[i].id);
		*philo->arguments->death = 1;
	}
	pthread_mutex_unlock(&philo->arguments->death_lock);
	pthread_mutex_unlock(philo->mutex.p);
}

void	increment_full(t_philo *philo)
{
	pthread_mutex_lock(&philo->arguments->full_lock);
	*(philo->full) += 1;
	pthread_mutex_unlock(&philo->arguments->full_lock);
}

int	handle_arg(t_info *arg, char **av, int ac)
{
	if (check_arg(ac, av))
		return (1);
	if (ft_atoi(av[1]) > 200)
	{
		printf("Error\narguments execeed requirements\n");
		return (1);
	}
	arg->num_of_philo = ft_atoi(av[1]);
	arg->time_to_die = ft_atoi(av[2]);
	arg->time_to_eat = ft_atoi(av[3]);
	arg->time_to_sleep = ft_atoi(av[4]);
	if (arg->num_of_philo <= 0 || arg->time_to_die <= 0 || arg->time_to_eat <= 0
		|| arg->time_to_sleep <= 0)
		return (printf("Error\ninvalid number\n"), 1);
	if (ac == 6)
	{
		arg->num_of_times_to_eat = ft_atoi(av[5]);
		if (arg->num_of_times_to_eat > 2147483647
			|| arg->num_of_times_to_eat <= 0)
		{
			printf("Error\nmore or not enough times to eat\n");
			return (1);
		}
	}
	return (0);
}

void	print(char c, t_philo *philo, int id)
{
	unsigned long	timestamp;

	pthread_mutex_lock(philo->mutex.p);
	pthread_mutex_lock(&philo->arguments->death_lock);
	if (!*(philo->arguments->death))
	{
		timestamp = time_1() - philo->arguments->this_time;
		if (c == 'F')
			printf("%ld %d has taken a fork\n", timestamp, id + 1);
		else if (c == 'E')
		{
			printf("%ld %d is eating\n", timestamp, id + 1);
			philo->eat_count++;
		}
		else if (c == 'S')
			printf("%ld %d is sleeping\n", timestamp, id + 1);
		else if (c == 'T')
			printf("%ld %d is thinking\n", timestamp, id + 1);
	}
	pthread_mutex_unlock(&philo->arguments->death_lock);
	pthread_mutex_unlock(philo->mutex.p);
}

void	destroy_mutex_and_free(t_philo *philo, pthread_mutex_t *fork)
{
	int	i;

	i = -1;
	while (++i < philo->arguments->num_of_philo)
	{
		pthread_mutex_destroy(&fork[i]);
		pthread_mutex_destroy(&philo[i].last_meal_lock);
	}
	pthread_mutex_destroy(philo->mutex.p);
	pthread_mutex_destroy(&philo->arguments->full_lock);
	pthread_mutex_destroy(&philo->arguments->death_lock);
	free(fork);
	free(philo);
}
