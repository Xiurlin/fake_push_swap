/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_operator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 07:03:36 by drestrep          #+#    #+#             */
/*   Updated: 2023/12/21 14:31:31 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	move_operator(t_list **stack_a, t_list **stack_b, int operator_number, int operator_position)
{
	int	min_or_max;
	
	min_or_max = check_if_min_or_max(stack_b, operator_number);
	if (min_or_max == 0)
	{
		operator_position = double_rotate(stack_a, stack_b, operator_number, operator_position, min_or_max);
		move_max_num_on_top(stack_b, ft_lstsize(*stack_b));
		push_b(stack_a, stack_b);
		return ;
	}
	else
	{
		operator_position = double_rotate(stack_a, stack_b, operator_number, operator_position, min_or_max);
		move_middle_number(stack_a, stack_b, operator_number, operator_position);
		push_b(stack_a, stack_b);
		return ;
	}
}
