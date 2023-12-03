/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_sleep_think.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugurel <mugurel@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:03:38 by mugurel           #+#    #+#             */
/*   Updated: 2023/10/26 16:23:22 by mugurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_life_philo(void *cphilo)
{
	t_philo	*philo;

	philo = (t_philo *)cphilo;
	if (philo->total_philo == 1)
	{
		pthread_mutex_lock(philo->left_fork_mutex);
		ft_philo_print(philo, "has taken a fork", 0);
		while (!ft_philo_check(philo))
		{
		}
		pthread_mutex_unlock(philo->left_fork_mutex);
	}
	else
	{
		while (1)
		{
			if (ft_philo_check(philo))
				break ;
			ft_philo_eat(philo);
			ft_philo_sleep(philo);
			ft_philo_think(philo);
		}
	}
	return (NULL);
}

void	ft_philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork_mutex);
	pthread_mutex_lock(philo->right_fork_mutex);
	ft_philo_print(philo, "has taken a fork", 0);
	ft_philo_print(philo, "has taken a fork", 0);
	ft_philo_print(philo, "is eating", 0);
	ft_philo_wait(philo, philo->eat_time);
	pthread_mutex_lock(philo->death);
	philo->eat_last = ft_get_time();
	pthread_mutex_unlock(philo->death);
	pthread_mutex_lock(philo->death);
	philo->total_eaten++;
	pthread_mutex_unlock(philo->death);
}

void	ft_philo_sleep(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork_mutex);
	pthread_mutex_unlock(philo->right_fork_mutex);
	if (ft_philo_check(philo))
		return ;
	ft_philo_print(philo, "is sleeping", 0);
	ft_philo_wait(philo, philo->sleep_time);
}

void	ft_philo_think(t_philo *philo)
{
	if (ft_philo_check(philo))
		return ;
	ft_philo_print(philo, "is thinking", 0);
}
