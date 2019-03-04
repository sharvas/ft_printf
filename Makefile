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

FLAGS = -Wall -Werror -Wextra -g

SRCS = ft_printf.c \
		initialize.c \
		parse_flags_width.c \
		parse_precision.c \
		parse_length.c \
		parse_type.c \
		read_numbers.c \
		read_floats.c \
		read_others.c \
		build_precision.c \
		build_width.c \
		build_prefix.c \
		build_float.c \
		error_protection.c \
		binary.c

LIBO = ft_isdigit.o \
		ft_itoa_base.o \
		ft_itoa_intmax.o \
		ft_itoa_unsigned.o \
		ft_putchar.o \
		ft_putstr.o \
		ft_strchr.o \
		ft_strdup.o \
		ft_strndup.o \
		ft_strjoin.o \
		ft_strlen.o \
		ft_strcat.o \
		ft_strcpy.o \
		ft_strnew.o \
		ft_bzero.o \
		ft_memset.o \
		ft_strjoinfree.o \
		ft_strjoinfree_s1.o \
		ft_strjoinfree_s2.o

SRCS_DIR = srcs/
LIBFT = libft/
OBJS_DIR = objs/
INC = includes/

HEADER = $(INC)ft_printf.h $(LIBFT)libft.h
SRCS_PATH = $(SRCS:%=$(SRCS_DIR)%)

OBJS = $(SRCS:%.c=%.o)
OBJS_PATH = $(addprefix $(OBJS_DIR), $(OBJS))
OBJS_LBFT = $(addprefix $(LIBFT), $(LIBO))

GREEN = "\033[0;32m"
RED = "\033[0;31m"
DEFAULT = "\033[0m"

all: lib $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS_PATH) $(OBJS_LBFT) $(HEADER)
	@echo "COMPILING:" $(GREEN) $(NAME) $(DEFAULT)
	ar rc $(NAME) $(OBJS_PATH) $(OBJS_LBFT)
	ranlib $(NAME)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(HEADER)
	@echo "Compiling:" $(GREEN) $< $(DEFAULT)
	gcc -c $(FLAGS) $< -o $@ -I $(INC)

lib: 
	@make -C $(LIBFT) all

libfclean:
	@make -C $(LIBFT) fclean

libclean:
	@make -C $(LIBFT) clean

clean: libclean
	@/bin/rm -rf $(OBJS_DIR)

fclean: clean libfclean
	@/bin/rm -rf $(NAME)

re: fclean all

.PHONY : all clean fclean re lib libclean libfclean
