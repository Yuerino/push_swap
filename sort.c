/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthien-h <cthien-h@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 22:20:03 by cthien-h          #+#    #+#             */
/*   Updated: 2022/03/17 08:27:21 by cthien-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_push_bit(t_pushswap *data, int bit)
{
	int		i;
	t_list	*lst;

	lst = data->stack_a;
	i = 0;
	while (lst && i < data->length)
	{
		if (((((t_nbr *)lst->content)->idx >> bit) & 1) == 1)
			stack_operation(data, OP_RA, 1);
		else
			stack_operation(data, OP_PB, 1);
		lst = data->stack_a;
		i++;
	}
}

void	radix_binary_sort(t_pushswap *data)
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
			stack_operation(data, OP_PA, 1);
			lst = data->stack_b;
		}
		bit++;
	}
}

static void	sort_3(t_pushswap *data)
{
	if (((t_nbr *)data->stack_a->content)->idx == data->length - 1)
		stack_operation(data, OP_RA, 1);
	else if (((t_nbr *)ft_lstlast(data->stack_a)->content)->idx
		!= data->length - 1)
		stack_operation(data, OP_RRA, 1);
	if (((t_nbr *)data->stack_a->content)->nbr
		> ((t_nbr *)data->stack_a->next->content)->nbr)
		stack_operation(data, OP_SA, 1);
}

static void	rotate_smallest_to_top(t_pushswap *data)
{
	int		smallest_num_idx;
	int		idx_in_stack;
	t_list	*lst;

	smallest_num_idx = get_smallest_num_idx(data);
	lst = data->stack_a;
	idx_in_stack = 0;
	while (lst)
	{
		if (((t_nbr *)lst->content)->idx == smallest_num_idx)
			break ;
		idx_in_stack++;
		lst = lst->next;
	}
	while (((t_nbr *)data->stack_a->content)->idx != smallest_num_idx)
	{
		if (idx_in_stack > ft_lstsize(data->stack_a) / 2)
			stack_operation(data, OP_RRA, 1);
		else
			stack_operation(data, OP_RA, 1);
	}
}

void	small_sort(t_pushswap *data)
{
	while (ft_lstsize(data->stack_a) > 3)
	{
		rotate_smallest_to_top(data);
		stack_operation(data, OP_PB, 1);
	}
	if (ft_lstsize(data->stack_a) <= 3)
		sort_3(data);
	while (data->stack_b)
		stack_operation(data, OP_PA, 1);
}
