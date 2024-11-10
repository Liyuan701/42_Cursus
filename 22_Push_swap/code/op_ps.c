/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_swap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <rohanafan@sina.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:45:10 by lifan             #+#    #+#             */
/*   Updated: 2024/10/24 18:45:10 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_swap(t_node **stack, char c, int flag)
{
	t_node	*second;

	*stack = ft_get_start(*stack);
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	second = (*stack)->next;
	second->prev = NULL;
	(*stack)->next = second->next;
	if (second->next != NULL)
		second->next->prev = *stack;
	(*stack)->prev = second;
	second->next = *stack;
	*stack = second;
	if (flag == PRINT)
		ft_printf("s%c\n", c);
}

void	ft_push(t_node **from, t_node **to, char t, int flag)
{
	t_node	*tmp;

	if (from == NULL || *from == NULL)
		return ;
	*from = ft_get_start(*from);
	*to = ft_get_start(*to);
	tmp = (*from)->next;
	if (tmp != NULL)
		tmp->prev = NULL;
	(*from)->next = *to;
	if (*to != NULL)
		(*to)->prev = *from;
	*to = *from;
	*from = tmp;
	if (flag == PRINT)
		ft_printf("p%c\n", t);
}

void	ft_ss(t_node **a, t_node **b, int flag)
{
	ft_swap(a, 'a', MUTE);
	ft_swap(b, 'b', MUTE);
	if (flag == PRINT)
		ft_printf("ss\n");
}
