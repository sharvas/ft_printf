/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaskeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 18:51:39 by svaskeli          #+#    #+#             */
/*   Updated: 2018/12/08 15:14:37 by svaskeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_negative(char *num_str, t_print *all)
{
	if (all->sign)
		num_str = ft_strjoin("-", num_str);
	return (num_str);
}

char		*ft_build_width(t_print *all, char c)
{
	char	*str;
	int 	i;
	
	i = 0;
	if (!(str = (char*)malloc(sizeof(char) * (all->width + 1))))
		return (str); //ft_error
	while (i < all->width)
		str[i++] = c;
	str[i] = '\0';
	return (str);
}

char		*ft_fill_width(char *num_str, t_print *all, char c)
{
	int		i;
	char	*str;

	str = NULL;
	if ((i = ft_strlen(num_str)) < all->width)
	{
		if (all->sign && !all->minus && !all->zero && all->precision < 0)
			num_str = ft_negative(num_str, all);
		if ((all->sign || ((all->plus || all->space) && (all->minus ||
							all->zero))) && all->precision < 0)
			all->width--;
		all->width = all->width - i;
		str = ft_build_width(all, c);
		if (all->minus)
			num_str = ft_strjoin(num_str, str);
		else
			num_str = ft_strjoin(str, num_str);
	}
	free(str);
	return (num_str);
}

char		*ft_int_plus(char *num_str, t_print *all)
{
	if (!all->sign)
	{
		if (all->plus)
			num_str = ft_strjoin("+", num_str);
		if (all->space && !all->plus)
			num_str = ft_strjoin(" ", num_str);
	}
	return (num_str);
}

void		ft_justify(char *num_str, t_print *all)
{
	if (!all->minus && (all->plus || all->space) && !all->zero &&
			all->precision < 0)
		num_str = ft_int_plus(num_str, all);
	if (all->width && !all->zero && all->precision < 0)
		num_str = ft_fill_width(num_str, all, ' ');
	else if ((all->width && all->zero) || all->precision > 0)
		num_str = ft_fill_width(num_str, all, '0');
	if (all->minus || all->zero || all->precision > 0)
		num_str = ft_negative(num_str, all);
	if ((all->minus && (all->plus || all->space)) || all->zero ||
			all->precision > 0)
		num_str = ft_int_plus(num_str, all);
	ft_putstr(num_str);
	all->printed = all->printed + ft_strlen(num_str);
}

void		ft_int(t_print *all, va_list ap)
{
	long long	num;
	char		*num_str;

/*	if (all.l)
		num = (long long)va_arg(ap, long);
	else if (all.ll)
		num = (long long)va_arg(ap, long long);
	else if (all.h)
		num = (long long)va_arg(ap, int);
	else if (all.hh)
		num = (long long)va_arg(ap, int);
	else*/
		num = (int)va_arg(ap, int);
	if (num < 0)
	{
		all->sign = 1;
		num = -num;
	}
	num_str = ft_itoa(num);
		//ft_error
	ft_justify(num_str, all);
	free(num_str);
}

void		ft_number(t_print *all, va_list ap)
{
	if (all->type == 'i' || all->type == 'd')
		ft_int(all, ap);
/*	if (all.type == 'u')
		ft_unsigned(all, ap);
	if (all.type == 'o')
		ft_int_octal(all, ap);
	if (all.type == 'x' || all.type == 'X')
		ft_int_hex(all, ap);
*/
}

void		ft_print(t_print *all, va_list ap)
{
	if (all->type == 'i' || all->type == 'd' || all->type == 'u' ||
			all->type == 'o' || all->type == 'x' || all->type == 'X')
		ft_number(all, ap);
/*	if (all.type == 's')
		ft_string(all, ap);
	if (all.type == 'c')
		ft_char(all, ap);
	if (all.type == 'f')
		ft_float(all, ap);
	if (all.type == 'p')
		ft_pointer(all, ap);*/
}
