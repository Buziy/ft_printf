# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: busyigit <busyigit@student.42istanbul.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/20 10:47:23 by busyigit          #+#    #+#              #
#    Updated: 2026/02/23 15:35:31 by busyigit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = libftprintf.a
CC      = cc
CFLAGS  = -Wall -Wextra -Werror

SRC     = ft_printchar.c \
		  ft_printf.c \
		  ft_printhex.c \
		  ft_printhexlow.c \
		  ft_printhexup.c \
		  ft_printnbr.c \
		  ft_printstr.c \
		  ft_printunbr.c \
		  ft_strlen.c

OBJS    = $(SRC:.c=.o)

INCLUDE = ft_printf.h

all: $(NAME)

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re