/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaskeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 18:51:39 by svaskeli          #+#    #+#             */
/*   Updated: 2018/12/06 18:08:16 by svaskeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_fill_width(char *num_str, t_print all, char c)
{
	int i;
	int len;
	char *tmp;

	i = 0;
	len = 0;
	if ((len = ft_strlen(num_str)) < all.width)
	{
		if (all.sign < 0 || all.plus || all.space)
			all.width--;
		all.width = all.width - len;
		tmp = (char*)malloc(sizeof(char) * (all.width + 1));
			//ft_error(all);
		while (i < all.width)
			tmp[i++] = c;
		tmp[i] = '\0';
		if (all.minus == 1)
			num_str = ft_strjoin(num_str, tmp);
		else
		{
			num_str = ft_strjoin(tmp, num_str);
			if (all.space && all.sign > 0)
				num_str = ft_strjoin(" ", num_str);
		}
		if (all.sign < 0)
			num_str = ft_strjoin("-", num_str);
		if (all.plus && !all.minus && all.sign > 0)
			num_str = ft_strjoin("+", num_str);
	}
	return (num_str);
}

char		*ft_intplus(char *num_str, t_print all)
{
	if (all.sign > 0)
	{
		if (all.plus && all.minus)
			num_str = ft_strjoin("+", num_str);
		if (all.space && all.minus)
			num_str = ft_strjoin(" ", num_str);
	}
	return (num_str);
}

t_print		ft_justify(char *num_str, t_print all)
{	
	if (all.minus == 0)
	{
		if (all.plus || all.space) //flags: + and space
			num_str = ft_intplus(num_str, all);
	}
	if (all.width != 0 && !all.zero)
		num_str = ft_fill_width(num_str, all, ' ');
	if ((all.width != 0 && all.zero == 1) || all.precision)
		num_str = ft_fill_width(num_str, all, '0');
	if (all.minus == 1)
	{
		if (all.plus || all.space) //flags: + and space
			num_str = ft_intplus(num_str, all);
	}
	ft_putstr(num_str);
	all.count = all.count + ft_strlen(num_str);
	return (all);
}

//modifying d, i and u without h, hh, l and ll
t_print		ft_modify_int(t_print all, va_list ap)
{
	char	*num_str;
	int	num;

	num = va_arg(ap, int);
	if (num < 0)
	{
		all.sign = -1;
		num = -num;
	}
	if (!(num_str = ft_itoa(num)))
		return (all); //ft_errori
	if (all.minus || all.zero || all.width) //flags: 0, -, min_width
		all = ft_justify(num_str, all);
	free(num_str);
	return (all);
}

t_print		ft_int(t_print all, va_list ap)
{
/*	if (all.l)
		ft_long_int(all, ap);//to write
	else if (all.ll)
		ft_long_long_int(all, ap);//to write
	else if (all.h)
		ft_short_int(all, ap);//to write
	else if (all.hh)
		ft_unsigned_int(all, ap);//to write
	else*/
		all = ft_modify_int(all, ap);
	return (all);
}

t_print		ft_number(t_print all, va_list ap)
{
	if (all.type == 'i' || all.type == 'd' || all.type == 'u')
		all = ft_int(all, ap);
/*	if (all.type == 'o')
		ft_int_octal(all, ap);//to write
	if (all.type == 'x' || all.type == 'X')
		ft_int_hex(all, ap);//to write
	if (all.type =='f')
		ft_int_float(all, ap);//to write*/
	return (all);
}

t_print		ft_print(t_print all, va_list ap)
{
	if (all.type == 'i' || all.type == 'd' || all.type == 'u' ||
			all.type == 'o' || all.type == 'x' || all.type == 'X') //ints
		all = ft_number(all, ap);
/*	if (all.type == 's') //string
		all = ft_string(all, ap);
	if (all.type == 'c') //char
		all = ft_char(all, ap);
	if (all.type == 'f') //float
		all = ft_float(all, ap);
	if (all.type == 'p') //pointer
		all = ft_pointer(all, ap);*/
	return (all);
}
