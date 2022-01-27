/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthien-h <cthien-h@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:57:54 by cthien-h          #+#    #+#             */
/*   Updated: 2022/01/27 16:37:59 by cthien-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_swap(t_list *stack_a, t_list *stack_b)
{
	t_list	*second;

	if (stack_a)
	{
		second = stack_a->next;
		ft_lstswap_content(stack_a, second);
	}
	if (stack_b)
	{
		second = stack_b->next;
		ft_lstswap_content(stack_b, second);
	}
}

void	stack_push(t_list **stack_first, t_list **stack_second)
{
	t_list	*tmp;

	tmp = (*stack_first)->next;
	(*stack_first)->next = *stack_second;
	*stack_second = *stack_first;
	*stack_first = tmp;
}

void	stack_rotate(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (stack_a)
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		tmp->next = NULL;
		ft_lstadd_back(stack_a, tmp);
	}
	if (stack_b)
	{
		tmp = *stack_b;
		*stack_b = (*stack_b)->next;
		tmp->next = NULL;
		ft_lstadd_back(stack_b, tmp);
	}
}

void	stack_rrotate(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (stack_a)
	{
		tmp = ft_lstlast(*stack_a);
		ft_lstsecondlast(*stack_a)->next = NULL;
		ft_lstadd_front(stack_a, tmp);
	}
	if (stack_b)
	{
		tmp = ft_lstlast(*stack_b);
		ft_lstsecondlast(*stack_b)->next = NULL;
		ft_lstadd_front(stack_a, tmp);
	}
}
