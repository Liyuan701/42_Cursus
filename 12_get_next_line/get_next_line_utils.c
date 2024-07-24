/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:48:07 by lifan             #+#    #+#             */
/*   Updated: 2024/01/03 19:40:18 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	int		i;
	char	cc;

	i = 0;
	cc = (char)c;
	if (!str)
		return (0);
	if (c == '\0')
		return ((char *)&str[ft_strlen(str)]);
	while (str[i])
	{
		if (str[i] == cc)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *got, char *buff)
{
	char	*new;

	if (!got)
	{
		got = (char *)malloc(sizeof(char));
		if (!got)
			return (NULL);
		got[0] = '\0';
	}
	if (!got || !buff)
		return (free(got), NULL);
	new = malloc(ft_strlen(got) + ft_strlen(buff) + 1);
	if (!new)
		return (NULL);
	new = ft_join(new, got, buff);
	return (new);
}

char	*ft_join(char *new, char *got, char *buff)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (got)
	{
		while (got[i])
		{
			new[i] = got[i];
			i++;
		}
	}
	while (buff[j])
	{
		new[i + j] = buff[j];
		j++;
	}
	new[i + j] = '\0';
	free(got);
	return (new);
}

char	*ft_copy(char *got, char *line)
{
	int	i;

	i = 0;
	while (got[i] && got[i] != '\n')
	{
		line[i] = got[i];
		i++;
	}
	if (got[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}
