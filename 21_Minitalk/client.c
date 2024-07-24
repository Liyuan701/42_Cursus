/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: lifan <lifan@student.42.fr>                +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2024/07/23 19:34:02 by lifan             #+#    #+#             */
/*   Updated: 2024/07/23 19:34:02 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minitalk.h"

int		g_signal = 0;

void	response(int sig, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	if (sig == SIGUSR1)
		g_signal = 1;
}

int	wait(void)
{
	while (g_signal == 0)
		usleep(50);
	g_signal = 0;
	return (0);
}

void	send(int pid, char *message, int len)
{
	int	i;
	int	shift;

	i = 0;
	while (i < len + 1)
	{
		shift = 7;
		while (shift >= 0)
		{
			if ((message[i] >> shift) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			wait();
			shift--;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	char				*message;
	int					pid;
	struct sigaction	sa;

	if (argc != 3)
		(ft_printf("Please type like this : ./client [server-pid] [message] \n"),
			exit(EXIT_FAILURE));
	pid = ft_atoi(argv[1]);
	if (pid < 1)
		(ft_printf("\n Opus, pid is wrong! \n"), exit(EXIT_FAILURE));
	sa.sa_sigaction = &response;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	message = argv[2];
	if (message[0] == '\0')
		(ft_printf("Tell me your message !\n"), exit(EXIT_FAILURE));
	send(pid, message, ft_strlen(argv[2]));
}
