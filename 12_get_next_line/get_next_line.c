/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:42:26 by lifan             #+#    #+#             */
/*   Updated: 2024/01/06 12:23:18 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char *got)
{
	int		len_l;
	char	*line;

	len_l = 0;
	if (!got[len_l])
		return (NULL);
	while (got[len_l] && got[len_l] != '\n')
		len_l++;
	if (got[len_l] == '\0')
		len_l++;
	else
		len_l += 2;
	line = (char *)malloc(sizeof(char) * len_l);
	if (!line)
		return (NULL);
	line = ft_copy(got, line);
	return (line);
}

char	*ft_get_rest(char *got)
{
	int		len_l;
	int		i;
	char	*new;

	len_l = 0;
	while (got[len_l] && got[len_l] != '\n')
		len_l++;
	if (!got[len_l])
	{
		free(got);
		return (NULL);
	}
	new = malloc(ft_strlen(got) - len_l);
	if (!new)
		return (NULL);
	len_l++;
	i = 0;
	while (got[len_l])
		new[i++] = got[len_l++];
	new[i] = '\0';
	free(got);
	return (new);
}

char	*ft_get(int fd, char *got)
{
	char	*buff;
	int		bytes;

	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(got, '\n') && bytes != 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[bytes] = '\0';
		got = ft_strjoin(got, buff);
	}
	free(buff);
	return (got);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*got;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 4095)
		return (NULL);
	got = ft_get(fd, got);
	if (!got)
		return (NULL);
	line = ft_get_line(got);
	got = ft_get_rest(got);
	return (line);
}

/*#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char	*str = NULL;
	int		fd = open("test1.txt", O_RDONLY);
	int		i = 1;

	while (1)
	{
		str = get_next_line(fd);
		printf("[%d] %s", i, str);
		free(str);
		if (!str)
			break ;
		i++;
	}
	return (0);
}*/
