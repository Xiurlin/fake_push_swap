/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algorithm_moves.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 04:16:37 by drestrep          #+#    #+#             */
/*   Updated: 2023/08/28 07:03:57 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	move_middle_number(t_list **stack_a, t_list **stack_b, int operator_number, int operator_position)
{
	int	just_smaller_number;
	int	just_smaller_operator_position;
	int	node_number;
	int	min_or_max;
	t_list *stack_b_first_nb;

	just_smaller_number = 0;
	just_smaller_operator_position = 0;
	node_number = 0;
	min_or_max = check_if_min_or_max (stack_a, operator_number);
	stack_b_first_nb = *stack_b;
	while (*stack_b)
	{
		if (just_smaller_number == 0 && *(int *)(*stack_b)->content < operator_number)
		{
			just_smaller_number = *(int *)(*stack_b)->content;
			just_smaller_operator_position = node_number;
		}
		if (*(int *)(*stack_b)->content < operator_number && *(int *)(*stack_b)->content > just_smaller_number)
		{
			just_smaller_number = *(int *)(*stack_b)->content;
			just_smaller_operator_position = node_number;
		}
		*stack_b = (*stack_b)->next;
		node_number++;
	}
	*stack_b = stack_b_first_nb;
	double_rotate(stack_a, stack_b, operator_number, operator_position, min_or_max);
	if (just_smaller_operator_position > ft_lstsize(*stack_b)/2)
	{
		while (just_smaller_operator_position < ft_lstsize(*stack_b))
		{
			revrotate_a_or_b(stack_b, 'b');
			just_smaller_operator_position++;
		}
	}
	else
	{
		while (just_smaller_operator_position > 0)
		{
			rotate_a_or_b(stack_b, 'b');
			just_smaller_operator_position--;
		}
	}
	if (operator_position > ft_lstsize(*stack_a)/2)
	{
		while (operator_position < ft_lstsize(*stack_a))
		{
			revrotate_a_or_b(stack_a, 'a');
			operator_position++;
		}
	}
	else
	{
		while (operator_position > 0)
		{
			rotate_a_or_b(stack_a, 'a');
			operator_position--;
		}
	}
}

void	move_max_num_on_top(t_list **stack, int size)
{
	int     max_number;
	int     max_operator_position;
	int     node_number;
	t_list *aux = *stack;
	
	max_number = *(int *)(*stack)->content;
	max_operator_position = 0;
	node_number = 0;
	while (*stack)
	{
		if (*(int *)(*stack)->content > max_number)
		{
			max_number = *(int *)(*stack)->content;
			max_operator_position = node_number;
		}
		*stack = (*stack)->next;
		node_number++;
	}
	*stack = aux;
	move_max_num_on_top_rotation(stack, size, max_operator_position);
}
void	move_max_num_on_top_rotation(t_list **stack, int size, int max_operator_position)
{
	if (max_operator_position > size/2)
	{
		while (max_operator_position < size)
		{
			revrotate_a_or_b(stack, 'b');
			max_operator_position++;
		}
	}
	else
	{
		while (max_operator_position > 0)
		{
			rotate_a_or_b(stack, 'b');
			max_operator_position--;
		}
	}
}
