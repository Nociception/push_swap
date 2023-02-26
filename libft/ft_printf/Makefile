# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nstoutze <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/29 14:06:38 by nstoutze          #+#    #+#              #
#    Updated: 2023/02/26 20:03:07 by nstoutze         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = libftprintf.a

SRC = ft_printf.c \
	  srcs/checkbase.c \
	  srcs/format_c.c \
	  srcs/format_di.c \
	  srcs/format_p.c \
	  srcs/format_s.c \
	  srcs/format_pc.c \
	  srcs/format_u.c \
	  srcs/format_xX.c \
	  srcs/pf_intlen.c \
	  srcs/pf_putchar.c \
	  srcs/pf_putnbr_base.c \
	  srcs/pf_putnbr_ptr.c \
	  srcs/pf_putstr.c \
	  srcs/pf_strlen.c \

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all
