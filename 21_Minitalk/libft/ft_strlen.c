/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <lifan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:00:33 by lifan             #+#    #+#             */
/*   Updated: 2023/11/12 14:09:58 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/*#include <stdio.h>
int	main()
{
	char *str = "it's just a test";
	printf("%i",ft_strlen(str));
	return (0);
}*/
