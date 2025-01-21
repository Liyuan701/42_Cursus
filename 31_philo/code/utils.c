/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <rohanafan@sina.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:00:49 by lifan             #+#    #+#             */
/*   Updated: 2024/11/15 17:00:49 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	nbr;

	sign = 1;
	nbr = 0;
	while ((*str <= 13 && *str >= 9) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if ((*str != '\0') && (*str >= '0') && (*str <= '9'))
	{
		while ((*str != '\0') && (*str >= '0') && (*str <= '9'))
		{
			nbr = nbr * 10 + (*str - '0');
			str++;
		}
		return (sign * nbr);
	}
	return (0);
}

int	ft_isdigital(char **av)
{
	int	i;
	int	j;
	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
//* get time and chang sec and usec to msec.
long long	ft_get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		ft_print_to(E_TIM, STE);
	return ((time.tv_sec *1000) + (time.tv_usec / 1000));
}

//* a usleep but divided by small
void	ft_usleep(long long	ms, t_philo *philo)
{
	long long	start;

	start = ft_get_time();
	while ((ft_get_time() - start) < ms)
	{
		if (ft_check_dead(philo, philo->info))
			return ;
		usleep(ms / 10);
	}
}

//* a printf can change fd
void	ft_print_to(char *str, int fd)
{
	int	len;

	len = 0;
	while(str[len])
		len++;
	write(fd, str, len);
}
