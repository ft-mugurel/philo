/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugurel <mugurel@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:03:38 by mugurel           #+#    #+#             */
/*   Updated: 2023/10/26 16:23:22 by mugurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	*death;
	t_philo			*philo;

	if (!ft_check_arg(ac, av))
	{
		printf("invalid argument");
		return (2);
	}
	philo = ft_calloc(sizeof(t_philo) * ft_atoll(av[1]));
	forks = ft_calloc(sizeof(pthread_mutex_t) * ft_atoll(av[1]));
	death = ft_calloc(sizeof(pthread_mutex_t));
	if (!philo || !forks || !death)
		return (2);
	ft_init_args(philo, ac, av);
	create_mutex(philo, forks, death);
	ft_start_philo(philo, av);
	ft_free(philo, forks, death);
	return (0);
}
