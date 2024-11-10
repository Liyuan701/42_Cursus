/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <rohanafan@sina.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:00:28 by lifan             #+#    #+#             */
/*   Updated: 2024/10/24 18:00:28 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// If in tab, begins form index 0, otherwise begins from 1.
void	ft_initial(t_node **a, char **av, int ac)
{
	int	i;

	i = 1;
	if (ac == 2)
		i = 0;
	while (av[i])
	{
		if (ft_isvalide(*a, av[i]) == 0)
			ft_error_initial(a, av, ac);
		*a = ft_extend(*a, ft_atoi(av[i]));
		i++;
	}
	if (ac == 2)
		ft_free_tab(av);
}

t_node	*ft_extend(t_node *old, int value)
{
	t_node	*new;

	new = ft_new_node(value);
	if (!new)
		return (NULL);
	if (!old)
		return (new);
	old->next = new;
	new->prev = old;
	return (new);
}

t_node	*ft_new_node(int value)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void	ft_atoi_flag(char *str, int *flag)
{
	long long	nbr;
	int			min;

	nbr = 0;
	min = 0;
	while ((*str <= 13 && *str >= 9) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			min = 1;
		str++;
	}
	if ((*str != '\0') && (*str >= '0') && (*str <= '9'))
	{
		while ((*str != '\0') && (*str >= '0') && (*str <= '9'))
		{
			nbr = nbr * 10 + (*str - '0');
			if (min == 0 && nbr > INT_MAX)
				*flag = PLUS;
			else if (min == 1 && nbr > 2147483648)
				*flag = PLUS;
			str++;
		}
	}
}
