/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 19:33:48 by drestrep          #+#    #+#             */
/*   Updated: 2023/12/21 14:31:06 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

// # define REPEATED_NUMBERS () write(1, "Error: números repetidos\n", 25)

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../libft/libft.h"

//PRINTS LINKED LISTS
void	printLinkedList(t_list *head);

int		push_swap_atoi(const char *str);

int		max_num_on_top(t_list **stack, int size);
int 	max_or_min_number(int position, int size);
int     check_if_min_or_max(t_list **stack, int stack_a_number);

int		ft_strcmp(const char *str1, const char *str2);
void	ft_free(t_list **lst);
int		get_double_rotate(t_list *stack_a, t_list *stack_b, int operator_position, int stack_b_number_position, int total_operations);
int		get_max_number_position(t_list **stack_b);
int		get_middle_number_position(t_list **stack_b, int number);

int	get_smaller_number(t_list **stack, int number, int next_smaller_number);
int	get_smaller_number_position(t_list **stack, int number, int next_smaller_number, int next_smaller_number_position);
int	middle_number(t_list **stack, int number, int size);


//DOUBLE ROTATE
int		double_rotate(t_list **stack_a, t_list **stack_b, int operator_number, int operator_position, int min_or_max);
int		both_numbers_halfway_up(t_list **stack_a, t_list **stack_b, int operator_position, int stack_b_operator_position);
int		both_numbers_halfway_down(t_list **stack_a, t_list **stack_b, int operator_position, int stack_b_operator_position);
//int		check_double_rotate(t_list **stack_a, t_list **stack_b,
int		check_all_doubles (t_list *stack_a, t_list *stack_b, int number_position, int stack_b_number_position);
int		get_all_doubles_operations (t_list *stack_a, t_list *stack_b, int number_position, int stack_b_number_position, int total_operations);
int		ft_exception(t_list **stack_a, t_list **stack_b, int operator_number, int operator_position, char c);

//PUSH BACK ALL NUMBERS FROM STACK_B TO STACK_A
void	push_back(t_list **stack_a, t_list **stack_b);
void	push_a_checker(t_list **stack_a, t_list **stack_b);

//MOVE OPERATOR TO STACK_B
void	move_operator(t_list **stack_a, t_list **stack_b, int operator_number, int operator_position);

//MOVE MAXIMUM NUMBER ON TOP OF THE STACK
void	move_max_num_on_top(t_list **stack, int size);
void	move_max_num_on_top_rotation(t_list **stack, int size, int max_operator_position);

//MOVE NEXT SMALLER NUMBER ON TOP OF THE STACK
void	move_middle_number(t_list **stack_a, t_list **stack_b, int operator_number, int operator_position);

//ORDER STACK
void	order_stack(t_list **stack_a, int number_position);

// INITIALIZER
void initialize(t_list **stack_a, int argc, char *argv[]);

// ERROR CHECKER
void	error_checker(t_list **stack);
void	check_if_ordered(t_list **stack, int caller);
void	check_duplicate(t_list **parameters);
void	check_is_number(char **argv);
void	check_spaces(char *str);
void	check_one_argument(t_list **str);

// ALGORITHMS
void sort_small(t_list **stack_a, t_list **stack_b, int argc);
void sort_big(t_list **stack_a, t_list **stack_b);
void two_numbers(t_list **stack);
void three_numbers(t_list **stack_a);
void four_or_five_numbers(t_list **stack_a, t_list **stack_b, int size);

// OPERATIONS
t_list **find_smallest_number(t_list **stack_a, int size);
int		get_smallest_number(t_list **stack_a, int smallest_number);
int		get_smallest_number_position(t_list **stack_a);

//MOVEMENTS
void	swap_a(t_list **lst);
void	swap_b(t_list **lst);
void	swap(t_list **lst_a, t_list **lst_b);
void	push_a(t_list **lst_a, t_list **lst_b);
void	push_b(t_list **lst_a, t_list **lst_b);
void	rotate(t_list **lst_a, t_list **lst_b);
void	rotate_a_or_b(t_list **lst, char c);
void	revrotate_a_or_b(t_list **lst, char c);
void	revrotate(t_list **lst_a, t_list **lst_b);

#endif