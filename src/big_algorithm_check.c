/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algorithm_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 04:50:23 by drestrep          #+#    #+#             */
/*   Updated: 2023/12/22 17:07:53 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	max_num_on_top(t_list **stack, int size)
{
	int     max_number;
	int     max_number_position;
	int     node_number;

	t_list *aux = *stack;

	max_number = *(int *)(*stack)->content;
	max_number_position = 0;
	node_number = 0;
	while (*stack)
	{
		if (*(int *)(*stack)->content > max_number)
		{
			max_number = *(int *)(*stack)->content;
			max_number_position = node_number;
		}
		*stack = (*stack)->next;
		node_number++;
	}
	*stack = aux;
	if (max_number_position > size/2)
		max_number_position = size - max_number_position;
	return(max_number_position);
}

int	get_operator_number(t_list **stack_a, t_list *stack_a_first_nb, int operator_position)
{
	int	position = 0;
	int	operator_number;

	*stack_a = stack_a_first_nb;
	while (position < operator_position)
	{
		*stack_a = (*stack_a)->next;
		position++;
	}
	operator_number = *(int *)(*stack_a)->content;
	*stack_a = stack_a_first_nb;
	return(operator_number);
}

int	get_double_rotate(t_list *stack_a, t_list *stack_b, int operator_position, int stack_b_number_position, int total_operations)
{
	int	operations;

	operations = 0;
	if (operator_position == 0 || stack_b_number_position == 0)
		return (total_operations);
	if (operator_position > ft_lstsize(stack_a)/2 && stack_b_number_position > ft_lstsize(stack_b)/2)
	{
		if (ft_lstsize(stack_a) - operator_position < ft_lstsize(stack_b) - stack_b_number_position)
		{
			operations = ft_lstsize(stack_a) - operator_position;
			operations = operations + ft_lstsize(stack_b) - stack_b_number_position - operations + 1;
		}
		else if (ft_lstsize(stack_b) - stack_b_number_position < ft_lstsize(stack_a) - operator_position)
		{
			operations = ft_lstsize(stack_b) - stack_b_number_position;
			operations = operations + ft_lstsize(stack_a) - operator_position - operations + 1;
		}
	}
	else if (operator_position <= ft_lstsize(stack_a)/2 && stack_b_number_position <= ft_lstsize(stack_b)/2)
	{
		operations = operator_position + 1;
		if (operator_position < stack_b_number_position)
			operations = operator_position + (stack_b_number_position - operator_position) + 1;
		if (stack_b_number_position < operator_position)
			operations = stack_b_number_position + (operator_position - stack_b_number_position) + 1;
	}
	if (operations < total_operations && operations != 0)
		total_operations = operations;
	return (total_operations);
}

void	is_min_or_max(t_list **stack_a, int operator_number, int operator_position, int current_position)
{
	int	total_operations;
	int	minimum_operations;

	total_operations = 0;
	minimum_operations = 0;
	if (minimum_operations == 0)
		minimum_operations = total_operations;
	if (total_operations < minimum_operations)
	{
		operator_number = *(int *)(*stack_a)->content;
		operator_position = current_position;
		minimum_operations = total_operations;
	}
}

int	get_operator_position(t_list **stack_a, t_list *stack_a_first_nb, t_list **stack_b, int operator_number)
{
	int	operator_position = 0;
	int	minimum_operations = 0;
	int	total_operations = 0;
	int	current_position = 0;

	while (*stack_a)
	{
		operator_number	= *(int *)(*stack_a)->content;
		if (check_if_min_or_max(stack_b, operator_number) == 0)
		{
			//total_operations = max_num_on_top(stack_b, ft_lstsize(*stack_b)) + max_or_min_number(current_position, ft_lstsize(stack_a_first_nb)) + 1;
			//total_operations = get_double_rotate(stack_a_first_nb, *stack_b, current_position, get_max_number_position(stack_b), total_operations);
			is_min_or_max (stack_a, operator_number, operator_position, current_position);
			if (minimum_operations == 0)
				minimum_operations = total_operations;
			if (total_operations < minimum_operations)
			{
				operator_number = *(int *)(*stack_a)->content;
				operator_position = current_position;
				minimum_operations = total_operations;
			}
		}
		
		//else
		if (check_if_min_or_max(stack_b, operator_number) == 1)
		{
			total_operations = middle_number(stack_b, operator_number, ft_lstsize(*stack_b)) + max_or_min_number(current_position, ft_lstsize(stack_a_first_nb)) + 1;
			total_operations = get_double_rotate(stack_a_first_nb, *stack_b, current_position, get_smaller_number_position(stack_b, operator_number, 0, 0), total_operations);
			if (minimum_operations == 0)
				minimum_operations = total_operations;
			if (total_operations < minimum_operations)
			{
				minimum_operations = total_operations;
				operator_position = current_position;
				operator_number = *(int *)(*stack_a)->content;
			}
		}
		*stack_a = (*stack_a)->next;
		current_position++;
	}
	return (operator_position);
}

void	sort_big(t_list **stack_a, t_list **stack_b)
{
	t_list	*stack_a_first_nb;
	int		operator_number;
	int		operator_position;
	
	push_b(stack_a, stack_b);
	push_b(stack_a, stack_b);
	while (ft_lstsize(*stack_a) > 3)
	{
		stack_a_first_nb = *stack_a;
		operator_position = get_operator_position(stack_a, stack_a_first_nb, stack_b, 0);
		operator_number = get_operator_number(stack_a, stack_a_first_nb, operator_position);
		*stack_a = stack_a_first_nb;
		move_operator(stack_a, stack_b, operator_number, operator_position);
	}
	push_back(stack_a, stack_b);
}
