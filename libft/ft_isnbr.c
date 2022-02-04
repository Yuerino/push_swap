/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthien-h <cthien-h@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 13:42:09 by cthien-h          #+#    #+#             */
/*   Updated: 2022/02/04 13:45:01 by cthien-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isnbr(char *nptr)
{
	if (*nptr == '+' || *nptr == '-')
		nptr++;
	if (!*nptr)
		return (0);
	while (*nptr)
	{
		if (!ft_isdigit(*nptr))
			return (0);
		nptr++;
	}
	return (1);
}
