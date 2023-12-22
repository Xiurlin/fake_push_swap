/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_or_max.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 07:01:30 by drestrep          #+#    #+#             */
/*   Updated: 2023/08/28 07:01:54 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_if_min_or_max(t_list **stack, int stack_a_number)
{
	int     stack_b_max;
	int     stack_b_min;
	t_list  *aux;

	stack_b_min = *(int *)(*stack)->content;
	stack_b_max = *(int *)(*stack)->content;
	aux = *stack;
	while (*stack)
	{
		if (*(int *)(*stack)->content > stack_b_max)
			stack_b_max = *(int *)(*stack)->content;
		if (*(int *)(*stack)->content < stack_b_min)
			stack_b_min = *(int *)(*stack)->content;
		*stack = (*stack)->next;
	}
	*stack = aux;
	if (stack_a_number < stack_b_min || stack_a_number > stack_b_max)
		return(0);
	return(1);
}

int	max_or_min_number(int position, int size)
{
	int operations;

	if (position > size/2)
		operations = size - position;
	else
		operations = position;
	return(operations);
}