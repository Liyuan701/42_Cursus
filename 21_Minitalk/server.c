/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <lifan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 19:49:06 by lifan             #+#    #+#             */
/*   Updated: 2024/07/23 19:49:06 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minitalk.h"

void	decrypt(int sig, siginfo_t *info, void *context)
{
	static unsigned char	cur;
	static int				index;

	(void)context;
	if (sig == SIGUSR2)
		cur = cur * 2 + 1;
	else
		cur = cur * 2;
	index++;
	if (index == 8)
	{
		if (cur == 0)
			ft_printf("\n");
		else
			ft_printf("%c", cur);
		cur = 0;
		index = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Loading...\nWelcome to the server!\n");
	ft_printf("My PID number is %d\n", getpid());
	sa.sa_sigaction = &decrypt;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		usleep(50);
	return (0);
}
