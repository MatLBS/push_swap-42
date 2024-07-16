/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 10:00:40 by matle-br          #+#    #+#             */
/*   Updated: 2024/07/15 17:17:35 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_s_node	*return_cheapest(t_stack *stack)
{
	int			i;
	t_s_node	*cheapest;
	t_s_node	*head;

	i = 0;
	cheapest = stack->stack_node;
	head = stack->stack_node;
	while (i < stack->size)
	{
		if (cheapest->push_price > head->push_price)
			cheapest = head;
		i++;
		head = head->next;
	}
	return (cheapest);
}

void	end_rotation(t_stack *stack, t_s_node *cheapest, char c)
{
	while (stack->stack_node != cheapest)
	{
		if (c == 'a')
		{
			if (cheapest->above_median == true)
				ra (stack, 1);
			else
				rra (stack, 1);
		}
		if (c == 'b')
		{
			if (cheapest->above_median == true)
				rb (stack, 1);
			else
				rrb (stack, 1);
		}
	}
}

void	set_current_position(t_stack *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack || !stack->stack_node)
		return ;
	median = stack->size / 2;
	while (i < stack->size)
	{
		stack->stack_node->position = i;
		if (i < median)
			stack->stack_node->above_median = true;
		else
			stack->stack_node->above_median = false;
		stack->stack_node = stack->stack_node->next;
		i++;
	}
}

void	set_current_position_push_price(t_stack *stack)
{
	int	i;
	int	median;

	i = 1;
	if (!stack || !stack->stack_node)
		return ;
	median = stack->size / 2;
	while (i < stack->size)
	{
		stack->stack_node->position = i;
		if (i < median)
			stack->stack_node->above_median = true;
		else
			stack->stack_node->above_median = false;
		stack->stack_node = stack->stack_node->next;
		i++;
	}
}

int	calculate_minus(t_s_node *head, t_s_node *closest, \
	t_stack *stack_a, t_stack *stack_b)
{
	int	minus;

	minus = 0;
	if (head->above_median && closest->above_median)
	{
		if (head->position < closest->position)
			minus = head->position;
		else
			minus = closest->position;
	}
	if (!head->above_median && !closest->above_median)
	{
		if ((stack_a->size - head->position) < \
		(stack_b->size - closest->position))
			minus = stack_a->size - head->position;
		else
			minus = stack_b->size - closest->position;
	}
	return (minus);
}
