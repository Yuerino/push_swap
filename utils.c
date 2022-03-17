/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthien-h <cthien-h@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:55:51 by cthien-h          #+#    #+#             */
/*   Updated: 2022/03/17 08:26:15 by cthien-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstswap_content(t_list *a, t_list *b)
{
	void	*content;

	content = a->content;
	a->content = b->content;
	b->content = content;
}

void	exit_error(char *err)
{
	ft_putendl_fd(err, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

int	is_sorted(t_list *lst)
{
	while (lst)
	{
		if (lst->next && ((t_nbr *)lst->content)->idx
			!= ((t_nbr *)lst->next->content)->idx - 1)
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	free_stack(t_pushswap *data)
{
	ft_lstclear(&(data->stack_a), free);
	ft_lstclear(&(data->stack_b), free);
}

int	get_smallest_num_idx(t_pushswap *data)
{
	int		smallest_num_idx;
	t_list	*lst;

	smallest_num_idx = data->length - 1;
	lst = data->stack_a;
	while (lst)
	{
		if (((t_nbr *)lst->content)->idx < smallest_num_idx)
			smallest_num_idx = ((t_nbr *)lst->content)->idx;
		lst = lst->next;
	}
	return (smallest_num_idx);
}
