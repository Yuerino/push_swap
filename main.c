/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthien-h <cthien-h@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 22:03:21 by cthien-h          #+#    #+#             */
/*   Updated: 2022/01/27 16:54:12 by cthien-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	print_stack(t_list *lst)
{
	while (lst)
	{
		printf("%i\n", *(int *)lst->content);
		lst = lst->next;
	}
}

int	main(int argc, char **argv)
{
	t_pushswap	data;

	if (argc < 3)
		exit_error("Enter at least 2 numbers");
	data.stack_a = NULL;
	data.stack_b = NULL;
	read_stack(&data, argc, argv);
	print_stack(data.stack_a);
	printf("\n");
	print_stack(data.stack_b);
	// stack_swap(data.stack_a, NULL);
	stack_push(&data.stack_a, &data.stack_b);
	stack_push(&data.stack_a, &data.stack_b);
	stack_rotate(&data.stack_b, NULL);
	stack_push(&data.stack_b, &data.stack_a);
	stack_push(&data.stack_b, &data.stack_a);
	printf("\nnew\n");
	print_stack(data.stack_a);
	printf("\n");
	print_stack(data.stack_b);
	return (EXIT_SUCCESS);
}
