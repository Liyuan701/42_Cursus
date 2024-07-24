/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: lifan <marvin@42.fr>                       +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2023/12/18 14:15:55 by lifan             #+#    #+#             */
/*   Updated: 2023/12/18 14:50:00 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*ft_get_line(char *got);
char	*ft_get_rest(char *got);
char	*ft_get(int fd, char *got);
char	*get_next_line(int fd);
size_t	ft_strlen(char *str);
char	*ft_strchr(char *str, int c);
char	*ft_join(char *new, char *got, char *buff);
char	*ft_strjoin(char *got, char *buff);
char	*ft_copy(char *got, char *line);

#endif
