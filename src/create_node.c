/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:29:02 by matle-br          #+#    #+#             */
/*   Updated: 2024/07/10 12:35:19 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long	ft_atol(const char *nptr)
{
	int		i;
	double	valeur;
	int		sign;

	i = 0;
	valeur = 0;
	sign = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
		if (nptr[i] == '-' || nptr[i] == '+')
			ft_error();
	}
	else if (nptr[i] == '+')
		if (nptr[i + 1] == '-' || nptr[i + 1] == '+')
			ft_error();
	while (nptr[i] != '\0' && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		valeur = valeur * 10 + nptr[i] - '0';
		i++;
	}
	return (sign * valeur);
}

t_s_node	*new_node(long value, t_stack *stack_a, char **buf, int flag)
{
	t_s_node	*new_element;

	if (value > 2147483647 || value < -2147483648)
	{
		if (flag == 1)
			ft_free_stack(stack_a, buf);
		else
			ft_free_stack(stack_a, NULL);
		ft_error();
	}
	new_element = malloc(sizeof(t_s_node));
	if (!new_element)
	{
		ft_free_stack(stack_a, buf);
		ft_error();
	}
	new_element->value = value;
	new_element->next = NULL;
	new_element->prev = NULL;
	return (new_element);
}

void	add_to_stack(t_stack *stack, t_s_node *new_element)
{
	t_s_node	*last;

	if (!stack->stack_node)
	{
		stack->stack_node = new_element;
		new_element->next = new_element;
		new_element->prev = new_element;
	}
	else
	{
		last = stack->stack_node->prev;
		new_element->next = stack->stack_node;
		new_element->prev = last;
		last->next = new_element;
		stack->stack_node->prev = new_element;
	}
	stack->size += 1;
}

void	ft_create_split(char **av, t_stack *stack_a, int ac)
{
	char			**buf;
	t_s_node		*tmp;
	int				i;

	i = 0;
	if (*av[1] == '\0')
		ft_error();
	buf = ft_split(av[1], ' ');
	if (buf == NULL)
	{
		ft_free_split(buf);
		ft_error();
	}
	check_input_split(buf, ac);
	while (buf[i])
	{
		tmp = new_node(ft_atol(buf[i]), stack_a, buf, 1);
		add_to_stack(stack_a, tmp);
		i++;
	}
	ft_free_split(buf);
}

void	init_stack(t_stack *stack_a, t_stack *stack_b, char **av, int ac)
{
	int				i;
	t_s_node		*tmp;

	stack_a->stack_node = NULL;
	stack_b->stack_node = NULL;
	stack_a->size = 0;
	stack_b->size = 0;
	i = 1;
	if (ac == 1)
		exit(0);
	if (ac == 2)
		ft_create_split(av, stack_a, ac);
	else
	{
		check_input(av, ac);
		while (i < ac)
		{
			tmp = new_node(ft_atol(av[i]), stack_a, av, 0);
			add_to_stack(stack_a, tmp);
			i++;
		}
	}
}
