/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthien-h <cthien-h@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 22:20:03 by cthien-h          #+#    #+#             */
/*   Updated: 2022/01/27 22:56:53 by cthien-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// Get length of LIS
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

static int	stack_push_nonlis(t_pushswap *data, int lis_start)
{
	if (data->stack_a-content)
	while (data->stack_a)
}

void	stack_sort(t_pushswap *data)
{
	printf("%i\n", get_lis_start(data->stack_a));
}
