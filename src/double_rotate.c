/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 06:59:36 by drestrep          #+#    #+#             */
/*   Updated: 2023/08/28 07:15:28 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	both_numbers_halfway_up(t_list **stack_a, t_list **stack_b, int operator_position, int stack_b_operator_position)
{
	while (operator_position < ft_lstsize(*stack_a) && stack_b_operator_position < ft_lstsize(*stack_b))
	{
		revrotate(stack_a, stack_b);
		operator_position++;
		stack_b_operator_position++;
	}
	return (operator_position);
}

int	both_numbers_halfway_down(t_list **stack_a, t_list **stack_b, int operator_position, int stack_b_operator_position)
{
	while (operator_position > 0 && stack_b_operator_position > 0)
	{
		rotate(stack_a, stack_b);
		operator_position--;
		stack_b_operator_position--;
	}
	return (operator_position);
}

int	double_rotate(t_list **stack_a, t_list **stack_b, int operator_number, int operator_position, int min_or_max)
{
	int		stack_b_operator_position;

	if (min_or_max == 0)
		stack_b_operator_position = get_max_number_position(stack_b);
	else if (min_or_max == 1)
		stack_b_operator_position = get_middle_number_position(stack_b, operator_number);
	if (operator_position > ft_lstsize(*stack_a) / 2 && stack_b_operator_position > ft_lstsize(*stack_b)/2)
		operator_position = both_numbers_halfway_up(stack_a, stack_b, operator_position, stack_b_operator_position);
	else if (operator_position <= ft_lstsize(*stack_a) / 2 && stack_b_operator_position <= ft_lstsize(*stack_b)/2)
		operator_position = both_numbers_halfway_down(stack_a, stack_b, operator_position, stack_b_operator_position);
	return (operator_position);
}
