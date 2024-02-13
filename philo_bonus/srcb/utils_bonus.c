/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugurel <mugurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 19:47:44 by mugurel           #+#    #+#             */
/*   Updated: 2024/02/14 01:00:53 by mugurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

int	print_error(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (0);
}

int	ft_atol(const char *str)
{
	unsigned long	i;
	unsigned long	result;
	unsigned long	sign;

	sign = 1;
	i = 0;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		result = 10 * result + (str[i] - 48);
		i++;
	}
	result = result * sign;
	return (result);
}

unsigned long long	ft_time(void)
{
	struct timeval		tv;
	unsigned long		time;

	gettimeofday(&tv, NULL);
	time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (time);
}

int	ft_sleep(t_philo *philo, int i)
{
	unsigned long long	time;
	unsigned long long	tmp_time;

	time = 0;
	tmp_time = ft_time();
	if (i == 1)
		time = philo->eat_time;
	else if (i == 2)
		time = philo->sleep_time;
	else if (i == 3)
		time = philo->die_time;
	while (1)
	{
		if (i != 3)
			dead_full_control(philo);
		if (ft_time() - tmp_time >= time)
			break ;
		usleep(50);
	}
	return (1);
}

int	print(t_philo *philo, char *str, int f)
{
	if (f == 1)
	{
		printf("%llu %d %s", (ft_time() - philo->start_time), \
			philo->ph_num, str);
		return (0);
	}
	else if (f == 0)
	{
		printf("%llu %d %s", (ft_time() - philo->start_time), \
			philo->ph_num, str);
	}
	return (1);
}
