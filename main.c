/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthien-h <cthien-h@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 22:03:21 by cthien-h          #+#    #+#             */
/*   Updated: 2022/03/17 08:07:19 by cthien-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_pushswap	data;

	if (argc <= 2)
		return (EXIT_SUCCESS);
	data.stack_a = NULL;
	data.stack_b = NULL;
	read_stack(&data, argc, argv);
	if (is_sorted(data.stack_a))
		return (EXIT_SUCCESS);
	if (data.length <= 5)
		small_sort(&data);
	else
		radix_binary_sort(&data);
	free_stack(&data);
	return (EXIT_SUCCESS);
}
