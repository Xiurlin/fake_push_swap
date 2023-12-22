/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_stacks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 23:36:27 by drestrep          #+#    #+#             */
/*   Updated: 2023/08/28 07:09:53 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	initialize(t_list **stack_a, int argc, char *argv[])
{
	int 	i;
	int		j;
	int		*nb;
	char	**aux;

	i = 1;
	j = 0;
	*stack_a = NULL;
	check_is_number(argv);
	while (i < argc)
	{
		check_spaces(argv[i]);
		if (ft_strchr(argv[i], ' '))
			aux = ft_split(argv[i], ' ');
		else
		{
			aux = malloc(sizeof(char *));
			*aux = argv[i];
		}
		while (aux[j])
		{
			nb = malloc(sizeof(int));
			*nb = push_swap_atoi(aux[j]);
			if (j == 0 && i == 1) 
				*stack_a = ft_lstnew(nb);
			else
				ft_lstadd_back(stack_a, ft_lstnew(nb));
			j++;
		}
		j = 0;
		i++;
	}
}

int	push_swap_atoi(const char *str)
{
	int	res;
	int	sgn;
	int	i;

	res = 0;
	sgn = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i] == '-')
			sgn *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (sgn * res);
}
