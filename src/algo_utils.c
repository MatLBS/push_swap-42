/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 18:55:09 by matle-br          #+#    #+#             */
/*   Updated: 2024/07/15 10:25:38 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_both(t_stack *stack_a, t_stack *stack_b, \
	t_s_node *cheapest_node, t_s_node *closest)
{
	while (stack_a->stack_node != cheapest_node
		&& stack_b->stack_node != closest)
		rr(stack_a, stack_b, 1);
	set_current_position(stack_a);
	set_current_position(stack_b);
}

void	rev_rotate_both(t_stack *stack_a, t_stack *stack_b, \
	t_s_node *cheapest_node, t_s_node *closest)
{
	while (stack_a->stack_node != cheapest_node
		&& stack_b->stack_node != closest)
		rrr(stack_a, stack_b, 1);
	set_current_position(stack_a);
	set_current_position(stack_b);
}

t_s_node	*find_smallest(t_stack *stack)
{
	t_s_node	*smallest;
	t_s_node	*head;
	int			i;

	if (!stack || !stack->stack_node)
		return (NULL);
	head = stack->stack_node->next;
	smallest = stack->stack_node;
	i = 0;
	while (i < stack->size)
	{
		if (head->value < smallest->value)
			smallest = head;
		head = head->next;
		i++;
	}
	return (smallest);
}

t_s_node	*find_max(t_stack *stack)
{
	t_s_node	*biggest;
	t_s_node	*head;
	int			i;

	if (!stack || !stack->stack_node)
		return (NULL);
	head = stack->stack_node->next;
	biggest = stack->stack_node;
	i = 0;
	while (i < stack->size)
	{
		if (head->value > biggest->value)
			biggest = head;
		head = head->next;
		i++;
	}
	return (biggest);
}
