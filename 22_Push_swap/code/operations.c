/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <rohanafan@sina.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:55:01 by lifan             #+#    #+#             */
/*   Updated: 2024/10/31 15:55:01 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_do(t_info info, t_node **a, t_node **b)
{
	int	ma;
	int	mb;

	ma = info.ia;
	mb = info.ib;
	if (info.way == 1)
		ft_case_rr(a, b, ma, mb);
	if (info.way == 2)
		ft_case_rrr(a, b, ma, mb);
	if (info.way == 3)
		ft_case_r_rr(a, b, ma, mb);
	if (info.way == 4)
		ft_case_rr_r(a, b, ma, mb);
}

// both do rr min_common times then r the rest to get to the top
void	ft_case_rr(t_node **a, t_node **b, int ma, int mb)
{
	int	times;

	times = ma;
	if (ma > mb)
		times = mb;
	ft_times_cm(ft_rr, a, b, times);
	if (ma > mb)
		ft_times(ft_rotate, a, 'a', ma - mb);
	else if (mb > ma)
		ft_times(ft_rotate, b, 'b', mb - ma);
}

// both do rrr min_common times then rr the rest to get to the top
void	ft_case_rrr(t_node **a, t_node **b, int ma, int mb)
{
	int	times;

	ma = ft_node_len(*a) - ma;
	if (mb != 0)
		mb = ft_node_len(*b) - mb;
	times = ma;
	if (ma > mb)
		times = mb;
	ft_times_cm(ft_rrr, a, b, times);
	if (ma > mb)
		ft_times(ft_rroate, a, 'a', ma - mb);
	else if (mb > ma)
		ft_times(ft_rroate, b, 'b', mb - ma);
}

// a r, and b rrr to get to the top.
void	ft_case_r_rr(t_node **a, t_node **b, int ma, int mb)
{
	int	times;

	times = ft_node_len(*b) - mb;
	ft_times(ft_rotate, a, 'a', ma);
	ft_times(ft_rroate, b, 'b', times);
}

// a rr and b r to get to the top.
void	ft_case_rr_r(t_node **a, t_node **b, int ma, int mb)
{
	int	times;

	times = ft_node_len(*a) - ma;
	ft_times(ft_rroate, a, 'a', times);
	ft_times(ft_rotate, b, 'b', mb);
}
