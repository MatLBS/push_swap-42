/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:00:17 by matle-br          #+#    #+#             */
/*   Updated: 2024/07/15 17:21:41 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_2(t_stack *stack_a)
{
	if (stack_a->stack_node->value > stack_a->stack_node->next->value)
		sa(stack_a, 1);
}

void	sort_3(t_stack *stack_a)
{
	int	a;
	int	b;
	int	c;

	a = stack_a->stack_node->value;
	b = stack_a->stack_node->next->value;
	c = stack_a->stack_node->next->next->value;
	if (a > b && a > c && c > b)
		ra(stack_a, 1);
	else if (a < b && c < b && c > a)
	{
		rra(stack_a, 1);
		sa(stack_a, 1);
	}
	else if (a > b && b < c)
		sa(stack_a, 1);
	else if (b > a && b > c)
		rra(stack_a, 1);
	else if (a > b && a > c)
	{
		sa(stack_a, 1);
		rra(stack_a, 1);
	}
}

void	sort_4_or_5(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->size > 3)
	{
		min_on_top(stack_a);
		pb(stack_a, stack_b, 1);
	}
	sort_3(stack_a);
	while (stack_b->stack_node)
		pa(stack_a, stack_b, 1);
}

void	big_algorithm(t_stack *stack_a, t_stack *stack_b)
{
	int			i;
	t_s_node	*closest;

	i = 0;
	pb(stack_a, stack_b, 1);
	pb(stack_a, stack_b, 1);
	while (stack_a->size > 3)
	{
		calculate_cheapest(stack_a, stack_b);
		set_current_position(stack_a);
		set_current_position(stack_b);
		cheapest_on_top(stack_a, stack_b);
		pb(stack_a, stack_b, 1);
	}
	sort_3(stack_a);
	while (stack_b->size)
	{
		set_current_position(stack_a);
		closest = find_closest_a(stack_b->stack_node, stack_a);
		set_current_position(stack_a);
		closest_on_top(closest, stack_a);
		pa(stack_a, stack_b, 1);
	}
	min_on_top(stack_a);
}

void	push_swap(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_b;
	if (stack_a->size <= 1)
		return ;
	if (stack_a->size == 2)
		sort_2(stack_a);
	else if (stack_a->size == 3)
		sort_3(stack_a);
	else if (stack_a->size == 4 || stack_a->size == 5)
		sort_4_or_5(stack_a, stack_b);
	else
		big_algorithm(stack_a, stack_b);
}
