/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 02:12:24 by hounejja          #+#    #+#             */
/*   Updated: 2025/04/27 22:04:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	convert_to_misec(int time)
{
	time *= 1000;
	return (time);
}

int	handle_arg(t_info *arg, char **av, int ac)
{
	if ((ac != 5 && ac != 6) || ft_atoi(av[1]) > 200
		|| ft_atoi(av[2]) < 60 || ft_atoi(av[3]) < 60
		|| ft_atoi(av[4]) < 60)
		return (1);
	arg->num_of_philo = ft_atoi(av[1]);
	arg->time_to_die = ft_atoi(av[2]);
	arg->time_to_eat = ft_atoi(av[3]);
	arg->time_to_sleep = ft_atoi(av[4]);
	arg->full = 0;
	arg->died = 0;
	if (av[5])
		arg->num_of_times_to_eat = ft_atoi(av[5]);
	return (0);
}

void	print(char c, t_philo *philo, int id)
{
	pthread_mutex_lock(philo->mutex.p);
	if (c == 'F')
		print_msg("has taken a fork\n",
			time_1() - philo->arguments->this_time, id);
	else if (c == 'E')
	{
		print_msg("is eating", time_1() - philo->arguments->this_time, id);
		philo->eat_count += 1;
		printf(" (%d)\n", philo->eat_count);
		if (philo->arguments->num_of_times_to_eat == philo->eat_count)
			*(philo->full) += 1;
	}
	else if (c == 'S')
		print_msg("is sleeping\n", time_1() - philo->arguments->this_time, id);
	else if (c == 'T')
		print_msg("is thinking\n", time_1() - philo->arguments->this_time, id);
	else if (c == 'D')
	{
		print_msg("died\n", time_1() - philo->arguments->this_time, id);
		return ;
	}
	pthread_mutex_unlock(philo->mutex.p);
}

void	destroy_mutex_and_free(t_philo *philo, pthread_mutex_t *fork)
{
	int	i;

	i = 0;
	while (i < philo->arguments->num_of_philo)
	{
		pthread_mutex_destroy(&fork[i]);
		i++;
	}
	pthread_mutex_destroy(philo->mutex.p);
	free(fork);
	free(philo);
}
