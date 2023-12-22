/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 02:26:13 by drestrep          #+#    #+#             */
/*   Updated: 2023/08/28 04:29:07 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	check_is_number(char **argv)
{
	int     i;
	int     j;
	char    *str;

	i = 1;
	j = 0;
	while ((argv[i]))
	{
		str = malloc(sizeof(char));
		str = argv[i];
		while (str[j])
		{
			if (ft_isdigit(str[j]) && !ft_isdigit(str[j + 1]) && str[j + 1] != '\0' && str[j + 1] != ' ')
			{
				write(1, "All arguments must be numbers\n", 30);
				exit(1);
			}
			if (!ft_isdigit(str[j]) && str[j] != ' ')
			{
				if (str[j] == '+' || str[j] == '-' )
				{
					if (!ft_isdigit(str[j +1]))
					{
						write(1,"All arguments must be numbers\n", 30);
						exit(1);
					}
				}
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	check_one_argument(t_list **str)
{
	if (ft_lstsize(*str) == 1)
	{
		write(1, "There's only one argument\n", 26);
		exit(1);
	}
}

void	check_spaces(char *str)
{
	int counter;
	
	counter = 0;
	while (str[counter] == ' ')
	{
		counter++;
		if (str[counter] == '\0')
		{
			write(1, "A space can't be an argument\n", 29);
			exit(1);
		}
	}
}

void	check_if_ordered(t_list **stack, int caller)
{
	t_list  *first_number;
	t_list  *next_number;

	first_number = (*stack);
	next_number = (*stack)->next;
	while(*(int *)(*stack)->content < *(int *)next_number->content)
	{
		if (next_number->next == NULL)
		{
			if (caller == 1)
			{
				write(1, "Stack is already ordered\n", 25);
				exit(1);
			}
			return ;
		}
		(*stack) = (*stack)->next;
		next_number = next_number->next;
	}
	(*stack) = first_number;
}

void	check_duplicate(t_list **parameters)
{
	t_list  *current;
	t_list  *runner;
	current = (*parameters);
	while (current != NULL)
	{
		runner = current->next;
		while (runner != NULL)
		{
			if (*(int *)current->content == *(int *)runner->content)
			{
				write(1, "There must be no duplicate numbers\n", 35);
				exit(1);
			}
			runner = runner->next;
		}
		current = current->next;
	}
	return ;
}

void	error_checker(t_list **stack)
{
	size_t  i;

	i = 1;
	if (!stack)
		return ;
	check_duplicate(stack);
	check_if_ordered(stack, i);
}