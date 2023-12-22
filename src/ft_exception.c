/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exception.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 21:16:32 by drestrep          #+#    #+#             */
/*   Updated: 2023/08/28 04:28:36 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
/* position = 0;
		while (*stack_a)
		{
			if (check_all_doubles(*stack_a, *stack_b, operator_position, get_middle_number_position(stack_b, *(int *)(*stack_a)->content)) == 0)
			{
				operator_number = *(int *)(*stack_a)->content;
				operator_position = position;
			}
			position++;
			*stack_a = (*stack_a)->next;
		}
		*stack_a = stack_a_first_nb; */
int	get_all_doubles_operations (t_list *stack_a, t_list *stack_b, int number_position, int stack_b_number_position, int minimum_operations)
{
	int	operations;

	operations = 0;
	if (operations == minimum_operations)
		return (0);
	while ((number_position > ft_lstsize(stack_a)/2 && stack_b_number_position > ft_lstsize(stack_b)/2)
			&& (number_position < ft_lstsize(stack_a) && stack_b_number_position < ft_lstsize(stack_b)))
	{
		number_position++;
		stack_b_number_position++;
		operations++;
	}
	while ((number_position < ft_lstsize(stack_a)/2 && stack_b_number_position < ft_lstsize(stack_b)/2)
			&& (number_position > 0 && stack_b_number_position > 0))
	{
		number_position--;
		stack_b_number_position--;
		operations++;
	}
	return (operations);
}

int	check_all_doubles (t_list *stack_a, t_list *stack_b, int number_position, int stack_b_number_position)
{
	int	result;

	result = -1;
	while ((number_position > ft_lstsize(stack_a)/2 && stack_b_number_position > ft_lstsize(stack_b)/2)
			&& (number_position < ft_lstsize(stack_a) && stack_b_number_position < ft_lstsize(stack_b)))
	{
		number_position++;
		stack_b_number_position++;
		if (number_position == ft_lstsize(stack_a) && stack_b_number_position == ft_lstsize(stack_b))
			result = 0;
	}
	while ((number_position < ft_lstsize(stack_a)/2 && stack_b_number_position < ft_lstsize(stack_b)/2)
			&& (number_position > 0 && stack_b_number_position > 0))
	{
		number_position--;
		stack_b_number_position--;
		if (number_position == 0 && stack_b_number_position == 0)
			result = 0;
	}
	if (result == -1)
		result = 1;
	return (result);
}

/* int	ft_exception (t_list **stack_a, t_list **stack_b, int operator_number, int operator_position, char c)
{
	int number;
	int node_number;
	int	position;
	int	all_doubles;
	int	min_or_max;
	t_list *stack_a_first_nb;

	node_number = 0;
	min_or_max = check_if_min_or_max(stack_a, (*stack_a)->content);
	stack_a_first_nb = *stack_a;
	while (*stack_a)
	{
		all_doubles = check_all_doubles(stack_a_first_nb, *stack_b, node_number, get_middle_number_position(stack_b, (*stack_a)->content));
		if (all_doubles == 0)
		{
			number = (*stack_a)->content;
			position = node_number;
		}
		node_number++;
		*stack_a = (*stack_a)->next;
	}
	*stack_a = stack_a_first_nb;
	if (c == 'n')
		return (number);
	if (c == 'p')
		return (position);
} */