/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <rohanafan@sina.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:12:57 by lifan             #+#    #+#             */
/*   Updated: 2024/11/04 15:12:57 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft.h"

# define FAIL	1
# define NO		0
# define YES	7
# define SPACE	' '
# define PLUS	100
# define LESS	101
# define EMPTY	103
# define TOSO	104
# define MUTE	105
# define PRINT	106
# define MAX	107
# define MIN	108
# define EXIST	109

//Structures

typedef struct s_node
{
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_info
{
	int		min_value;
	int		max_value;
	int		min_index;
	int		max_index;
	int		cheap_a;
	int		ia;
	int		ib;
	int		minm;
	int		moves;
	int		way;
	t_node	*cheap_a_node;
}	t_info;

//Functions

void	ft_error_initial(t_node **a, char **av, int ac);
void	ft_free_tab(char **av);
void	ft_free_node(t_node *stack);
void	ft_initial(t_node **a, char **av, int ac);
t_node	*ft_extend(t_node *old, int value);
t_node	*ft_new_node(int value);
void	ft_atoi_flag(char *str, int *flag);
void	ft_distribute(t_node **a, t_node **b, int len);

int		ft_isvalide(t_node *a, char *str);
int		ft_isnb(char *c);
int		ft_nodouble(int nb, t_node *a);
void	ft_is_sorted(t_node *stack, int *flag);
int		ft_if_zero(char *str);

void	ft_rotate(t_node **stack, char c, int flag);
void	ft_rroate(t_node **stack, char c, int flag);
void	ft_rr(t_node **a, t_node **b, int flag);
void	ft_rrr(t_node **a, t_node **b, int flag);

void	ft_swap(t_node **stack, char c, int flag);
void	ft_push(t_node **from, t_node **to, char t, int flag);
void	ft_ss(t_node **a, t_node **b, int flag);

void	ft_sort_larg(t_node **a, t_node **b);
int		ft_merge(t_info *info, t_node **a, int bvalue);
void	ft_find_and_top(t_node **a, t_info *info, int ex);
void	ft_intra_top(t_node **a, char c, int index);

void	ft_sort_thre(t_node **a);
void	ft_sort_five(t_node **a, t_node **b, int len);

int		ft_node_len(t_node *stack);
void	ft_times(void (*func)(t_node **, char, int), \
	t_node **a, char c, int times);
void	ft_times_cm(void (*func)(t_node **, t_node **\
	, int), t_node **a, t_node **b, int times);
void	ft_times_ps(t_node **a, t_node **b, char c, int times);
int		ft_get_index(t_node *stack);

int		ft_get_vindex(t_node *stack, int value);
t_node	*ft_get_start(t_node *stack);
t_node	*ft_get_end(t_node *stack);
int		ft_get_max(t_info *info, t_node *stack);
int		ft_get_min(t_info *info, t_node *stack);

void	ft_do(t_info info, t_node **a, t_node **b);
void	ft_case_rr(t_node **a, t_node **b, int ma, int mb);
void	ft_case_rrr(t_node **a, t_node **b, int ma, int mb);
void	ft_case_r_rr(t_node **a, t_node **b, int ma, int mb);
void	ft_case_rr_r(t_node **a, t_node **b, int ma, int mb);

void	ft_cheap_a(t_info *info, t_node *a, t_node *b);
void	ft_count_a(t_info *info, t_node *a, t_node *b);
int		ft_find_b(t_info *info, t_node *a, t_node *b, int avalue);
void	ft_move_cost(t_info *info, int lena, int lenb);
void	ft_cmp(t_info *info, int move, int cas);

#endif
