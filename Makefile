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

SRCS = convert.c \
		float.c \
		ft_printf.c \
		parse.c \
		parse_2.c \
		string.c \
		numbers.c \
		float_types.c \
		build_str.c

LIBO = libft/ft_isdigit.o \
		libft/ft_itoa_base.o \
		libft/ft_itoa_mod.o \
		libft/ft_itoa_unsigned.o \
		libft/ft_putchar.o \
		libft/ft_putstr.o \
		libft/ft_strchr.o \
		libft/ft_strdup.o \
		libft/ft_strjoin.o \
		libft/ft_strlen.o \
		libft/ft_strcat.o \
		libft/ft_strcpy.o \
		libft/ft_strnew.o \
		libft/ft_bzero.o \
		libft/ft_memset.o

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

##$(NAME): lib
##	gcc $(FLAGS) $(HEADER) -c $(SRCS) -g
##	gcc $(OBJ) $(HEADER) $(LIB) -g -o $(NAME)

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
