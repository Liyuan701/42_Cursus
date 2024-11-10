/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <rohanafan@sina.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:39:21 by lifan             #+#    #+#             */
/*   Updated: 2024/11/06 14:36:12 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	**ft_malloc_fail(char **new, int j)
{
	while (j >= 1)
	{
		free(new[j - 1]);
		j--;
	}
	free(new);
	return (NULL);
}

static int	ft_count(char const *s, char c)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			while (s[i] && s[i] != c)
				i++;
			n++;
		}
	}
	return (n);
}

static char	*ft_copy(char *innew, char const *s, int end, int len_l)
{
	int	i;

	i = 0;
	while (len_l > 0)
	{
		innew[i] = s[end - len_l];
		len_l--;
		i++;
	}
	innew[i] = '\0';
	return (innew);
}

static char	**ft_getword(char const *s, char c, char **new, int len_w)
{
	int	i;
	int	j;
	int	len_l;

	i = 0;
	j = 0;
	len_l = 0;
	while (j < len_w)
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			len_l++;
			i++;
		}
		new[j] = (char *)malloc(sizeof(char) * (len_l + 1));
		if (new[j] == NULL)
			return (ft_malloc_fail(new, j));
		ft_copy(new[j], s, i, len_l);
		len_l = 0;
		j++;
	}
	new[j] = NULL;
	return (new);
}

char	**ft_split(char const *s, char c)
{
	char			**new;
	unsigned int	len_w;

	if (!s)
		return (NULL);
	len_w = ft_count(s, c);
	new = (char **)malloc(sizeof(char *) * (len_w + 1));
	if (!new)
		return (NULL);
	new = ft_getword(s, c, new, len_w);
	if (!new)
		return (NULL);
	return (new);
}

/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	int	i;
	char	**test;
	char 	*str = "hello here is a test";

		test = ft_split(str, 32);
		while (test[i])
		{
			printf("%s\n", test[i]);
			i++;
		}
		return (0);
}*/
