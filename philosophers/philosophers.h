/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:29:17 by hounejja          #+#    #+#             */
/*   Updated: 2025/04/27 21:41:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdarg.h>
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
	int				num_of_times_to_eat;
	int				this_time;
	int				*death;
	int				full;
	int				died;
}					t_info;

typedef struct s_mutex
{
	pthread_mutex_t	*fork;
	pthread_mutex_t	*p;
}	t_mutex;

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
}					t_philo;

int					time_1(void);
int					ft_atoi(const char *str);
int					handle_arg(t_info *arg, char **av, int ac);
int					convert_to_misec(int time);
void				print_msg(char *msg, int time, int id);
void				print(char c, t_philo *philo, int id);
int				ft_putchar(char c);
int				ft_putstr(const char *str);
long				print_int(long int n);
int				ft_printf(const char *w, ...);
void				*check_if_death(void *args);
void				destroy_mutex_and_free(t_philo *philo, pthread_mutex_t *fork);

#endif
