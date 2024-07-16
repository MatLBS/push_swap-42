/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:42:22 by matle-br          #+#    #+#             */
/*   Updated: 2024/07/10 13:41:38 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	check_input(char **buf, int ac)
{
	int	i;
	int	j;

	if (ac == 2)
		i = 0;
	else
		i = 1;
	while (buf[i])
	{
		j = 0;
		if (buf[i][j] == '-' || buf[i][j] == '+')
			j++;
		while (buf[i][j])
		{
			if (buf[i][j] < '0' || buf[i][j] > '9')
				ft_error();
			j++;
		}
		j = i;
		check_double(buf, j, i, 0);
		i++;
	}
}

void	check_input_split(char **buf, int ac)
{
	int	i;
	int	j;

	if (ac == 2)
		i = 0;
	else
		i = 1;
	while (buf[i])
	{
		j = 0;
		if (buf[i][j] == '-' || buf[i][j] == '+')
			j++;
		while (buf[i][j])
		{
			if (buf[i][j] < '0' || buf[i][j] > '9')
			{
				ft_free_split(buf);
				ft_error();
			}
			j++;
		}
		j = i;
		check_double(buf, j, i, 1);
		i++;
	}
}

void	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(0);
}

void	ft_free_split(char	**buf)
{
	int	i;

	i = 0;
	while (buf[i])
	{
		free(buf[i]);
		i++;
	}
	free(buf);
}

void	ft_free_stack(t_stack *stack, char **buf)
{
	t_s_node	*tmp;
	t_s_node	*head;

	if (stack->stack_node)
	{
		head = stack->stack_node->prev;
		while (stack->stack_node != head)
		{
			stack->stack_node->value = 0;
			tmp = stack->stack_node->next;
			free(stack->stack_node);
			stack->stack_node = tmp;
		}
		free(head);
	}
	if (!buf)
		return ;
	ft_free_split(buf);
}
