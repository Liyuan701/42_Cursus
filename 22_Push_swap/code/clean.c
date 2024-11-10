/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <rohanafan@sina.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:00:23 by lifan             #+#    #+#             */
/*   Updated: 2024/10/24 18:00:23 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_error_initial(t_node **a, char **av, int ac)
{
	ft_printf("Error\n");
	ft_free_node(*a);
	if (ac == 2)
		ft_free_tab(av);
	exit(FAIL);
}

void	ft_free_tab(char **av)
{
	int	i;

	i = 0;
	if (av == NULL || av[0] == NULL)
		return ;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
}

// free all nodes from the first one.
// use the tmp to note down the next address.
void	ft_free_node(t_node *stack)
{
	t_node	*tmp;

	if (stack == NULL)
		return ;
	stack = ft_get_start(stack);
	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}
