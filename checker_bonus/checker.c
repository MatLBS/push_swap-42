/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:16:08 by matle-br          #+#    #+#             */
/*   Updated: 2024/07/11 10:42:16 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/get_next_line.h"

int	which_instruction(char *str, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strcmp(str, "pa\n") == 0)
		pa(stack_a, stack_b, 0);
	else if (ft_strcmp(str, "pb\n") == 0)
		pb(stack_a, stack_b, 0);
	else if (ft_strcmp(str, "ra\n") == 0)
		ra(stack_a, 0);
	else if (ft_strcmp(str, "rb\n") == 0)
		rb(stack_b, 0);
	else if (ft_strcmp(str, "rr\n") == 0)
		rr(stack_a, stack_b, 0);
	else if (ft_strcmp(str, "rra\n") == 0)
		rra(stack_a, 0);
	else if (ft_strcmp(str, "rrb\n") == 0)
		rrb(stack_b, 0);
	else if (ft_strcmp(str, "rrr\n") == 0)
		rrr(stack_a, stack_b, 0);
	else if (ft_strcmp(str, "sa\n") == 0)
		sa(stack_a, 0);
	else if (ft_strcmp(str, "sb\n") == 0)
		sb(stack_b, 0);
	else if (ft_strcmp(str, "ss\n") == 0)
		ss(stack_a, stack_b, 0);
	else
		return (0);
	return (1);
}

void	clean_checker(t_stack *stack_a, t_stack *stack_b, char *str, int fd)
{
	(void)str;
	if (stack_a)
		ft_free_stack(stack_a, NULL);
	if (stack_b)
		ft_free_stack(stack_b, NULL);
	free(str);
	close(fd);
	ft_error();
}

int	main(int ac, char **av)
{
	t_stack		stack_a;
	t_stack		stack_b;
	char		*str;
	int			size_base;

	init_stack(&stack_a, &stack_b, av, ac);
	size_base = stack_a.size;
	str = get_next_line(STDIN_FILENO);
	while (str != NULL)
	{
		if (!which_instruction(str, &stack_a, &stack_b))
			clean_checker(&stack_a, &stack_b, str, STDIN_FILENO);
		free(str);
		str = get_next_line(STDIN_FILENO);
	}
	if (stack_a.size == size_base && is_sorted(&stack_a) == 1)
		ft_putstr_fd("OK\n", 2);
	else
		ft_putstr_fd("KO\n", 2);
	ft_free_stack(&stack_a, NULL);
	ft_free_stack(&stack_b, NULL);
	return (0);
}
