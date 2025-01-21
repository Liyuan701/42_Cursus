/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <rohanafan@sina.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:31:47 by lifan             #+#    #+#             */
/*   Updated: 2024/11/15 16:31:47 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//* observe and update new evenments.
#include "../include/philo.h"

//* check if the philo is dead,first find, announce.
int	ft_check_dead(t_philo *philo, t_info *info)
{
	int	flag;
	long long	time;

	flag = 0;
	time = ft_get_time() - philo->last_meal;
	pthread_mutex_lock(&info->lst_meal);
	if (time > info->t_death)
		flag = QUIT;
	pthread_mutex_unlock(&info->lst_meal);
	if (flag == QUIT)
	{
		pthread_mutex_lock(&info->stop);
		if (info->status == GO)
		{
			printf("!!!time difference%lld\n", time);
			info->status = QUIT;
			pthread_mutex_unlock(&info->stop);
			pthread_mutex_lock(&info->write);
			printf("%lld %d died\n", ft_get_time()\
			 - info->t_start, philo->id);
			pthread_mutex_unlock(&info->write);
		}
		else
			pthread_mutex_unlock(&info->stop);
	}
	return (flag);
}

//* If no nbr_to_eat, quit.
//* otherwise, iterate to see if all philo got nbr_to_eat.
int	ft_all_eat(t_info *info)
{
	int	i;
	int count;
	t_philo	*philo;

	philo = info->philo;
	i = 0;
	count = 0;
	if (info->nbr_meal == -1)
		return (0);
	pthread_mutex_lock(&info->eat);
	while (i < info->nbr_philo)
	{
		if (philo[i].eaten >= info->nbr_meal)
			count++;
		i++;
	}
	pthread_mutex_unlock(&info->eat);
	if (count == info->nbr_philo)
	{
		printf("STOP: All philo ate %d times\n", info->nbr_meal);
		pthread_mutex_lock(&info->stop);
		info->status = QUIT;
		pthread_mutex_unlock(&info->stop);
		return (QUIT);
	}
	return (0);
}

//* Monitoring the status of all philos.
//* Set the quit flag and break when one die/ all eat.
void	ft_monitor(t_info *info)
{
	int	i;

	i = 0;
	while (1)
	{
		pthread_mutex_lock(&info->stop);
		if (info->status == QUIT)
		{
			pthread_mutex_unlock(&info->stop);
			break ;
		}
		else
			pthread_mutex_unlock(&info->stop);
		while (i < info->nbr_philo)
		{
			if (ft_check_dead(&info->philo[i], info) || ft_all_eat(info))
			{
				pthread_mutex_unlock(&info->stop);
				info->status = QUIT;
				pthread_mutex_unlock(&info->stop);
				return ;
			}
			i++;
		}
		usleep(1000);
	}
}
