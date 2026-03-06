/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busyigit <busyigit@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 23:32:47 by busyigit          #+#    #+#             */
/*   Updated: 2026/02/23 15:41:35 by busyigit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(const char *str)
{
	int	i;
	int	check;

	i = 0;
	if (str == NULL)
	{
		if ((write(1, "(null)", 6) == -1))
			return (-1);
		return (6);
	}
	while (str[i] != '\0')
	{
		check = ft_printchar(str[i]);
		if (check == -1)
			return (-1);
		i++;
	}
	return (i);
}
