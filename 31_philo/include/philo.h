/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <rohanafan@sina.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:12:57 by lifan             #+#    #+#             */
/*   Updated: 2024/11/04 15:12:57 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>

# define FAIL	1
# define NOA	2
# define NOC	3
# define INI	4
# define THR	6

# define QUIT	170
# define GO		171

# define S_TAKE		"has taken a fork"
# define S_EAT		"is eating"
# define S_SLEEP	"is sleeping"
# define S_THINK	"is thinking"

# define E_NOA	"\033[31mError: Please give 4 or 5 arguments.\033[0m\n"
# define E_NOC	"\033[31mError: Please give correct arguments.\033[0m\n"
# define E_INI	"\033[31mError: something went wrong while initializing.\033[0m\n"
# define E_TIM	"\033[31mError:Something went wrong while getting time.\033[0m\n\n"
# define E_THR	"\033[31mError:Something went wrong while dealling with threads.\033[0m\n\n"

# define STO		1
# define STI		0
# define STE		2
# define NP			200

# define YES	1
# define NO 	2
# define ALL	-1
# define EAT	-2
# define STOP	-3
# define LSTM	-4
# define WRITE	-5

typedef pthread_mutex_t mutex_t;

//Structures

typedef struct s_info t_info;

typedef struct s_philo
{
	int			id;
	pthread_t	thread_id;
	int			eaten;
	int			hand_r;
	int			hand_l;
	long long	last_meal;
	t_info		*info;

}	t_philo;

typedef struct s_info
{
	int			nbr_philo;
	int			t_death;
	int			t_eat;
	int			t_sleep;
	int			t_think;
	int			nbr_meal;
	int			status;
	long long	t_start;
	mutex_t		eat;
	mutex_t		write;
	mutex_t		lst_meal;
	mutex_t		stop;
	mutex_t		fork[NP];
	t_philo		philo[NP];
}	t_info;

//Functions

int			ft_check_args(char **av, t_info *info);
int			ft_initial(t_info *info);
void		ft_philo_init(t_philo *philo, t_info *info, int i, int flag);
int			ft_mutex_init(t_info *info);
int			main(int ac, char **av);

void		ft_eat(t_philo *philo, t_info *info);
void		ft_think(t_philo *philo, t_info *info);
void		ft_sleep(t_philo *philo, t_info *info);
void		*ft_routine(void *p_philo);
int			ft_start(t_info *info);

int			ft_check_dead(t_philo *philo, t_info *info);
int			ft_all_eat(t_info *info);
void		ft_monitor(t_info *info);

void		ft_error(int code);
void		ft_announce(t_info *info, int id, char *str);
void		ft_clean(t_info *info, int flag);
void		ft_take_fork(t_philo *philo);
void		ft_put_fork(t_philo *philo);

int			ft_atoi(const char *str);
int			ft_isdigital(char **av);
long long	ft_get_time(void);
void		ft_usleep(long long	ms, t_philo *philo);
void		ft_print_to(char *str, int fd);

#endif
