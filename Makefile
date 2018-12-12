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
		main.c \
		parse.c \
		parse_2.c \

OBJ = $(SRCS:.c=.o)

FLAGS = -Wall -Werror -Wextra

HEADER = -I libft/

LIB = -L libft/ -lft

all: $(NAME)

$(NAME): lib
	gcc $(FLAGS) $(HEADER) -c $(SRCS) -g
	gcc $(OBJ) $(HEADER) $(LIB) -g -o $(NAME)

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
