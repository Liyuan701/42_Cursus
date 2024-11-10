/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <rohanafan@sina.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:44:59 by lifan             #+#    #+#             */
/*   Updated: 2024/10/24 18:44:59 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// get the first node by tmp and put tmp at the end.
void	ft_rotate(t_node **stack, char c, int flag)
{
	t_node	*tmp;

	*stack = ft_get_start(*stack);
	tmp = *stack;
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	tmp->prev = ft_get_end(*stack);
	tmp->next = NULL;
	ft_get_end(*stack)->next = tmp;
	if (flag == PRINT)
		ft_printf("r%c\n", c);
}

// get the first as tmp, and make the end as the new first.
void	ft_rroate(t_node **stack, char c, int flag)
{
	t_node	*tmp;

	*stack = ft_get_start(*stack);
	tmp = *stack;
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	*stack = ft_get_end(*stack);
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
	(*stack)->next = tmp;
	tmp->prev = *stack;
	if (flag == PRINT)
		ft_printf("rr%c\n", c);
}

void	ft_rr(t_node **a, t_node **b, int flag)
{
	ft_rotate(a, 'a', MUTE);
	ft_rotate(b, 'b', MUTE);
	if (flag == PRINT)
		ft_printf("rr\n");
}

void	ft_rrr(t_node **a, t_node **b, int flag)
{
	ft_rroate(a, 'a', MUTE);
	ft_rroate(b, 'b', MUTE);
	if (flag == PRINT)
		ft_printf("rrr\n");
}
