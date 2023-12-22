/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 07:02:48 by drestrep          #+#    #+#             */
/*   Updated: 2023/08/28 07:03:09 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	order_stack(t_list **stack_a, int operator_position)
{
	if (operator_position == -1)
	{
		operator_position = get_smallest_number_position(stack_a);
		order_stack(stack_a, operator_position);
		return ;
	}
	if (operator_position == ft_lstsize(*stack_a) - 1)
		revrotate_a_or_b(stack_a, 'a');
	else if (operator_position > ft_lstsize(*stack_a)/2)
	{
		while(operator_position < ft_lstsize(*stack_a))
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
