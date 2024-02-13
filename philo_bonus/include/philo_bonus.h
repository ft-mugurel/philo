/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugurel <mugurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 19:47:33 by mtu               #+#    #+#             */
/*   Updated: 2024/02/14 01:00:19 by mugurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <fcntl.h>
# include <semaphore.h>
# include <sys/time.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define INV_ARG "There is invalid argument!\n"
# define ARG_COUNT "Number of argument is wrong!\n"
# define ALLOC "Allocation error!\n"
# define SEMERR "Semaphore init failed!\n"
# define FORKERR "Fork opening is failed!\n"
# define FORK "  has taken a fork\n"
# define EAT "  is eating\n"
# define SLEEP "  is sleeping\n"
# define THINK "  is thinking\n"
# define DEAD "  is dead\n"

typedef struct s_philo
{
	int						fin_flag;
	int						ph_count;
	int						max_eat_count;
	int						total_eat_count;
	int						ph_num;
	unsigned long long		die_time;
	unsigned long long		eat_time;
	unsigned long long		sleep_time;
	unsigned long long		start_time;
	unsigned long long		last_time;
	struct s_data			*data;
}			t_philo;

typedef struct s_data
{
	int					philo_count;
	int					*ph_pid;
	sem_t				*forks;
	sem_t				*finish;
	sem_t				*print;
	t_philo				*philo;
}						t_data;

//----------main-------------
int					arg_control(int ac, char **av);
int					init_data_philo(t_data *data, char **av);
void				init_philo(t_data *data, char **av);
int					fork_n_thread_start(t_data *data);

//----------reating-------------
int					fork_create(t_data *data);
int					fork_create_2(t_data *data);
void				waiter_and_murder(t_data *data);

//----------routine-------------
void				*fork_routine(t_philo *philo);
int					dead_full_control(t_philo *philo);
int					eating(t_philo *philo);
int					sleeping(t_philo *philo);
int					take_fork(t_philo *philo);

//-----------utils--------------
int					print_error(char *str);
int					ft_atol(const char *str);
unsigned long long	ft_time(void);
int					ft_sleep(t_philo *philo, int i);
int					print(t_philo *philo, char *str, int f);

#endif