/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugurel <mugurel@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:03:38 by mugurel           #+#    #+#             */
/*   Updated: 2023/10/26 16:23:22 by mugurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

# define MAX 2147483647

typedef unsigned long long	t_time;

typedef struct s_philo
{
	int				id;
	int				*dead_check;
	int				eat_i;
	int				total_eaten;
	int				total_philo;
	t_time			die_time;
	t_time			eat_time;
	t_time			sleep_time;
	t_time			eat_last;
	t_time			start_time;
	pthread_t		thread;
	pthread_mutex_t	*death;
	pthread_mutex_t	*print;
	pthread_mutex_t	*left_fork_mutex;
	pthread_mutex_t	*right_fork_mutex;
}	t_philo;

void		*ft_calloc(size_t count);
int			ft_check_arg(int ac, char **av);
int			ft_isdigit(int c);
long long	ft_atoll(const char *str);
t_time		ft_get_time(void);
void		ft_init_args(t_philo *philo, int ac, char **av);
void		create_mutex(t_philo *philo, pthread_mutex_t *forks, \
			pthread_mutex_t *death);
void		ft_free(t_philo *philo, pthread_mutex_t *forks, \
			pthread_mutex_t *death);
void		ft_start_philo(t_philo *philo, char **av);
void		ft_philo_print(t_philo *philo, char *str, int kill);
int			ft_philo_check(t_philo *philo);
void		*ft_life_philo(void *cphilo);
int			ft_philo_wait(t_philo *philo, t_time time_ag);
void		ft_philo_think(t_philo *philo);
void		ft_philo_sleep(t_philo *philo);
void		ft_philo_eat(t_philo *philo);

#endif
