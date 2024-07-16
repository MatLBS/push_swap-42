/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 10:35:49 by matle-br          #+#    #+#             */
/*   Updated: 2024/07/03 10:53:46 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_stack		stack_a;
	t_stack		stack_b;

	init_stack(&stack_a, &stack_b, av, ac);
	if (!is_sorted(&stack_a))
		push_swap(&stack_a, &stack_b);
	ft_free_stack(&stack_a, NULL);
	ft_free_stack(&stack_b, NULL);
	return (0);
}
