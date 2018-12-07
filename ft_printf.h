/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 15:06:08 by dfinnis           #+#    #+#             */
/*   Updated: 2018/12/06 17:42:42 by svaskeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF

# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> //for testing

typedef struct		s_print
{
	unsigned int	printed;
	unsigned int	len;
	char		*form;
	char		type;
	int		hh;
	int		h;
	int		j;
	int		ll;
	int		l;
	int		L;
	int		z;
	int		sharp;
	int		zero;
	int		minus;
	int		plus;
	int		space;
	int		width;
	int		precision;
	int		sign;
}			t_print;

//t_print		ft_parse(char const *format, t_list all);
//t_print			ft_init(t_print all);

t_print			ft_print(t_print all, va_list ap);
t_print			ft_modify_int(t_print all, va_list ap);
t_print			ft_int(t_print all, va_list ap);

#endif
