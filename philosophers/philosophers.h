/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssam <houssam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:29:17 by hounejja          #+#    #+#             */
/*   Updated: 2025/07/10 20:10:24 by houssam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_info
{
	int				num_of_philo;
	int				time_to_die;
	int				time_to_sleep;
	int				time_to_eat;
	long			num_of_times_to_eat;
	int				this_time;
	int				*death;
	int				full;
	int				died;
	pthread_mutex_t	full_lock;
}					t_info;

typedef struct s_mutex
{
	pthread_mutex_t	*fork;
	pthread_mutex_t	*p;
}					t_mutex;

typedef struct s_philo
{
	int				eat_count;
	int				id;
	int				*full;
	int				must_die;
	t_info			*arguments;
	t_mutex			mutex;
	pthread_t		philo;
	pthread_t		alive;
	pthread_mutex_t	must_die_lock;
}					t_philo;

int					time_1(void);
void				check_philo(t_philo *philo);
long				ft_atoi(const char *str);
int					handle_arg(t_info *arg, char **av, int ac);
int					convert_to_misec(int time);
void				print_msg(char *msg, int time, int id);
void				print(char c, t_philo *philo, int id);
int					take_forks(t_philo *philo);
int					check_if_full_and_died(t_philo *philo);
void				one_philo(t_philo *philo);
int					check_death_of_philo(t_philo *philo, int left, int right);
void				increment_full(t_philo *philo);
void				put_forks(t_philo *philo);
void				update_eating(t_philo *philo);
int					is_all_full(t_philo *philo);
void				*check_if_death(void *args);
void				destroy_mutex_and_free(t_philo *philo,
						pthread_mutex_t *fork);

#endif
