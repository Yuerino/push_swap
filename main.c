/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthien-h <cthien-h@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 22:03:21 by cthien-h          #+#    #+#             */
/*   Updated: 2022/01/26 22:16:09 by cthien-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// implement ft_lstswap(t_list *a, t_list *b);
void	stack_swap(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*second;

	if (stack_a)
	{
		second = stack_a->stack->next;
		ft_lstswap(stack_a->stack, second);
	}
	if (stack_b)
	{
		second = stack_b->stack->next;
		ft_lstswap(stack_b->stack, second);
	}
}

void	stack_push(t_stack *stack_first, t_stack *stack_second)
{

}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	return (EXIT_SUCCESS);
}
