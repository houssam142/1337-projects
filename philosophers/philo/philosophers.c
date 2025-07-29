/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssam <houssam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:30:27 by hounejja          #+#    #+#             */
/*   Updated: 2025/07/29 10:42:07 by houssam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void *check_if_death(void *arg)
{
	t_philo *philo;
	int i;

	philo = (t_philo *)arg;
	usleep(20 * (philo->arguments->num_of_philo / 2));
	while (1)
	{
		i = 0;
		while (i < philo->arguments->num_of_philo)
		{
			pthread_mutex_lock(&philo[i].must_die_lock);
			if ((time_1() - philo[i].last_meal) >= (unsigned long)philo->arguments->time_to_die)
			{
				pthread_mutex_unlock(&philo[i].must_die_lock);
				pthread_mutex_lock(&philo->arguments->death_lock);
				if (!(*philo->arguments->death))
				{
					pthread_mutex_lock(philo[i].mutex.p);
					print_msg("died\n", time_1() - philo->arguments->this_time, philo[i].id);
					*philo->arguments->death = 1;
					pthread_mutex_unlock(philo[i].mutex.p);
				}
				pthread_mutex_unlock(&philo->arguments->death_lock);
				return (NULL);
			}
			pthread_mutex_unlock(&philo[i].must_die_lock);
			i++;
		}
		if (check_if_full_and_died(philo))
			return (NULL);
		usleep(50);
	}
	return (NULL);
}

void death_events(t_philo *philo)
{
	int i;
	int now;

	i = 0;
	now = time_1();
	while (i < philo->arguments->num_of_philo)
	{
		pthread_mutex_lock(&philo[i].must_die_lock);
		philo[i].last_meal = now;
		pthread_mutex_unlock(&philo[i].must_die_lock);
		i++;
	}
}

void	*exec(void *args)
{
	t_philo *philo = (t_philo *)args;

	pthread_mutex_lock(&philo->must_die_lock);
	philo->last_meal = time_1();
	pthread_mutex_unlock(&philo->must_die_lock);
	if (philo->id % 2 != 0)
		usleep(50);
	if (philo->arguments->num_of_philo == 1)
		return (one_philo(philo), NULL);
	while (!is_dead(philo))
	{
		if (take_forks(philo))
			break ;
		update_eating(philo);
		if (is_dead(philo))
		{
			put_forks(philo);
			return (NULL);
		}
		put_forks(philo);
		print('S', philo, philo->id);
		ft_usleep((unsigned long)philo->arguments->time_to_sleep, philo);
		thinking_exec(philo);
	}
	return (NULL);
}

void init_param(t_info *info, t_philo *philo, pthread_mutex_t *print_mutex,
	pthread_mutex_t *forks)
{
    int i;

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
        pthread_mutex_init(&philo[i].must_die_lock, NULL);
    }
    death_events(philo);
	i = -1;
    while (++i < info->num_of_philo)
        pthread_create(&philo[i].philo, NULL, exec, &philo[i]);
}

int main(int ac, char **av)
{
    t_info          arguments;
    t_philo         *philo;
    pthread_mutex_t *forks;
    pthread_mutex_t print_mutex;
    int             i;

    if (handle_arg(&arguments, av, ac))
        return (1);
    philo = malloc(sizeof(t_philo) * arguments.num_of_philo);
    forks = malloc(sizeof(pthread_mutex_t) * arguments.num_of_philo);
    if (!philo || !forks)
        return (1);
    pthread_mutex_init(&arguments.full_lock, NULL);
    pthread_mutex_init(&arguments.death_lock, NULL);
    pthread_mutex_init(&arguments.start_mutex, NULL);
	i = 0;
    while (i < arguments.num_of_philo)
	{
        pthread_mutex_init(&forks[i++], NULL);
	}
	pthread_mutex_lock(&arguments.start_mutex);
	init_param(&arguments, philo, &print_mutex, forks);
	pthread_mutex_unlock(&arguments.start_mutex);
    pthread_create(&arguments.alive, NULL, check_if_death, philo);
	i = 0;
    while (i < arguments.num_of_philo)
        pthread_join(philo[i++].philo, NULL);
    pthread_join(arguments.alive, NULL);
    destroy_mutex_and_free(philo, forks);
    return (0);
}
