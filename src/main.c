/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 19:33:56 by drestrep          #+#    #+#             */
/*   Updated: 2023/08/31 02:37:22 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

void	ft_free(t_list **lst)
{
	t_list	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		(*lst)->content = 0;
		free(*lst);
		*lst = tmp;
	}
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc <= 1)
		return(1);
	
	stack_a	= NULL;
	stack_b = NULL;
	initialize(&stack_a, argc, argv);
	argc = ft_lstsize(stack_a);
	error_checker(&stack_a);
	if (argc <= 5)
		sort_small(&stack_a, &stack_b, argc);
	else
		sort_big(&stack_a, &stack_b);	
	return (0);
}
