/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtu <mtu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 19:47:06 by mtu               #+#    #+#             */
/*   Updated: 2024/02/13 22:51:16 by mtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac == 5 || ac == 6)
	{
		if (ft_atol(av[1]) == 0)
			return (0);
		if (arg_control(ac, av) == 0)
			return (0);
		data = (t_data *)malloc(sizeof(t_data));
		if (init_data_philo(data, av) == 0)
			return (0);
		if (fork_n_thread_start(data) == 0)
			return (0);
	}
	else
		return (print_error(ARG_COUNT));
}

int	arg_control(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (++i < ac)
	{
		j = -1;
		if (ft_atol(av[i]) == 0 && i != 5)
		{
			print_error(INV_ARG);
			return (0);
		}
		while (av[i][++j])
		{
			if (!(av[i][j] >= '0' && av[i][j] <= '9'))
			{
				print_error(INV_ARG);
				return (0);
			}
		}
	}
	return (1);
}

int	init_data_philo(t_data *data, char **av)
{
	data->philo_count = ft_atol(av[1]);
	sem_unlink("/forks");
	sem_unlink("/finish");
	sem_unlink("/print");
	data->forks = sem_open("/forks", O_CREAT, 0777, ft_atol(av[1]));
	data->finish = sem_open("/finish", O_CREAT, S_IRWXU, 1);
	data->print = sem_open("/print", O_CREAT, S_IRWXU, 1);
	if (data->forks == SEM_FAILED || data->finish == SEM_FAILED)
		return (0);
	data->philo = (t_philo *)malloc(sizeof(t_philo) * data->philo_count);
	data->ph_pid = (int *)malloc (sizeof(int) * data->philo_count);
	if (!data->philo || !data->ph_pid)
		return (print_error(ALLOC));
	init_philo(data, av);
	return (1);
}

void	init_philo(t_data *data, char **av)
{
	int	i;

	i = -1;
	while (++i < ft_atol(av[1]))
	{
		data->philo[i].ph_count = ft_atol(av[1]);
		data->philo[i].ph_num = i + 1;
		data->philo[i].max_eat_count = -1;
		if (av[5])
			data->philo[i].max_eat_count = ft_atol(av[5]);
		data->philo[i].total_eat_count = 0;
		data->philo[i].fin_flag = 0;
		data->philo[i].die_time = ft_atol(av[2]);
		data->philo[i].eat_time = ft_atol(av[3]);
		data->philo[i].sleep_time = ft_atol(av[4]);
		data->philo[i].data = data;
	}
}

int	fork_n_thread_start(t_data *data)
{
	if (fork_create(data) == 0)
		return (0);
	return (1);
}
