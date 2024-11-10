/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <rohanafan@sina.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 16:55:17 by lifan             #+#    #+#             */
/*   Updated: 2024/11/03 16:55:17 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// count the nodes of the stack, from the start
int	ft_node_len(t_node *stack)
{
	int		len;
	t_node	*tmp;

	tmp = ft_get_start(stack);
	len = 0;
	while (tmp)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}

int	ft_get_index(t_node *stack)
{
	int		index;
	t_node	*tmp;

	index = 0;
	tmp = stack;
	if (!stack)
		return (0);
	while (tmp->prev)
	{
		index++;
		tmp = tmp->prev;
	}
	return (index);
}

void	ft_times(void (*func)(t_node **, char, int), \
		t_node **a, char c, int times)
{
	if (times <= 0)
		return ;
	func(a, c, PRINT);
	ft_times(func, a, c, times - 1);
}

void	ft_times_cm(void (*func)(t_node **, t_node **, int), \
		t_node **a, t_node **b, int times)
{
	if (times <= 0)
		return ;
	func(a, b, PRINT);
	ft_times_cm(func, a, b, times - 1);
}

void	ft_times_ps(t_node **a, t_node **b, char c, int times)
{
	while (times-- > 0)
		ft_push(a, b, c, PRINT);
}
