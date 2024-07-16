/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 11:49:30 by matle-br          #+#    #+#             */
/*   Updated: 2024/07/03 11:42:09 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack *stack)
{
	int		tmp;

	if (!stack->stack_node)
		return ;
	if (stack->size < 2)
		return ;
	tmp = stack->stack_node->value;
	stack->stack_node->value = stack->stack_node->next->value;
	stack->stack_node->next->value = tmp;
}

void	sa(t_stack *stack_a, int flag)
{
	swap(stack_a);
	if (flag == 1)
		ft_putendl_fd("sa", 1);
}

void	sb(t_stack *stack_b, int flag)
{
	swap(stack_b);
	if (flag == 1)
		ft_putendl_fd("sb", 1);
}

void	ss(t_stack *stack_a, t_stack *stack_b, int flag)
{
	swap(stack_a);
	swap(stack_b);
	if (flag == 1)
		ft_putendl_fd("ss", 1);
}
