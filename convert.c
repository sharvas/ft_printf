/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaskeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 18:51:39 by svaskeli          #+#    #+#             */
/*   Updated: 2018/12/06 17:02:33 by svaskeli         ###   ########.fr       */
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

void		ft_justif(char *num_str, t_print all)
{
	if (all.minus == 1)
		ft_putstr(num_str);
	if (all.width != 0 && !all.zero)
		ft_fill_width(ft_strlen(num_str), all, ' ');
	if ((all.width != 0 && all.zero == 1) || all.precision)
		ft_fill_width(ft_strlen(num_str), all, '0');
	if (all.minus == 0)
		ft_putstr(num_str);
	all.count = all.count + ft_strlen(num_str) + all.width;
}

void		ft_intplus(char *num_str, t_print all)
{
	if (num_str[0] =! '-')
	{
		if (all.plus)
			write(1, "+", 1);
		if (all.space)
			write(1, " ", 1);
		all.count++;
	}
	ft_putstr(num_str);
	all.count = all.count + ft_strlen(num_str);
}

//modifying d, i and u without h, hh, l and ll
t_print		ft_modify_int(t_print all, va_list ap)
{
	char	*num_str;
	int		num;

	num = va_arg(ap, int);
	if (!(num_str = ft_itoa(num)))
		return (all); //ft_error
	if (!all.plus || !all.space) //flags: + and space
		ft_intplus(num_str, all);
	if (!all.minus || !all.zero || !all.width) //flags: 0, -, min_width
		ft_justif(num_str, all);
	free(num_str);
	return (all);
}

void		ft_int(t_print all, va_list ap)
{
	if (all.l)
		ft_long_int(all, ap);//to write
	else if (all.ll)
		ft_long_long_int(all, ap);//to write
	else if (all.h)
		ft_short_int(all, ap);//to write
	else if (all.hh)
		ft_unsigned_int(all, ap);//to write
	else
		ft_modify_int(all, ap);
}

t_print		ft_number(t_print all, va_list ap)
{
	if (all.type == 'i' || all.type == 'd' || all.type == 'u')
		ft_int(all, ap);
	if (all.type == 'o')
		ft_int_octal(all, ap);
	if (all.type == 'x' || all.type == 'X')
		ft_int_hex(all, ap);
	if (all.type =='f')
		ft_int_float(all, ap);
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
