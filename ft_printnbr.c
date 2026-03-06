/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busyigit <busyigit@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 04:15:18 by busyigit          #+#    #+#             */
/*   Updated: 2026/02/23 15:39:50 by busyigit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_handle_min(void)
{
	if (write(1, "-2147483648", 11) != 11)
		return (-1);
	return (11);
}

int	ft_printnbr(int n)
{
	int	i;
	int	res;

	i = 0;
	if (n == -2147483648)
		return (ft_handle_min());
	if (n < 0)
	{
		if (write(1, "-", 1) != 1)
			return (-1);
		n = -n;
		i++;
	}
	if (n > 9)
	{
		res = ft_printnbr(n / 10);
		if (res == -1)
			return (-1);
		i += res;
	}
	if (ft_printchar(('0' + (n % 10))) == -1)
		return (-1);
	return (i + 1);
}
