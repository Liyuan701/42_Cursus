/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   declear.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <rohanafan@sina.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:32:26 by lifan             #+#    #+#             */
/*   Updated: 2024/11/15 16:32:26 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//* backstage of the "lidfegame"
#include "../include/philo.h"

//* print in STE error messages.
void	ft_error(int code)
{
	if (code == NOA)
		ft_print_to(E_NOA, STE);
	if (code == NOC)
		ft_print_to(E_NOC, STE);
	if (code == INI)
		ft_print_to(E_INI, STE);
	if (code == THR)
		ft_print_to(E_THR, STE);
}

//* announce philo activities.
void	ft_announce(t_info *info, int id, char *str)
{
	long long	time;

	pthread_mutex_lock(&info->write);
	time = ft_get_time() - info->t_start;
	pthread_mutex_lock(&info->stop);
	if (info->status == GO)
	{
		printf("%lli %i %s\n", time, id, str);
		pthread_mutex_unlock(&info->stop);
	}
	else
		pthread_mutex_unlock(&info->stop);
	pthread_mutex_unlock(&info->write);
	return ;
}
//* Mutex clean according to the flag(where fails)
void	ft_clean(t_info *info, int flag)
{
	int	i;

	if (flag < 0)
		i = info->nbr_philo - 1;
	else
		i = flag - 1;
	while (i >= 0)
	{
		pthread_mutex_destroy(&info->fork[i]);
		i--;
	}
	if (flag == WRITE || flag == STOP || flag == LSTM || flag == ALL)
		pthread_mutex_destroy(&info->eat);
	if (flag == STOP || flag == LSTM || flag == ALL)
		pthread_mutex_destroy(&info->write);
	if (flag == LSTM || flag == ALL)
		pthread_mutex_destroy(&info->stop);
	if (flag == ALL)
		pthread_mutex_destroy(&info->lst_meal);
}
//* a strategy to take and put forks.
void	ft_take_fork(t_philo *philo)
{
	if (philo->id % 2 != 0)
	{
		pthread_mutex_lock(&philo->info->fork[philo->hand_r - 1]);
		if(!ft_check_dead(philo, philo->info))
		{
			ft_announce(philo->info, philo->id, S_TAKE);
			pthread_mutex_lock(&philo->info->fork[philo->hand_l - 1]);
			if(!ft_check_dead(philo, philo->info))
				ft_announce(philo->info, philo->id, S_TAKE);
		}
	}
	else
	{
		pthread_mutex_lock(&philo->info->fork[philo->hand_l - 1]);
		if(!ft_check_dead(philo, philo->info))
		{
			ft_announce(philo->info, philo->id, S_TAKE);
			pthread_mutex_lock(&philo->info->fork[philo->hand_r - 1]);
			if(!ft_check_dead(philo, philo->info))
				ft_announce(philo->info, philo->id, S_TAKE);
		}
	}
}

void	ft_put_fork(t_philo *philo)
{
	if (philo->id % 2 != 0)
	{
		pthread_mutex_unlock(&philo->info->fork[philo->hand_r - 1]);
		pthread_mutex_unlock(&philo->info->fork[philo->hand_l - 1]);
	}
	else
	{
		pthread_mutex_unlock(&philo->info->fork[philo->hand_l - 1]);
		pthread_mutex_unlock(&philo->info->fork[philo->hand_r - 1]);
	}
}
