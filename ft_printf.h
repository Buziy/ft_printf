/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busyigit <busyigit@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 23:31:52 by busyigit          #+#    #+#             */
/*   Updated: 2026/02/23 15:44:21 by busyigit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int				ft_printchar(int c);
int				ft_printstr(const char *str);
int				ft_printnbr(int n);
int				ft_printhex(void *p);
unsigned int	ft_printunbr(unsigned int nbr);
int				ft_printhexlow(int n);
int				ft_printhexupp(int n);
int				ft_printf(const char *str, ...);
int				ft_strlen(char *s);

#endif