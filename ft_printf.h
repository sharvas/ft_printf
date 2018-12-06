/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 15:06:08 by dfinnis           #+#    #+#             */
/*   Updated: 2018/12/06 10:31:33 by svaskeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF

# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> //for testing

typedef struct		s_print_list
{
	unsigned int	count;
	unsigned int	len;
	char			*flags;
	char			type;
	int				hh;
	int				h;
	int				ll;
	int				l;
	int				L;
	int				sharp;
	int				zero;
	int				minus;
	int				plus;
	int				space;
	int				width;
	int				precision;
}					t_print_list;

//t_list			ft_parse(char const *format, t_list all);
t_print_list		ft_init(t_print_list all);

t_print_list		ft_convert(t_print_list all, va_list ap);
t_print_list		ft_modify_integer(int num, t_print_list all);
t_print_list		ft_integer(t_print_list all, va_list ap);

#endif
