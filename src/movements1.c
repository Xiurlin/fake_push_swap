/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 10:58:47 by drestrep          #+#    #+#             */
/*   Updated: 2023/08/28 04:28:13 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap_a(t_list **lst)
{
	t_list  *aux;
	
	if (!lst || !(*lst) || !(*lst)->next)
		return ;
	aux = (*lst)->next;
	(*lst)->next = aux->next;
	aux->next = (*lst);
	(*lst) = aux;
	write(1, "sa\n", 3);
}

void	swap_b(t_list **lst)
{
	t_list  *aux;
	
	if (!lst || !(*lst) || !(*lst)->next)
		return ;
	aux = (*lst)->next;
	(*lst)->next = aux->next;
	aux->next = (*lst);
	(*lst) = aux;
	write(1, "sb\n", 3);
}

void	swap(t_list **lst_a, t_list **lst_b)
{
	if (!lst_a || !(*lst_a) || !(*lst_a)->next || !(*lst_a)->next->next ||
		!lst_b || !(*lst_b) || !(*lst_b)->next || !(*lst_b)->next->next)
		return ;
	swap_a(lst_a);
	swap_b(lst_b);
	write(1, "ss\n", 3);
}

void	push_a(t_list **lst_a, t_list **lst_b)
{
	t_list  *aux;
	
	if (!(*lst_b))
		return ;
	aux = (*lst_b);
	(*lst_b) = (*lst_b)->next;
	aux->next = (*lst_a);
	(*lst_a) = aux;
	write(1, "pa\n", 3);
}

void	push_b(t_list **lst_a, t_list **lst_b)
{
	t_list  *aux;

	aux = (*lst_a);
	(*lst_a) = (*lst_a)->next;
	aux->next = (*lst_b);
	(*lst_b) = aux;
	write(1, "pb\n", 3);
}
