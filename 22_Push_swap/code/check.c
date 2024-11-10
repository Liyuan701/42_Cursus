/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <rohanafan@sina.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:01:00 by lifan             #+#    #+#             */
/*   Updated: 2024/10/24 18:01:00 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Verify three things: char is nb? nb is in limits? there is no double?
int	ft_isvalide(t_node *a, char *str)
{
	int		nb;
	int		flag;

	flag = LESS;
	if (!ft_isnb(str))
		return (0);
	if (ft_if_zero(str) == NO)
	{
		while (*str == '0' && *(str + 1) != '\0')
			str++;
		ft_atoi_flag(str, &flag);
		if (flag == PLUS)
			return (0);
		nb = ft_atoi(str);
	}
	else
		nb = 0;
	if (!ft_nodouble(nb, a))
		return (0);
	return (1);
}

int	ft_if_zero(char *str)
{
	int		i;
	int		azero;

	i = 0;
	azero = NO;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '0')
	{
		while (str[i] == '0')
			i++;
		if (!str[i])
			azero = YES;
	}
	return (azero);
}

// to see wether the inputs in av are char of numbers
int	ft_isnb(char *c)
{
	int	i;

	i = 0;
	if (!ft_isdigit(c[i]) && c[i] != '-' && c[i] != '+' )
		return (0);
	i++;
	while (c[i])
	{
		if (!ft_isdigit(c[i]))
			return (0);
		i++;
	}
	return (1);
}

// to see if already has the same nb in the stack.
int	ft_nodouble(int nb, t_node *a)
{
	t_node	*tmp;

	if (a == NULL)
		return (1);
	tmp = ft_get_start(a);
	while (tmp)
	{
		if (tmp->value == nb)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	ft_is_sorted(t_node *stack, int *flag)
{
	t_node	*tmp;

	tmp = ft_get_start(stack);
	if (! tmp)
		*flag = EMPTY;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
		{
			*flag = NO;
			break ;
		}
		tmp = tmp->next;
	}
}
