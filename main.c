/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthien-h <cthien-h@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 22:03:21 by cthien-h          #+#    #+#             */
/*   Updated: 2022/02/04 14:45:13 by cthien-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_pushswap	data;

	if (argc < 3)
		exit_error("Enter at least 2 numbers");
	data.stack_a = NULL;
	data.stack_b = NULL;
	read_stack(&data, argc, argv);
	stack_sort(&data);
	return (EXIT_SUCCESS);
}
