/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_max_or_middle_nb_pos.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 06:49:19 by drestrep          #+#    #+#             */
/*   Updated: 2023/08/31 04:02:37 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_middle_number_position(t_list **stack_b, int number)
{
	int node_number;
	int next_smaller_number;
	int next_smaller_number_position;
	t_list  *aux;

	aux = *stack_b;
	node_number = 0;
	next_smaller_number = 0;
	next_smaller_number_position = 0;
	while (*stack_b)
	{
		if (next_smaller_number == 0 && *(int *)(*stack_b)->content < number)
		{
			next_smaller_number = *(int *)(*stack_b)->content;
			next_smaller_number_position = node_number;
		}
		if (*(int *)(*stack_b)->content < number && *(int *)(*stack_b)->content > next_smaller_number)
		{
			next_smaller_number = *(int *)(*stack_b)->content;
			next_smaller_number_position = node_number;
		}
		*stack_b = (*stack_b)->next;
		node_number++;
	}
	*stack_b = aux;
	return (next_smaller_number_position);
}

int	get_max_number_position(t_list **stack_b)
{
	t_list	*aux;
	int 	position;
	int		node_number;
	int		max_number;

	aux = *stack_b;
	position = 0;
	node_number = 0;
	max_number = *(int *)(*stack_b)->content;
	while (*stack_b)
	{
		if (*(int *)(*stack_b)->content > max_number)
		{
			max_number = *(int *)(*stack_b)->content;
			position = node_number;
		}
		*stack_b = (*stack_b)->next;
		node_number++;
	}
	*stack_b = aux;
	return (position);
}
