/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <rohanafan@sina.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:25:47 by lifan             #+#    #+#             */
/*   Updated: 2024/11/15 18:25:47 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//* In this page we will creat threads.
//* Also define the philo's routine.
#include "../include/philo.h"

void	ft_eat(t_philo *philo, t_info *info)
{
	if (info->nbr_philo == 1)
	{
		pthread_mutex_lock(&info->fork[philo->hand_r - 1]);
		ft_announce(info, philo->id, S_TAKE);
		ft_usleep(info->t_death, philo);
		ft_announce(info, philo->id, "died");
		pthread_mutex_lock(&info->stop);
		info->status = QUIT;
		pthread_mutex_unlock(&info->stop);
		pthread_mutex_unlock(&info->fork[philo->hand_r - 1]);
		return ;
	}
	ft_take_fork(philo);
	pthread_mutex_lock(&info->lst_meal);
	philo->last_meal = ft_get_time();
	pthread_mutex_unlock(&info->lst_meal);
	ft_announce(info, philo->id, S_EAT);
	ft_usleep(info->t_eat, philo);
	pthread_mutex_lock(&info->eat);
	philo->eaten+= 1;
	pthread_mutex_unlock(&info->eat);
	ft_put_fork(philo);
}
void	ft_think(t_philo *philo, t_info *info)
{
	ft_announce(info, philo->id, S_THINK);
	if (info->t_think != NO && info->nbr_philo % 2 != 0)
		ft_usleep(info->t_think / 2, philo);
}

void	ft_sleep(t_philo *philo, t_info *info)
{
	ft_announce(info, philo->id, S_SLEEP);
	ft_usleep(info->t_sleep, philo);
}
//* end the thread when get the QUIT flag.
void	*ft_routine(void *p_philo)
{
	t_philo	*philo;
	t_info	*info;

	philo = (t_philo *)p_philo;
	info = philo->info;
	if (philo->id % 2 == 0)
		usleep(500 * info->t_eat);
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
		ft_eat(philo, info);
		if (info->nbr_philo == 1 || ft_check_dead(philo, info) || ft_all_eat(info))
			break ;
		ft_sleep(philo, philo->info);
		ft_think(philo, philo->info);
	}
	return (p_philo);
}
//* creat philo threads.
int	ft_start(t_info *info)
{
	int	i;

	i = 0;
	info->t_start = ft_get_time();
	while (i < info->nbr_philo)
	{
		if (pthread_create(&(info->philo[i].thread_id), \
			NULL, ft_routine, &info->philo[i]))
			return (ft_clean(info, ALL), FAIL);
		i++;
	}
	ft_monitor(info);
	i = 0;
	while (i < info->nbr_philo)
	{
		if (pthread_join(info->philo[i].thread_id, NULL))
			return (ft_clean(info, ALL), FAIL);
		i++;
	}
	return (0);
}
