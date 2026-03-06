/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busyigit <busyigit@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 18:26:01 by busyigit          #+#    #+#             */
/*   Updated: 2026/02/23 15:38:43 by busyigit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexupper(unsigned int n)
{
	int		count;
	char	*base;

	count = 0;
	base = "0123456789ABCDEF";
	if (n >= 16)
	{
		count = ft_hexupper(n / 16);
		if (count == -1)
			return (-1);
	}
	if (write(1, &base[n % 16], 1) == -1)
		return (-1);
	return (count + 1);
}

int	ft_printhexupp(int n)
{
	return (ft_hexupper((unsigned int)n));
}
