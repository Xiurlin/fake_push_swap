/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 06:46:20 by drestrep          #+#    #+#             */
/*   Updated: 2023/08/31 04:05:11 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_a_checker(t_list **stack_a, t_list **stack_b)
{
	t_list	*stack_a_first_nb;
	int		next_bigger_number;
	int		next_bigger_number_position;
	int		current_position;

	stack_a_first_nb = *stack_a;
	next_bigger_number_position = -1;
	current_position = 0;
	while (*stack_a)
	{
		if (next_bigger_number_position == -1 && *(int *)(*stack_a)->content > *(int *)(*stack_b)->content)
		{
			next_bigger_number = *(int *)(*stack_a)->content;
			next_bigger_number_position = current_position;
		}
		if (*(int *)(*stack_a)->content > *(int *)(*stack_b)->content && *(int *)(*stack_a)->content < next_bigger_number)
		{
			next_bigger_number = *(int *)(*stack_a)->content;
			next_bigger_number_position = current_position;
		}
		*stack_a = (*stack_a)->next;
		current_position++;
	}
	*stack_a = stack_a_first_nb;
	order_stack(stack_a, next_bigger_number_position);
}

void	push_back(t_list **stack_a, t_list **stack_b)
{
	int		smallest_number_position;

	three_numbers(stack_a);
	while (*stack_b)
	{
		push_a_checker(stack_a, stack_b);
		push_a(stack_a, stack_b);
	}
	smallest_number_position = get_smallest_number_position(stack_a);
	order_stack(stack_a, smallest_number_position);
}
