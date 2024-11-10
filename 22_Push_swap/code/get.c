/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_getinfo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <rohanafan@sina.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 22:09:06 by lifan             #+#    #+#             */
/*   Updated: 2024/10/25 22:09:06 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// to get the start of the stack
t_node	*ft_get_start(t_node *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack->prev)
	{
		stack = stack->prev;
	}
	return (stack);
}

// to get the end of the stack
t_node	*ft_get_end(t_node *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

// Get max value and node, note down in info
int	ft_get_max(t_info *info, t_node *stack)
{
	t_node	*tmp;
	int		i;

	i = 0;
	if (stack == NULL)
	{
		info->max_index = 0;
		return (FAIL);
	}
	tmp = ft_get_start(stack);
	info->max_value = INT_MIN;
	while (tmp)
	{
		if (info->max_value < tmp->value)
		{
			info->max_value = tmp->value;
			info->max_index = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (EXIST);
}

// Get min value and node, note down in info
int	ft_get_min(t_info *info, t_node *stack)
{
	t_node	*tmp;
	int		i;

	i = 0;
	if (stack == NULL)
	{
		info->min_index = 0;
		return (FAIL);
	}
	tmp = ft_get_start(stack);
	info->min_value = INT_MAX;
	while (tmp)
	{
		if (tmp->value < info->min_value)
		{
			info->min_value = tmp->value;
			info->min_index = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (EXIST);
}

int	ft_get_vindex(t_node *stack, int value)
{
	t_node	*tmp;
	int		i;

	i = 0;
	tmp = ft_get_start(stack);
	if (!stack || ft_node_len(stack) == 0)
		return (-1);
	while (tmp)
	{
		if (tmp->value == value)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (-1);
}
