/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugurel <mugurel@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:03:38 by mugurel           #+#    #+#             */
/*   Updated: 2023/10/26 16:23:22 by mugurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

long long	ft_atoll(const char *str)
{
	int			i;
	int			sign;
	long long	number;

	sign = 1;
	i = 0;
	number = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		number = (number * 10) + (str[i] - '0');
		i++;
	}
	return (number * sign);
}

t_time	ft_get_time(void)
{
	struct timeval		tv;
	unsigned long long	time;

	gettimeofday(&tv, NULL);
	time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (time);
}

int	ft_check_arg(int ac, char **av)
{
	int	i;
	int	j;

	if (ac != 5 && ac != 6)
		return (0);
	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (!(av[i][j] >= '0' && av[i][j] <= '9'))
				return (0);
			if (ft_atoll(av[i]) > MAX)
				return (0);
			if (ft_atoll(av[i]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	*ft_calloc(size_t count)
{
	void	*start;
	void	*ret;

	ret = malloc(count);
	start = ret;
	if (!ret)
		return (0);
	while (count--)
		*(unsigned char *)ret++ = 0;
	return (start);
}
