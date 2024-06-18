# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/12 11:03:26 by nstoutze          #+#    #+#              #
#    Updated: 2024/06/18 01:57:10 by nstoutze         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = libft.a

SRC = ft_atoi.c \
	  ft_bzero.c \
	  ft_isalnum.c \
	  ft_isalpha.c \
	  ft_isascii.c \
	  ft_isdigit.c \
	  ft_isprint.c \
	  ft_memcpy.c \
	  ft_memset.c \
	  ft_strchr.c \
	  ft_strlen.c \
	  ft_substr.c \
	  ft_split.c \
	  ft_strncmp.c \
	  ft_calloc.c \
	  ft_memmove.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_toupper.c \
	  ft_tolower.c \
	  ft_strdup.c \
	  ft_strrchr.c \
	  ft_strnstr.c \
	  ft_strlcpy.c \
	  ft_strlcat.c \
	  ft_itoa.c \
	  ft_strtrim.c \
	  ft_strjoin.c \
	  ft_striteri.c \
	  ft_putchar_fd.c \
	  ft_putstr_fd.c \
	  ft_putnbr_fd.c \
	  ft_putendl_fd.c \
	  ft_strmapi.c \
	  get_next_line.c \
	  get_next_line_utils.c \
	  ft_printf/ft_printf.c \
	  ft_printf/srcs/format_c.c \
	  ft_printf/srcs/format_di.c \
	  ft_printf/srcs/format_p.c \
	  ft_printf/srcs/format_pc.c \
	  ft_printf/srcs/format_s.c \
	  ft_printf/srcs/format_u.c \
	  ft_printf/srcs/format_xX.c \
	  ft_printf/srcs/ft_intlen.c \
	  ft_printf/srcs/ft_putnbr_ptr.c \
	  ft_printf/srcs/checkbase.c \
	  ft_printf/srcs/ft_putnbr_base.c \

SRC_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

ifndef WITH_BONUS
OBJ_LIST = $(OBJ)
else
OBJ_LIST = $(OBJ) $(OBJ_BONUS)
endif

CFLAGS = #-Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ_LIST)
	ar rc $(NAME) $(OBJ_LIST)
	@printf "compiling : $<                        \r"

bonus :	
	@make WITH_BONUS=1 all

clean :
	rm -rf $(OBJ)
	rm -rf $(OBJ_BONUS)

fclean : clean
	rm -rf $(NAME)

re : fclean all
