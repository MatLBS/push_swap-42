/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:22:48 by matle-br          #+#    #+#             */
/*   Updated: 2024/07/03 11:41:25 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rev_rotate(t_stack *stack)
{
	if (!stack->stack_node)
		return ;
	stack->stack_node = stack->stack_node->prev;
}

void	rra(t_stack *stack_a, int flag)
{
	ft_rev_rotate(stack_a);
	if (flag == 1)
		ft_putendl_fd("rra", 1);
}

void	rrb(t_stack *stack_b, int flag)
{
	ft_rev_rotate(stack_b);
	if (flag == 1)
		ft_putendl_fd("rrb", 1);
}

void	rrr(t_stack *stack_a, t_stack *stack_b, int flag)
{
	ft_rev_rotate(stack_a);
	ft_rev_rotate(stack_b);
	if (flag == 1)
		ft_putendl_fd("rrr", 1);
}
