/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <rohanafan@sina.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:46:06 by lifan             #+#    #+#             */
/*   Updated: 2024/11/11 15:46:06 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//* In this page I will deal with arguments verify and intial fonctions.
#include "../include/philo.h"

//* philo index from 0, philo id from 1
void	ft_philo_init(t_philo *philo, t_info *info, int i, int lst_flag)
{
	long long	time;

	time = ft_get_time();
	philo->info = info;
	philo->id = i;
	philo->eaten = 0;
	philo->hand_l = i;
	philo->last_meal = time;
	if (lst_flag == 1)
		philo->hand_r = 1;
	else
		philo->hand_r = i + 1;
}
//* Initial four common mutexes.
int	ft_mutex_init(t_info *info)
{
	int	i;
	int	lst_flag;

	i = info->nbr_philo;
	lst_flag = 1;
	while (i >= 1)
	{
		if (pthread_mutex_init(&info->fork[i - 1], NULL))
			return (ft_clean(info, i), FAIL);
		ft_philo_init(&info->philo[i - 1], info, i, lst_flag);
		i--;
		lst_flag = 0;
	}
	if (pthread_mutex_init(&info->eat, NULL))
		return(ft_clean(info, EAT), FAIL);
	if (pthread_mutex_init(&info->write, NULL))
		return(ft_clean(info, WRITE), FAIL);
	if (pthread_mutex_init(&info->stop, NULL))
		return(ft_clean(info, STOP), FAIL);
	if (pthread_mutex_init(&info->lst_meal, NULL))
		return(ft_clean(info, LSTM), FAIL);
	return (0);
}
//* initiate philo and mutexs according to numbers of philo.
//* use flag to indicate the first philo.
int	ft_initial(t_info *info)
{
	long long	time;

	time = ft_get_time();
	info->status = GO;
	info->t_start = time;
	if (info->t_eat >= info->t_sleep)
		info->t_think = info->t_eat;
	else
		info->t_think = NO;
	if (ft_mutex_init(info) == FAIL)
		return (FAIL);
	return (0);
}

//* make sure that args are correct numbers and init info.
int	ft_check_args(char **av, t_info *info)
{
	if (!ft_isdigital(av))
		return (FAIL);
	info->nbr_philo = ft_atoi(av[1]);
	info->t_death = ft_atoi(av[2]);
	info->t_eat = ft_atoi(av[3]);
	info->t_sleep = ft_atoi(av[4]);
	info->nbr_meal = -1;
	if (av[5])
	{
		info->nbr_meal = ft_atoi(av[5]);
		if (info->nbr_meal < 0)
			return (FAIL);
	}
	else
		info->nbr_meal = -1;
	if (info->nbr_philo < 1 || info->nbr_philo > NP || info->t_death < 0
	|| info->t_eat < 0 || info->t_sleep < 0)
		return (FAIL);
	return (0);
}
int	main(int ac, char **av)
{
	t_info	info;

	if (ac != 5 && ac !=6)
		return(ft_error(NOA), FAIL);
	if (ft_check_args(av, &info) == FAIL)
		return(ft_error(NOC), FAIL);
	if (ft_initial(&info) == FAIL)
		return(ft_error(INI), FAIL);
	if (ft_start(&info) == FAIL)
		return(ft_error(THR), FAIL);
	ft_clean(&info, ALL);
	return (0);
}

