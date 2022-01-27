/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthien-h <cthien-h@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 22:01:05 by cthien-h          #+#    #+#             */
/*   Updated: 2022/01/27 16:38:10 by cthien-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

# include "libft.h"

typedef struct s_pushswap
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		length;
}	t_pushswap;

void	read_stack(t_pushswap *data, int argc, char **argv);

void	stack_swap(t_list *stack_a, t_list *stack_b);
void	stack_push(t_list **stack_first, t_list **stack_second);
void	stack_rotate(t_list **stack_a, t_list **stack_b);
void	stack_rrotate(t_list **stack_a, t_list **stack_b);

t_list	*ft_lstsecondlast(t_list *lst);
void	ft_lstswap_content(t_list *a, t_list *b);
void	exit_error(char *err);

#endif
