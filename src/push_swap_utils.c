/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:01:04 by matle-br          #+#    #+#             */
/*   Updated: 2024/07/15 15:25:06 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	get_position(t_s_node *node, t_stack *stack)
{
	int				i;
	t_s_node		*current;

	current = stack->stack_node;
	i = 0;
	if (!node)
		return ;
	while (current)
	{
		if (current == node)
		{
			node->position = i;
			break ;
		}
		current = current->next;
		i++;
	}
}

t_s_node	*find_min(t_stack *stack_a)
{
	t_s_node	*min;
	t_s_node	*tmp;

	min = stack_a->stack_node;
	tmp = stack_a->stack_node->next;
	while (tmp != min)
	{
		if (min->value > tmp->value)
			min = tmp;
		tmp = tmp->next;
	}
	get_position(min, stack_a);
	return (min);
}

void	min_on_top(t_stack *stack_a)
{
	t_s_node	*min_value;

	min_value = find_min(stack_a);
	while (stack_a->stack_node != min_value)
	{
		if (min_value->position <= stack_a->size / 2)
			ra(stack_a, 1);
		else
			rra(stack_a, 1);
	}
}

void	max_on_top(t_stack *stack)
{
	t_s_node	*max_value;

	max_value = find_max(stack);
	while (stack->stack_node != max_value)
	{
		if (max_value->position <= stack->size / 2)
			rb(stack, 1);
		else
			rrb(stack, 1);
	}
}

int	is_sorted(t_stack *stack)
{
	t_s_node	*head;

	head = stack->stack_node;
	if (!head)
		return (0);
	while (head->next != stack->stack_node)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}
