# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psafflow <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/08 11:43:55 by psafflow          #+#    #+#              #
#    Updated: 2020/07/17 11:44:03 by psafflow         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

INCS	= ./include/ft_printf.h

SRCDIR	= ./src/
SRC		= ft_printf.c print_char.c print_string.c print_pointer.c\
		print_decimal_integer.c print_unsigned_int.c print_hexadecimal.c\
		print_percentage.c search_spec_format.c
SRCS	= $(addprefix $(SRCDIR), $(SRC))

UTLDIR	= ./utils/
UTL		= ft_putchar.c ft_putstr.c ft_strlen.c ft_calloc.c ft_strnbr.c\
		  ft_bzero.c ft_strnew.c ft_strcmp.c ft_strcpy.c ft_strncpy.c\
		  ft_putnchar.c ft_nbrlen.c ft_putnbr.c ft_putui.c ft_puthex.c
UTLS	= $(addprefix $(UTLDIR), $(UTL))

OBJS	= $(SRCS:.c=.o) $(UTLS:.c=.o)

GCCFLAG	= -Wall -Wextra -Werror

all: $(NAME)

$(NAME):$(OBJS)
	ar -rcs $@ $^
	
.c.o:		
	gcc $(GCCFLAG) -c $< -o $(<:.c=.o) -include $(INCS)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
