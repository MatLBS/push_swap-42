/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:25:58 by matle-br          #+#    #+#             */
/*   Updated: 2024/07/10 13:40:13 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	max_value(t_stack *stack)
{
	int	max;
	int	i;

	i = 0;
	max = stack->stack_node->value;
	while (i < stack->size)
	{
		if (max < stack->stack_node->value)
			max = stack->stack_node->value;
		i++;
		stack->stack_node = stack->stack_node->next;
	}
	return (max);
}

int	min_value(t_stack *stack)
{
	int	i;
	int	min;

	i = 0;
	min = stack->stack_node->value;
	while (i < stack->size)
	{
		if (min > stack->stack_node->value)
			min = stack->stack_node->value;
		i++;
		stack->stack_node = stack->stack_node->next;
	}
	return (min);
}

void	check_double(char **buf, int j, int i, int flag)
{
	while (buf[++j])
	{
		if (ft_atol(buf[i]) == ft_atol(buf[j]))
		{
			if (flag == 1)
			{
				ft_free_split(buf);
				ft_error();
			}
			else
				ft_error();
		}
	}
}
