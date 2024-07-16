/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 10:33:01 by matle-br          #+#    #+#             */
/*   Updated: 2024/07/15 17:17:02 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack_node
{
	int						value;
	int						position;
	int						index;
	int						push_price;
	bool					above_median;
	bool					cheapest;
	struct s_stack_node		*prev;
	struct s_stack_node		*next;
	struct s_stack_node		*target_node;
}	t_s_node;

typedef struct s_stack
{
	t_s_node	*stack_node;
	int			size;
}	t_stack;

/* Algo_Utils */
void		rotate_both(t_stack *stack_a, t_stack *stack_b, \
	t_s_node *cheapest_node, t_s_node *closest);
void		rev_rotate_both(t_stack *stack_a, t_stack *stack_b, \
	t_s_node *cheapest_node, t_s_node *closest);
t_s_node	*find_smallest(t_stack *stack);
t_s_node	*find_max(t_stack *stack);

/* Algo_Utils2 */
t_s_node	*return_cheapest(t_stack *stack);
void		end_rotation(t_stack *stack, t_s_node *cheapest, char c);
void		set_current_position(t_stack *stack);
void		set_current_position_push_price(t_stack *stack);
int			calculate_minus(t_s_node *head, t_s_node *closest, \
	t_stack *stack_a, t_stack *stack_b);

/* Create_Node*/
t_s_node	*new_node(long value, t_stack *stack_a, char **buf, int flag);
void		add_to_stack(t_stack *stack, t_s_node *new_element);
void		ft_create_split(char **av, t_stack *stack_a, int ac);
long		ft_atol(const char *nptr);
void		init_stack(t_stack *stack_a, t_stack *stack_b, char **av, int ac);

/* Calculate_cheapest */
void		calculate_cheapest(t_stack *stack_a, t_stack *stack_b);
void		cheapest_on_top(t_stack *stack_a, t_stack *stack_b);
t_s_node	*find_closest(t_s_node *node, t_stack *stack_b);
t_s_node	*find_closest_a(t_s_node *node, t_stack *stack_a);
void		closest_on_top(t_s_node *closest, t_stack *stack);

/* Error*/
void		check_input(char **buf, int ac);
void		ft_error(void);
void		ft_free_split(char	**buf);
void		ft_free_stack(t_stack *stack, char **buf);
void		check_input_split(char **buf, int ac);

/* Push_Swap_Utils */
void		get_position(t_s_node *node, t_stack *stack);
t_s_node	*find_min(t_stack *stack_a);
void		min_on_top(t_stack *stack_a);
void		max_on_top(t_stack *stack);
int			is_sorted(t_stack *stack);

/* Push_Swap */
void		sort_2(t_stack *stack_a);
void		sort_3(t_stack *stack_a);
void		sort_4_or_5(t_stack *stack_a, t_stack *stack_b);
void		big_algorithm(t_stack *stack_a, t_stack *stack_b);
void		push_swap(t_stack *stack_a, t_stack *stack_b);

/* Push */
void		push(t_stack *stack_dest, int value);
int			pop(t_stack *stack);
void		pa(t_stack *stack_a, t_stack *stack_b, int flag);
void		pb(t_stack *stack_a, t_stack *stack_b, int flag);

/* Rotate */
void		ft_rotate(t_stack *stack);
void		ra(t_stack *stack_a, int flag);
void		rb(t_stack *stack_b, int flag);
void		rr(t_stack *stack_a, t_stack *stack_b, int flag);

/* Reverse_Rotate*/
void		ft_rev_rotate(t_stack *stack);
void		rra(t_stack *stack_a, int flag);
void		rrb(t_stack *stack_b, int flag);
void		rrr(t_stack *stack_a, t_stack *stack_b, int flag);

/* Swap */
void		swap(t_stack *stack);
void		sa(t_stack *stack_a, int flag);
void		sb(t_stack *stack_b, int flag);
void		ss(t_stack *stack_a, t_stack *stack_b, int flag);

/* Utils */
int			max_value(t_stack *stack);
int			min_value(t_stack *stack);
void		check_double(char **buf, int j, int i, int flag);

/* Checker */
int			which_instruction(char *str, t_stack *stack_a, t_stack *stack_b);
void		clean_checker(t_stack *stack_a, t_stack *stack_b, \
				char *str, int fd);
int			main(int ac, char **av);

#endif
