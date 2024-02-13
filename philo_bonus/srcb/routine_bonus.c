/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtu <mtu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 19:47:40 by mtu               #+#    #+#             */
/*   Updated: 2024/02/14 00:48:45 by mtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

void	*fork_routine(t_philo *philo)
{
	philo->start_time = ft_time();
	philo->last_time = ft_time();
	if (philo->ph_count == 1)
	{
		sem_wait(philo->data->forks);
		print(philo, FORK, 0);
		ft_sleep(philo, 3);
		usleep(1000);
		print(philo, DEAD, 1);
		kill(getpid(), 15);
	}
	while (1)
	{
		if (dead_full_control(philo) == 0)
			return (0);
		if (eating(philo) == 0)
			return (0);
		if (sleeping(philo) == 0)
			return (0);
	}
}

int	dead_full_control(t_philo *philo)
{
	sem_wait(philo->data->finish);
	if (ft_time() > (philo->last_time + philo->die_time))
	{
		philo->fin_flag = 1;
		print(philo, DEAD, 1);
		kill(getpid(), 15);
	}
	if (philo->total_eat_count == philo->max_eat_count)
	{
		sem_post(philo->data->finish);
		return (0);
	}
	sem_post(philo->data->finish);
	return (1);
}

int	eating(t_philo *philo)
{
	if (take_fork(philo) == 0)
		return (0);
	if (print(philo, EAT, 0) == 0)
		return (0);
	if (ft_sleep(philo, 1) == 0)
		return (0);
	sem_post(philo->data->forks);
	sem_post(philo->data->forks);
	philo->last_time = ft_time();
	philo->total_eat_count++;
	return (1);
}

int	sleeping(t_philo *philo)
{
	if (print(philo, SLEEP, 0) == 0)
		return (0);
	if (ft_sleep(philo, 2) == 0)
		return (0);
	if (print(philo, THINK, 0) == 0)
		return (0);
	return (1);
}

int	take_fork(t_philo *philo)
{
	sem_wait(philo->data->forks);
	sem_wait(philo->data->forks);
	if (print(philo, FORK, 0) == 0)
		return (0);
	if (print(philo, FORK, 0) == 0)
		return (0);
	return (1);
}
