/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthien-h <cthien-h@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:05:32 by cthien-h          #+#    #+#             */
/*   Updated: 2022/01/27 16:37:08 by cthien-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*get_int(const char *nptr)
{
	long	result;
	int		sign;
	int		*nbr;

	sign = 1;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	result = 0;
	while (*nptr)
	{
		if (!ft_isdigit(*nptr))
			return (NULL);
		result = (result * 10) + (*nptr - 48);
		if ((sign && result > INT32_MAX) || (!sign && result < INT32_MIN))
			return (NULL);
		nptr++;
	}
	nbr = ft_calloc(1, sizeof(int));
	*nbr = result * sign;
	return (nbr);
}

static int	is_dup(t_list *lst, int nbr)
{
	while (lst)
	{
		if (nbr == *(int *)(lst->content))
			return (1);
		lst = lst->next;
	}
	return (0);
}

void	read_stack(t_pushswap *data, int argc, char **argv)
{
	int	i;
	int	*tmp;

	data->length = argc - 1;
	i = 1;
	while (i < argc)
	{
		tmp = get_int(argv[i]);
		if (!tmp)
			exit_error("Invalid number");
		if (is_dup(data->stack_a, *tmp))
			exit_error("Duplicated number");
		ft_lstadd_back(&data->stack_a, ft_lstnew(tmp));
		i++;
	}
}
