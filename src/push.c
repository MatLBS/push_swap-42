/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 13:09:29 by matle-br          #+#    #+#             */
/*   Updated: 2024/07/03 11:40:09 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push(t_stack *stack_dest, int value)
{
	t_s_node	*new_element;
	t_s_node	*last;

	new_element = malloc(sizeof(t_s_node));
	if (new_element == NULL)
		return ;
	new_element->value = value;
	if (stack_dest->stack_node == NULL)
	{
		stack_dest->stack_node = new_element;
		new_element->next = new_element;
		new_element->prev = new_element;
	}
	else
	{
		last = stack_dest->stack_node->prev;
		new_element->next = stack_dest->stack_node;
		new_element->prev = last;
		last->next = new_element;
		stack_dest->stack_node->prev = new_element;
	}
	stack_dest->stack_node = new_element;
}

int	pop(t_stack *stack)
{
	int			value;
	t_s_node	*head;
	t_s_node	*new_head;
	t_s_node	*tail;

	head = stack->stack_node;
	value = stack->stack_node->value;
	if (stack == NULL)
		return (-1);
	if (head == head->next)
	{
		free(head);
		stack->stack_node = NULL;
	}
	else
	{
		tail = head->prev;
		new_head = head->next;
		new_head->prev = tail;
		tail->next = new_head;
		stack->stack_node = new_head;
		free(head);
	}
	return (value);
}

void	pa(t_stack *stack_a, t_stack *stack_b, int flag)
{
	if (!stack_b->stack_node)
		return ;
	stack_a->size++;
	stack_b->size--;
	push(stack_a, pop(stack_b));
	if (flag == 1)
		ft_putendl_fd("pa", 1);
}

void	pb(t_stack *stack_a, t_stack *stack_b, int flag)
{
	if (!stack_a->stack_node)
		return ;
	stack_a->size--;
	stack_b->size++;
	push(stack_b, pop(stack_a));
	if (flag == 1)
		ft_putendl_fd("pb", 1);
}
