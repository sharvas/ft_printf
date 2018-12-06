/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaskeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 18:51:39 by svaskeli          #+#    #+#             */
/*   Updated: 2018/12/06 15:55:58 by svaskeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_fill_width(int len, t_print all, char c)
{
	int i;

	i = 0;
	if (len < all.width)
		{
			all.width = all.width - len;
			while (i++ < all.width)
				write(1, &c, 1);
		}
}

void		ft_space(char *str, t_print all)
{
	if (str[0] != '-')
		write(1, " ", 1);
}

//modifying d, i and u without h, hh, l and ll
t_print		ft_modify_int(t_print all, va_list ap)
{
	char	*num_str;
	int		i;
	int		num;

	num = va_arg(ap, int);
	i = 0;
	if (!(num_str = ft_itoa(num)))
		return (all); //error
	if (all.minus == 1)
		ft_putstr(num_str);
	if (all.width != 0 && !all.zero)
		ft_fill_width(ft_strlen(num_str), all, ' ');
	if ((all.width != 0 && all.zero == 1) || all.precision != 0)
		ft_fill_width(ft_strlen(num_str), all, '0');
	if (all.minus == 0)
		ft_putstr(num_str);
	all.count = ft_strlen(num_str) + all.width;
	free(num_str);
	return (all);
}

t_print		ft_number(t_print all, va_list ap)
{
	if ((all.type == 'i' || all.type == 'd' || all.type == 'u') && !all.h &&
			!all.hh && !all.l && !all.ll)
		ft_modify_int(all, ap);
	if ...
	return (all);
}

t_print		ft_print(t_print all, va_list ap)
{
	if (all.type == 'i' || all.type == 'd' || all.type == 'u' ||
			all.type == 'o' || all.type == 'x' || all.type == 'X') //ints
		all = ft_number(all, ap);
	if (all.type == 's') //string
		all = ft_string(all, ap);
	if (all.type == 'c') //char
		all = ft_char(all, ap);
	if (all.type == 'f') //float
		all = ft_float(all, ap);
	if (all.type == 'p') //pointer
		all = ft_pointer(all, ap);
	return (all);
}
