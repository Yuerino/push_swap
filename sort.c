/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthien-h <cthien-h@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 22:20:03 by cthien-h          #+#    #+#             */
/*   Updated: 2022/02/22 17:37:43 by cthien-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_stack(t_list *lst)
{
	printf("stack\n");
	while (lst)
	{
		printf("nbr %i and idx %i\n", ((t_nbr *)lst->content)->nbr,
			((t_nbr *)lst->content)->idx);
		lst = lst->next;
	}
}

static void	stack_push_bit(t_pushswap *data, int bit)
{
	int		i;
	t_list	*lst;

	lst = data->stack_a;
	i = 0;
	while (lst && i < data->length)
	{
		if (((((t_nbr *)lst->content)->nbr >> bit) & 1) == 1)
			stack_operation(data, OP_RA);
		else
			stack_operation(data, OP_PB);
		lst = data->stack_a;
		i++;
	}
}

static void	radix_binary_sort(t_pushswap *data)
{
	int		max_bits;
	int		bit;
	t_list	*lst;

	max_bits = 0;
	while ((data->length >> max_bits) != 0)
		max_bits++;
	bit = 0;
	while (bit < max_bits)
	{
		stack_push_bit(data, bit);
		lst = data->stack_b;
		while (lst)
		{
			stack_operation(data, OP_PA);
			lst = data->stack_b;
		}
		bit++;
	}
}

// TODO: add small sort base on length
void	stack_sort(t_pushswap *data)
{
	print_stack(data->stack_a);
	print_stack(data->stack_b);
	radix_binary_sort(data);
	print_stack(data->stack_a);
	print_stack(data->stack_b);
}
