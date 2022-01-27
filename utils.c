/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthien-h <cthien-h@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:55:51 by cthien-h          #+#    #+#             */
/*   Updated: 2022/01/27 16:44:49 by cthien-h         ###   ########.fr       */
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

t_list	*ft_lstsecondlast(t_list *lst)
{
	while (lst && lst->next && !lst->next->next)
	{
		lst = lst->next;
	}
	return (lst);
}

void	exit_error(char *err)
{
	ft_putendl_fd(err, 2);
	exit(EXIT_FAILURE);
}
