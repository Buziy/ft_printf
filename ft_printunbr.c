/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busyigit <busyigit@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 15:27:12 by busyigit          #+#    #+#             */
/*   Updated: 2026/02/23 15:42:05 by busyigit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_printunbr(unsigned int nbr)
{
	int	i;

	i = 0;
	if (nbr > 9)
	{
		i = ft_printunbr(nbr / 10);
		if (i == -1)
			return (-1);
		nbr = nbr % 10;
	}
	if (nbr <= 9)
	{
		if (ft_printchar(('0' + nbr)) == -1)
			return (-1);
		i++;
	}
	return (i);
}
