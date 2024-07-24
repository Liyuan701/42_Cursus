/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <lifan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:22:59 by lifan             #+#    #+#             */
/*   Updated: 2024/07/23 11:22:59 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MINITALK_H
# define MINITALK_H

//Headers

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include "../libft/libft.h"

//Founctions

void	decrypt(int sig, siginfo_t *info, void *context);
void	send(int pid, char *message, int len);

#endif
