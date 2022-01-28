/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthien-h <cthien-h@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 22:01:05 by cthien-h          #+#    #+#             */
/*   Updated: 2022/01/28 10:25:12 by cthien-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

# include "libft.h"

// Operations macros

# define OP_SA "sa"
# define OP_SB "sb"
# define OP_SS "ss"
# define OP_PA "pa"
# define OP_PB "pb"
# define OP_RB "rb"
# define OP_RA "ra"
# define OP_RR "rr"
# define OP_RRA "rra"
# define OP_RRB "rrb"
# define OP_RRR "rrr"

typedef struct s_pushswap
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		length;
}	t_pushswap;

void	read_stack(t_pushswap *data, int argc, char **argv);
void	stack_sort(t_pushswap *data);
void	stack_operation(t_pushswap *data, char *operation);

t_list	*ft_lstsecondlast(t_list *lst);
void	ft_lstswap_content(t_list *a, t_list *b);
void	exit_error(char *err);

#endif
