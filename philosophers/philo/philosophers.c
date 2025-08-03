/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:30:27 by hounejja          #+#    #+#             */
/*   Updated: 2025/07/31 21:44:01 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*check_if_death(void *arg)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)arg;
	usleep(20 * (philo->arguments->num_of_philo / 2));
	while (1)
	{
		i = -1;
		while (++i < philo->arguments->num_of_philo)
		{
			pthread_mutex_lock(&philo[i].last_meal_lock);
			if ((time_1()
					- philo[i].last_meal) >= (unsigned long)
				philo->arguments->time_to_die)
			{
				monitor_helper(philo, i);
				return (NULL);
			}
			pthread_mutex_unlock(&philo[i].last_meal_lock);
		}
		if (check_if_full_and_died(philo))
			return (NULL);
		usleep(philo->arguments->time_to_die / 10);
	}
	return (NULL);
}

void	death_events(t_philo *philo)
{
	int				i;
	unsigned long	now;

	i = 0;
	now = time_1();
	while (i < philo->arguments->num_of_philo)
	{
		pthread_mutex_lock(&philo[i].last_meal_lock);
		philo[i].last_meal = now;
		pthread_mutex_unlock(&philo[i].last_meal_lock);
		i++;
	}
}

void	*exec(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	pthread_mutex_lock(&philo->last_meal_lock);
	philo->last_meal = time_1();
	pthread_mutex_unlock(&philo->last_meal_lock);
	if (philo->arguments->num_of_philo == 1)
		return (one_philo(philo), NULL);
	if (philo->id % 2 != 0)
		usleep(50);
	while (!is_dead(philo))
	{
		if (take_forks(philo))
			break ;
		update_eating(philo);
		if (is_dead(philo) || is_all_full(philo))
			return (put_forks(philo), NULL);
		put_forks(philo);
		if (is_dead(philo))
			break ;
		print('S', philo, philo->id);
		ft_usleep((unsigned long)philo->arguments->time_to_sleep, philo);
		thinking_exec(philo);
	}
	return (NULL);
}

void	init_param(t_info *info, t_philo *philo, pthread_mutex_t *print_mutex,
		pthread_mutex_t *forks)
{
	int	i;

	info->this_time = time_1();
	info->died = 0;
	info->full = 0;
	pthread_mutex_init(print_mutex, NULL);
	i = -1;
	while (++i < info->num_of_philo)
	{
		philo[i].id = i;
		philo[i].eat_count = 0;
		philo[i].arguments = info;
		philo[i].mutex.fork = forks;
		philo[i].mutex.p = print_mutex;
		philo[i].full = &info->full;
		info->death = &info->died;
		pthread_mutex_init(&philo[i].last_meal_lock, NULL);
	}
	death_events(philo);
	i = -1;
	while (++i < info->num_of_philo)
		pthread_create(&philo[i].philo, NULL, exec, &philo[i]);
}

int	main(int ac, char **av)
{
	t_info			arguments;
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	int				i;

	if (handle_arg(&arguments, av, ac))
		return (1);
	philo = malloc(sizeof(t_philo) * arguments.num_of_philo);
	forks = malloc(sizeof(pthread_mutex_t) * arguments.num_of_philo);
	if (!philo || !forks)
		return (1);
	pthread_mutex_init(&arguments.full_lock, NULL);
	pthread_mutex_init(&arguments.death_lock, NULL);
	i = 0;
	while (i < arguments.num_of_philo)
		pthread_mutex_init(&forks[i++], NULL);
	init_param(&arguments, philo, &print_mutex, forks);
	pthread_create(&arguments.alive, NULL, check_if_death, philo);
	i = 0;
	while (i < arguments.num_of_philo)
		pthread_join(philo[i++].philo, NULL);
	pthread_join(arguments.alive, NULL);
	destroy_mutex_and_free(philo, forks);
	return (0);
}
