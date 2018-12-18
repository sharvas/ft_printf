# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/08 14:34:39 by dfinnis           #+#    #+#              #
#    Updated: 2018/12/08 14:34:43 by dfinnis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c \
		parse_flags_width.c \
		parse_precision.c \
		parse_length.c \
		parse_type.c \
		read_numbers.c \
		read_floats.c \
		read_others.c \
		convert.c \
		build_precision.c \
		build_width.c \
		build_prefix.c \
		build_float.c \
		float_support.c

LIBO = libft/ft_isdigit.o \
		libft/ft_itoa_base.o \
		libft/ft_itoa_intmax.o \
		libft/ft_itoa_unsigned.o \
		libft/ft_putchar.o \
		libft/ft_putstr.o \
		libft/ft_strchr.o \
		libft/ft_strdup.o \
		libft/ft_strndup.o \
		libft/ft_strjoin.o \
		libft/ft_strlen.o \
		libft/ft_strcat.o \
		libft/ft_strcpy.o \
		libft/ft_strnew.o \
		libft/ft_bzero.o \
		libft/ft_memset.o \
		libft/ft_strjoinfree.o \
		libft/ft_strjoinfree_s1.o \
		libft/ft_strjoinfree_s2.o

OBJ = $(SRCS:.c=.o)

FLAGS = -Wall -Werror -Wextra

HEADER = -I libft/

INC = ft_printf.h

LIB = -L libft/ -lft

all: lib $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ) $(LIBO)
	@ranlib $(NAME)

$(OBJ): $(SRCS)
	@gcc -c $(FLAGS) $(SRCS) -I $(INC)

lib: 
	@make -C libft/ all

libfclean:
	@make -C libft/ fclean

libclean:
	@make -C libft/ clean

clean: libclean
	@/bin/rm -f $(OBJ)

fclean: clean libfclean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
