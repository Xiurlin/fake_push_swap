/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_smallest_number.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 04:00:13 by drestrep          #+#    #+#             */
/*   Updated: 2023/08/31 04:04:08 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_smallest_number_position(t_list **stack_a)
{
	t_list	*stack_a_first_nb;
	int		smallest_number;
	int		smallest_number_position;
	int		current_position;

	stack_a_first_nb = *stack_a;
	smallest_number = *(int *)(*stack_a)->content;
	current_position = 0;
	smallest_number_position = current_position;
	while (*stack_a)
	{
		if (*(int *)(*stack_a)->content < smallest_number)
		{
			smallest_number = *(int *)(*stack_a)->content;
			smallest_number_position = current_position;
		}
		current_position++;
		*stack_a = (*stack_a)->next;
	}
	*stack_a = stack_a_first_nb;
	return (smallest_number_position);
}

int	get_smallest_number(t_list **stack_a, int smallest_number)
{
	t_list *aux;

	aux = *stack_a;
	while (*stack_a)
	{
		if (*(int *)(*stack_a)->content < smallest_number)
			smallest_number = *(int *)(*stack_a)->content;
		*stack_a = (*stack_a)->next;
	}
	*stack_a = aux;
	return (smallest_number);
}

t_list	**find_smallest_number(t_list **stack_a, int size)
{
	int     smallest_number;
	int		smallest_number_position;

	smallest_number_position = 0;
	smallest_number = *(int *)(*stack_a)->content;
	smallest_number = get_smallest_number(stack_a, smallest_number);
	smallest_number_position = get_smallest_number_position(stack_a);
	if (smallest_number_position < size/2)
	{
		while (smallest_number_position > 0)
		{
			rotate_a_or_b(stack_a, 'a');
			smallest_number_position--;
		}
	}
	else
	{
		while (*(int *)(*stack_a)->content != smallest_number)
			revrotate_a_or_b(stack_a, 'a');
	}
	return(stack_a);
}