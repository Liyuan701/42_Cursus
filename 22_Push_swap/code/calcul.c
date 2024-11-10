/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_calcul.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <rohanafan@sina.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:55:22 by lifan             #+#    #+#             */
/*   Updated: 2024/10/28 22:55:22 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// calculate which element in a merit to be push.
void	ft_cheap_a(t_info *info, t_node *a, t_node *b)
{
	t_node	*tmp;
	int		min_moves;
	int		i;

	i = 0;
	tmp = ft_get_start(a);
	min_moves = INT_MAX;
	while (tmp)
	{
		ft_count_a(info, tmp, b);
		if (info->moves < min_moves)
		{
			min_moves = info->moves;
			info->cheap_a_node = tmp;
			info->cheap_a = i;
		}
		tmp = tmp->next;
		i++;
	}
}

// If the current a is less or larger than the smallesr
// or biggest in b, move = cost to move next to it.
// If the current a is not bigger/smaller case 2, ft_count.
void	ft_count_a(t_info *info, t_node *a, t_node *b)
{
	info->ia = ft_get_index(a);
	if (!b)
	{
		info->moves = info->ia + 1;
		return ;
	}
	ft_get_min(info, b);
	ft_get_max(info, b);
	if (a->value < info->min_value || a->value > info->max_value)
	{
		info->ib = info->max_index;
		ft_move_cost(info, ft_node_len(a), ft_node_len(b));
		info->moves = info->minm + 1;
	}
	else
		info->moves = ft_find_b(info, a, b, a->value) + 1;
}

// for an element of a which is neither larger nor smaller than b
// count how many moves can push it to its correct place in b
// correct place : the number just smaller than the a element
int	ft_find_b(t_info *info, t_node *a, t_node *b, int avalue)
{
	t_node	*tmp;
	int		bvalue;

	tmp = ft_get_start(b);
	if (b)
	{
		bvalue = tmp->value;
		while (tmp)
		{
			if ((tmp->value > bvalue && tmp->value < avalue)
				|| (tmp->value < avalue && bvalue > avalue))
				bvalue = tmp->value;
			tmp = tmp->next;
		}
		info->ib = ft_get_vindex(b, bvalue);
	}
	ft_move_cost(info, ft_node_len(a), ft_node_len(b));
	return (info->minm);
}

// Given the elemen in a to move, and the place in b to go.
// Decide how many cm moves and which way cost less moves(rr/rrr/ra+rrb/rb+rra)
void	ft_move_cost(t_info *info, int lena, int lenb)
{
	int	flag;

	flag = 1;
	info->way = 1;
	info->minm = INT_MAX;
	if (info->ib == 0)
	{
		info->ib = info->ia;
		flag = 0;
	}
	if (info->ia < info->ib)
		ft_cmp(info, info->ib, 1);
	else
		ft_cmp(info, info->ia, 1);
	if (lena - info->ia < lenb - info->ib)
		ft_cmp(info, lenb - info->ib, 2);
	else
		ft_cmp(info, lena - info->ia, 2);
	ft_cmp(info, info->ia + lenb - info->ib, 3);
	ft_cmp(info, info->ib + lena - info->ia, 4);
	if (flag == 0)
		info->ib = 0;
}

void	ft_cmp(t_info *info, int move, int cas)
{
	if (move >= 0 && move < info->minm)
	{
		info->minm = move;
		info->way = cas;
	}
}
