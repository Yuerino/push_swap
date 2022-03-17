/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthien-h <cthien-h@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:05:32 by cthien-h          #+#    #+#             */
/*   Updated: 2022/03/17 09:01:55 by cthien-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_dup(t_list *lst, int nbr)
{
	while (lst)
	{
		if (nbr == ((t_nbr *)lst->content)->nbr)
			return (1);
		lst = lst->next;
	}
	return (0);
}

static void	index_stack(t_pushswap *data)
{
	int		i;
	int		min;
	t_list	*min_lst;
	t_list	*lst;

	i = 0;
	while (i < data->length)
	{
		min = INT32_MAX;
		min_lst = NULL;
		lst = data->stack_a;
		while (lst)
		{
			if (min >= ((t_nbr *)lst->content)->nbr
				&& ((t_nbr *)lst->content)->idx < 0)
			{
				min = ((t_nbr *)lst->content)->nbr;
				min_lst = lst;
			}
			lst = lst->next;
		}
		((t_nbr *)min_lst->content)->idx = i;
		i++;
	}
}

void	read_stack(t_pushswap *data, int argc, char **argv)
{
	int			i;
	long long	tmp;
	t_nbr		*nbr;

	data->length = argc - 1;
	i = 1;
	while (i < argc)
	{
		if (!ft_isnbr(argv[i]))
			exit_error("Error");
		tmp = ft_atoll(argv[i]);
		if (tmp > INT32_MAX || tmp < INT32_MIN)
			exit_error("Error");
		if (is_dup(data->stack_a, tmp))
			exit_error("Error");
		nbr = ft_calloc(1, sizeof(t_nbr));
		if (!nbr)
			exit_error("Error");
		nbr->nbr = tmp;
		nbr->idx = -1;
		ft_lstadd_back(&data->stack_a, ft_lstnew(nbr));
		i++;
	}
	index_stack(data);
}
