/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 15:43:28 by matle-br          #+#    #+#             */
/*   Updated: 2024/07/03 11:40:52 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rotate(t_stack *stack)
{
	if (!stack->stack_node)
		return ;
	stack->stack_node = stack->stack_node->next;
}

void	ra(t_stack *stack_a, int flag)
{
	ft_rotate(stack_a);
	if (flag == 1)
		ft_putendl_fd("ra", 1);
}

void	rb(t_stack *stack_b, int flag)
{
	ft_rotate(stack_b);
	if (flag == 1)
		ft_putendl_fd("rb", 1);
}

void	rr(t_stack *stack_a, t_stack *stack_b, int flag)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	if (flag == 1)
		ft_putendl_fd("rr", 1);
}
