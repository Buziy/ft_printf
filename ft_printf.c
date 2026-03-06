/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busyigit <busyigit@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 18:33:55 by busyigit          #+#    #+#             */
/*   Updated: 2026/03/02 15:46:42 by busyigit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_type(char c, va_list format)
{
	if (c == 'c')
		return (ft_printchar(va_arg(format, int)));
	if (c == 's')
		return (ft_printstr(va_arg(format, char *)));
	if (c == 'p')
		return (ft_printhex(va_arg(format, void *)));
	if (c == 'd' || c == 'i')
		return (ft_printnbr(va_arg(format, int)));
	if (c == 'x')
		return (ft_printhexlow(va_arg(format, int)));
	if (c == 'X')
		return (ft_printhexupp(va_arg(format, int)));
	if (c == 'u')
		return (ft_printunbr(va_arg(format, unsigned int)));
	if (c == 'a')
		return(ft_printnbr(42));
	return (0);
}

static int	ft_percent(char c, va_list b)
{
	int	i;

	i = 0;
	if (c != '%')
	{
		i = ft_type(c, b);
		if (i == -1)
			return (-1);
		return (i);
	}
	else
	{
		if (write(1, &c, 1) != 1)
			return (-1);
		return (1);
	}
}

static int	ft_string(const char *str, va_list b, int n)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == '\0')
				return (-1);
			n = n + ft_percent(str[i + 1], b);
			if (n == -1)
				return (-1);
			i++;
		}
		else
		{
			if (write(1, &str[i], 1) != 1)
				return (-1);
			n++;
		}
		i++;
	}
	return (n);
}

int	ft_printf(const char *str, ...)
{
	va_list	b;
	int		n;

	if (!str)
		return (0);
	n = 0;
	va_start (b, str);
	n = ft_string(str, b, n);
	va_end(b);
	return (n);
}
