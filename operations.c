/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthien-h <cthien-h@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:57:54 by cthien-h          #+#    #+#             */
/*   Updated: 2022/01/28 11:24:21 by cthien-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_swap(t_list *stack)
{
	t_list	*second;

	if (stack)
	{
		second = stack->next;
		if (second)
			ft_lstswap_content(stack, second);
	}
}

static void	stack_push(t_list **stack_from, t_list **stack_to)
{
	t_list	*tmp;

	if (stack_from)
	{
		tmp = (*stack_from)->next;
		(*stack_from)->next = *stack_to;
		*stack_to = *stack_from;
		*stack_from = tmp;
	}
}

static void	stack_rotate(t_list **stack)
{
	t_list	*tmp;

	if (stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		tmp->next = NULL;
		ft_lstadd_back(stack, tmp);
	}
}

// TODO: odd case check empty second last + only 1 ele
static void	stack_rrotate(t_list **stack)
{
	t_list	*tmp;

	if (stack)
	{
		tmp = ft_lstlast(*stack);
		ft_lstsecondlast(*stack)->next = NULL;
		ft_lstadd_front(stack, tmp);
	}
}

void	stack_operation(t_pushswap *data, char *operation)
{
	if (!ft_strncmp(operation, OP_SA, ft_strlen(OP_SA))
		|| !ft_strncmp(operation, OP_SS, ft_strlen(OP_SS)))
		stack_swap(data->stack_a);
	if (!ft_strncmp(operation, OP_SB, ft_strlen(OP_SB))
		|| !ft_strncmp(operation, OP_SS, ft_strlen(OP_SS)))
		stack_swap(data->stack_b);
	if (!ft_strncmp(operation, OP_PA, ft_strlen(OP_PA)))
		stack_push(&data->stack_b, &data->stack_a);
	else if (ft_strncmp(operation, OP_PB, ft_strlen(OP_PB)))
		stack_push(&data->stack_a, &data->stack_b);
	if (!ft_strncmp(operation, OP_RA, ft_strlen(OP_RA))
		|| !ft_strncmp(operation, OP_RR, ft_strlen(OP_RR)))
		stack_rotate(&data->stack_a);
	if (!ft_strncmp(operation, OP_RB, ft_strlen(OP_RB))
		|| !ft_strncmp(operation, OP_RR, ft_strlen(OP_RR)))
		stack_rotate(&data->stack_b);
	if (!ft_strncmp(operation, OP_RRA, ft_strlen(OP_RRA))
		|| !ft_strncmp(operation, OP_RRR, ft_strlen(OP_RRR)))
		stack_rrotate(&data->stack_a);
	if (!ft_strncmp(operation, OP_RRB, ft_strlen(OP_RRB))
		|| !ft_strncmp(operation, OP_RRR, ft_strlen(OP_RRR)))
		stack_rrotate(&data->stack_b);
	ft_putendl_fd(operation, STDOUT_FILENO);
}
