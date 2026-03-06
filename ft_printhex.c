/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busyigit <busyigit@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 04:39:01 by busyigit          #+#    #+#             */
/*   Updated: 2026/02/23 16:27:40 by busyigit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexapointer(char *b, unsigned long long n, int c)
{
	unsigned long long	y;

	y = ft_strlen(b);
	if (n >= y)
	{
		c = ft_hexapointer(b, n / y, c);
		if (c == -1)
			return (-1);
		if (write(1, &b[n % y], 1) == -1)
			return (-1);
		c++;
	}
	else
	{
		if (write(1, &b[n], 1) == -1)
			return (-1);
		c++;
	}
	return (c);
}

int	ft_printhex(void *p)
{
	unsigned long long	pointer;
	int					i;

	i = 0;
	if (!p)
	{
		if (write(1, "(nil)", 5) != 5)
			return (-1);
		return (5);
	}
	pointer = (unsigned long long)p;
	if (write(1, "0x", 2) != 2)
		return (-1);
	i = ft_hexapointer("0123456789abcdef", pointer, i);
	if (i == -1)
		return (-1);
	i += 2;
	return (i);
}
