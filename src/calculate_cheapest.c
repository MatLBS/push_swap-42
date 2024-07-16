/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cheapest.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 13:12:33 by matle-br          #+#    #+#             */
/*   Updated: 2024/07/14 13:12:33 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	calculate_cheapest(t_stack *stack_a, t_stack *stack_b)
{
	t_s_node	*closest;
	t_s_node	*head;
	int			i;
	int			minus;

	i = 0;
	head = stack_a->stack_node;
	while (i < stack_a->size)
	{
		set_current_position(stack_a);
		set_current_position(stack_b);
		closest = find_closest(head, stack_b);
		if (head->above_median == true)
			head->push_price = head->position;
		else
			head->push_price = stack_a->size - head->position;
		if (closest->above_median == true)
			head->push_price += closest->position;
		else
			head->push_price += stack_b->size - closest->position;
		minus = calculate_minus(head, closest, stack_a, stack_b);
		head->push_price -= minus;
		i++;
		head = head->next;
	}
}

void	cheapest_on_top(t_stack *stack_a, t_stack *stack_b)
{
	t_s_node	*cheapest;
	t_s_node	*closest;

	cheapest = return_cheapest(stack_a);
	closest = find_closest(cheapest, stack_b);
	if (cheapest->above_median && closest->above_median)
		rotate_both(stack_a, stack_b, cheapest, closest);
	else if (!cheapest->above_median && !closest->above_median)
		rev_rotate_both(stack_a, stack_b, cheapest, closest);
	end_rotation(stack_a, cheapest, 'a');
	end_rotation(stack_b, closest, 'b');
}

t_s_node	*find_closest(t_s_node *node, t_stack *stack_b)
{
	t_s_node	*closest;
	t_s_node	*biggest;
	t_s_node	*head;
	int			i;

	biggest = find_max(stack_b);
	closest = NULL;
	head = stack_b->stack_node;
	i = 0;
	while (i < stack_b->size)
	{
		if (head->value < node->value
			&& (closest == NULL || head->value > closest->value))
			closest = head;
		head = head->next;
		i++;
	}
	if (closest == NULL)
		closest = biggest;
	return (closest);
}

t_s_node	*find_closest_a(t_s_node *node, t_stack *stack_a)
{
	t_s_node	*closest;
	t_s_node	*smallest;
	t_s_node	*head;
	int			i;

	i = 0;
	closest = NULL;
	head = stack_a->stack_node;
	smallest = find_smallest(stack_a);
	while (i < stack_a->size)
	{
		if (head->value > node->value && (closest == NULL
				|| head->value < closest->value))
			closest = head;
		head = head->next;
		i++;
	}
	if (closest == NULL)
		closest = smallest;
	return (closest);
}

void	closest_on_top(t_s_node *closest, t_stack *stack)
{
	while (stack->stack_node != closest)
	{
		if (closest->position <= stack->size / 2)
			ra(stack, 1);
		else
			rra(stack, 1);
	}
}
