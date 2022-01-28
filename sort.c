/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthien-h <cthien-h@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 22:20:03 by cthien-h          #+#    #+#             */
/*   Updated: 2022/01/28 12:16:01 by cthien-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// Get length of LIS
// TODO: wrong bro
static int	get_lis_length(t_list *lst)
{
	int	max;
	int	length;

	max = *(int *)lst->content;
	length = 1;
	while (lst)
	{
		if (*(int *)lst->content > max)
		{
			max = *(int *)lst->content;
			length++;
		}
		lst = lst->next;
	}
	return (length);
}

// Get LIS start number
// TODO: wrong bro
static int	get_lis_start(t_list *lst)
{
	int	start;
	int	tmp;
	int	length;

	start = *(int *)lst->content;
	tmp = 1;
	while (lst)
	{
		length = get_lis_length(lst);
		if (length > tmp)
		{
			tmp = length;
			start = *(int *)lst->content;
		}
		lst = lst->next;
	}
	return (start);
}

// Push all non LIS number to stack B
static void	stack_push_nonlis(t_pushswap *data, int lis_start)
{
	t_list	*stack_a;
	int		i;

	i = 0;
	stack_a = data->stack_a;
	while (stack_a && i < data->length)
	{
		if (*(int *)stack_a->content >= lis_start)
		{
			lis_start = *(int *)stack_a->content;
			stack_operation(data, OP_RA);
		}
		else
		{
			stack_operation(data, OP_PB);
		}
		stack_a = data->stack_a;
		i++;
	}
}

void	print_stack(t_list *lst)
{
	printf("stack\n");
	while (lst)
	{
		printf("%i\n", *(int *)lst->content);
		lst = lst->next;
	}
}

void	stack_sort(t_pushswap *data)
{
	print_stack(data->stack_a);
	print_stack(data->stack_b);
	stack_push_nonlis(data, get_lis_start(data->stack_a));
	print_stack(data->stack_a);
	print_stack(data->stack_b);
}
