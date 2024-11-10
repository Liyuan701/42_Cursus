/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <rohanafan@sina.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:00:45 by lifan             #+#    #+#             */
/*   Updated: 2024/10/24 18:00:45 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// In this way, for n numbers, I shall move 3n - 1 steps.
void	ft_reverse(t_node **a, t_node **b, int len)
{
	int	i;

	i = len;
	while (i-- > 0)
		ft_push(a, b, 'b', PRINT);
	while (i++ < len)
	{
		ft_rroate(b, 'b', PRINT);
		ft_push(b, a, 'a', PRINT);
	}
}

// Move the biggest number to the bottom then compare the first two.
void	ft_sort_thre(t_node **a)
{
	t_info	info;

	ft_memset(&info, 0, sizeof(t_info));
	ft_get_max(&info, *a);
	if (info.max_value == (*a)->value)
		ft_rotate(a, 'a', PRINT);
	else if (info.max_value == (*a)->next->value)
		ft_rroate(a, 'a', PRINT);
	if ((*a)->value > (*a)->next->value)
		ft_swap(a, 'a', PRINT);
}

// find the two top numbers to b, and send the rest to ft_sort_thre.
void	ft_sort_five(t_node **a, t_node **b, int len)
{
	int		i;
	t_info	info;

	i = 0;
	ft_memset(&info, 0, sizeof(t_info));
	while (3 < len - i)
	{
		ft_get_min(&info, *a);
		ft_intra_top(a, 'a', info.min_index);
		ft_push(a, b, 'b', PRINT);
		i++;
	}
	ft_sort_thre(a);
	while (i > 0)
	{
		ft_push(b, a, 'a', PRINT);
		i--;
	}
}
