/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_larg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <rohanafan@sina.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:00:42 by lifan             #+#    #+#             */
/*   Updated: 2024/10/24 18:00:42 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Step1: calculate, chose case to rotate then push to b.
// Step2: for emlements in b, find the correct place in a,
// top a to arrive at this place and push emement to b.
// Step3: final find_and_top, rotate/rroate to get the min,
// followed by its sorted list at the top.
void	ft_sort_larg(t_node **a, t_node **b)
{
	t_info	info;
	int		index;

	ft_times_ps(a, b, 'b', 2);
	ft_memset(&info, 0, sizeof(t_info));
	while (ft_node_len(*a) > 3)
	{
		ft_cheap_a(&info, *a, *b);
		*a = info.cheap_a_node;
		ft_count_a(&info, *a, *b);
		ft_do(info, a, b);
		ft_push(a, b, 'b', PRINT);
	}
	ft_sort_thre(a);
	while (ft_node_len(*b) > 0)
	{
		index = ft_merge(&info, a, (*b)->value);
		ft_intra_top(a, 'a', index);
		ft_push(b, a, 'a', PRINT);
	}
	ft_find_and_top(a, &info, MIN);
}

// Try to find the place of the node which
// will just bigger than the current one.
// If the currrent one of b is bigger than max in a,
// the place will be the current min place.
int	ft_merge(t_info *info, t_node **a, int bvalue)
{
	t_node	*tmp;
	t_node	*thenode;
	int		avalue;

	tmp = ft_get_start(*a);
	avalue = INT_MAX;
	if (ft_get_max(info, *a) == FAIL || \
		ft_get_min(info, *a) == FAIL || !tmp)
		return (0);
	if (bvalue > info->max_value)
		return (info->min_index);
	while (tmp)
	{
		if (bvalue < tmp->value && tmp->value <= avalue)
		{
			avalue = tmp->value;
			thenode = tmp;
		}
		tmp = tmp->next;
	}
	return (ft_get_index(thenode));
}

// find the MIN or MAX and top it.
void	ft_find_and_top(t_node **a, t_info *info, int ex)
{
	if (ex == MIN)
	{
		ft_get_min(info, *a);
		ft_intra_top(a, 'a', info->min_index);
	}
	else
	{
		ft_get_max(info, *a);
		ft_intra_top(a, 'a', info->max_index);
	}
}

// in a list, top up the X index element.
void	ft_intra_top(t_node **a, char c, int index)
{
	int	len;

	len = ft_node_len(*a);
	if (index <= len / 2)
	{
		while (index--)
			ft_rotate(a, c, PRINT);
	}
	else
	{
		index = len - index;
		while (index--)
			ft_rroate(a, c, PRINT);
	}
}
