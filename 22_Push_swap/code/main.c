/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <rohanafan@sina.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:50:57 by lifan             #+#    #+#             */
/*   Updated: 2024/11/06 14:52:48 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (ac < 2 || (ac == 2 && av[1][0] == '\0'))
		return (FAIL);
	else if (ac == 2)
		av = ft_split(av[1], SPACE);
	if (!av)
		return (FAIL);
	ft_initial(&a, av, ac);
	if (ft_node_len(a) == 0)
		ft_error_initial(&a, av, ac);
	ft_distribute(&a, &b, ft_node_len(a));
	ft_free_node(a);
	return (0);
}

void	ft_distribute(t_node **a, t_node **b, int len)
{
	int	flag;

	flag = PLUS;
	*a = ft_get_start(*a);
	ft_is_sorted(*a, &flag);
	if (flag == PLUS || flag == EMPTY)
		return ;
	*a = ft_get_start(*a);
	*b = ft_get_start(*b);
	if (flag == NO)
	{
		if (len == 2)
			ft_swap(a, 'a', PRINT);
		if (len == 3)
			ft_sort_thre(a);
		else if (len == 4 || len == 5)
			ft_sort_five(a, b, len);
		else if (len > 5)
			ft_sort_larg(a, b);
	}
}
