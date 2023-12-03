/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugurel <mugurel@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:03:38 by mugurel           #+#    #+#             */
/*   Updated: 2023/10/26 16:23:22 by mugurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_philo_check(t_philo *philo)
{
	pthread_mutex_lock(philo->death);
	if (philo->total_eaten == philo->eat_i)
	{
		pthread_mutex_unlock(philo->death);
		return (1);
	}
	pthread_mutex_unlock(philo->death);
	pthread_mutex_lock(philo->death);
	if (*philo->dead_check)
	{
		pthread_mutex_unlock(philo->death);
		return (1);
	}
	pthread_mutex_unlock(philo->death);
	pthread_mutex_lock(philo->death);
	if ((ft_get_time() - philo->eat_last) > \
		philo->die_time)
	{
		pthread_mutex_unlock(philo->death);
		ft_philo_print(philo, "died", 1);
		return (1);
	}
	pthread_mutex_unlock(philo->death);
	return (0);
}

void	ft_philo_print(t_philo *philo, char *str, int kill)
{
	pthread_mutex_lock(philo->print);
	if (!*philo->dead_check)
	{
		printf("%s%llu%s %s%d%s %s%s%s\n", "\033[4;31m", ft_get_time() \
		- philo->start_time, "\033[0m", "\033[4;30m", \
		philo->id + 1, "\033[0m", \
			"\033[4;34m", str, "\033[0m");
		if (kill)
			*philo->dead_check = 1;
	}
	pthread_mutex_unlock(philo->print);
	ft_philo_check(philo);
}

int	ft_philo_wait(t_philo *philo, t_time time_ag)
{
	t_time	time;

	time = ft_get_time();
	while (ft_get_time() - time < time_ag)
	{
		if (ft_philo_check(philo))
			return (1);
		usleep(100);
	}
	return (0);
}
