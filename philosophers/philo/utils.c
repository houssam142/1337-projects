/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssam <houssam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 02:12:24 by hounejja          #+#    #+#             */
/*   Updated: 2025/07/26 13:22:43 by houssam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	increment_full(t_philo *philo)
{
	pthread_mutex_lock(&philo->arguments->full_lock);
	(*(philo->full))++;
	pthread_mutex_unlock(&philo->arguments->full_lock);
}

int	handle_arg(t_info *arg, char **av, int ac)
{
	if (ac != 5 && ac != 6)
	{
		if (check_arg(ac, av))
			return (1);
	}
	if (ft_atoi(av[1]) > 200 || ft_atoi(av[2]) < 60
		|| ft_atoi(av[3]) < 60 || ft_atoi(av[4]) < 60)
		return (1);
	arg->num_of_philo = ft_atoi(av[1]);
	arg->time_to_die = ft_atoi(av[2]);
	arg->time_to_eat = ft_atoi(av[3]);
	arg->time_to_sleep = ft_atoi(av[4]);
	arg->this_time = time_1();
	if (ac == 6)
	{
		arg->num_of_times_to_eat = ft_atoi(av[5]);
		if (arg->num_of_times_to_eat > 2147483647
			|| !arg->num_of_times_to_eat)
			return (1);
	}
	else
		arg->num_of_times_to_eat = -1;
	return (0);
}

void	print(char c, t_philo *philo, int id)
{
	pthread_mutex_lock(philo->mutex.p);
	if (c == 'F')
		print_msg("has taken a fork\n", time_1() - philo->arguments->this_time,
			id);
	else if (c == 'E')
		print_msg("is eating\n", time_1() - philo->arguments->this_time, id);
	else if (c == 'S')
		print_msg("is sleeping\n", time_1() - philo->arguments->this_time, id);
	else if (c == 'T')
		print_msg("is thinking\n", time_1() - philo->arguments->this_time, id);
	else if (c == 'D')
	{
		print_msg("died\n", time_1() - philo->arguments->this_time, id);
		pthread_mutex_unlock(philo->mutex.p);
		return ;
	}
	pthread_mutex_unlock(philo->mutex.p);
}

void	destroy_mutex_and_free(t_philo *philo, pthread_mutex_t *fork)
{
	int	i;

	i = -1;
	while (++i < philo->arguments->num_of_philo)
	{
		pthread_mutex_destroy(&fork[i]);
		pthread_mutex_destroy(&philo[i].must_die_lock);
		pthread_mutex_destroy(&philo[i].eat_count_lock);
	}
	pthread_mutex_destroy(philo->mutex.p);
	pthread_mutex_destroy(&philo->arguments->full_lock);
	free(fork);
	free(philo);
}
