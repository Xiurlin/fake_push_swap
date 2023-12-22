/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_middle_number.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 06:43:59 by drestrep          #+#    #+#             */
/*   Updated: 2023/08/31 02:38:19 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_smaller_number(t_list **stack, int number, int next_smaller_number)
{
	t_list  *aux;

	aux = *stack;
	while (*stack)
	{
		if (next_smaller_number == 0 && *(int *)(*stack)->content < number)
			next_smaller_number = *(int *)(*stack)->content;
		if (*(int *)(*stack)->content < number && *(int *)(*stack)->content > next_smaller_number)
			next_smaller_number = *(int *)(*stack)->content;
		*stack = (*stack)->next;
	}
	*stack = aux;
	return (next_smaller_number);
}

int	get_smaller_number_position(t_list **stack, int number, int next_smaller_number, int next_smaller_number_position)
{
	int	node_number;
	t_list  *aux;

	node_number = 0;
	aux = *stack;
	while (*stack)
	{
		if (next_smaller_number == 0 && *(int *)(*stack)->content < number)
		{
			next_smaller_number = *(int *)(*stack)->content;
			next_smaller_number_position = node_number;
		}
		if (*(int *)(*stack)->content < number && *(int *)(*stack)->content > next_smaller_number)
		{
			next_smaller_number = *(int *)(*stack)->content;
			next_smaller_number_position = node_number;
		}
		*stack = (*stack)->next;
		node_number++;
	}
	*stack = aux;
	return (next_smaller_number_position);
}

int	middle_number(t_list **stack, int number, int size)
{
	int next_smaller_number_position;

	next_smaller_number_position = get_smaller_number_position(stack, number, 0, 0);
	if (next_smaller_number_position > size/2)
		next_smaller_number_position = size - next_smaller_number_position;
	return (next_smaller_number_position);
}
