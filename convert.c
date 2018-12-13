/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaskeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 18:51:39 by svaskeli          #+#    #+#             */
/*   Updated: 2018/12/13 13:01:30 by svaskeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_negative(char *num_str, t_print *all)
{
	if (all->sign)
		num_str = ft_strjoin("-", num_str);
	all->print_negative = 1;
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
		if (all->sign && !all->minus && !all->zero)
			num_str = ft_negative(num_str, all);
		if ((all->sign || ((all->sharp || all->plus || all->space) && (all->minus ||
							all->zero))))
		{
			if (all->sharp && all->type != 'o')
				all->width--;
			all->width--;
		}
		all->width = all->width - i;
		str = ft_build_width(all, c);
		if (all->minus)
			num_str = ft_strjoin(num_str, str);
		else
			num_str = ft_strjoin(str, num_str);
	}
	else if (all->type == 'f')
			num_str = ft_negative(num_str, all);
	free(str);
	return (num_str);
}

char		*ft_int_plus(char *num_str, t_print *all)
{
	if (!all->sign && all->type != 'u')
	{
		if (all->plus)
			num_str = ft_strjoin("+", num_str);
		else if (all->space && !all->plus)
			num_str = ft_strjoin(" ", num_str);
	}
	if (all->sharp && all->type == 'x' && !all->hex_o_zero && !all->num_zero)
		num_str = ft_strjoin("0x", num_str);
	else if (all->sharp && all->type == 'X' && !all->hex_o_zero && !all->num_zero)
		num_str = ft_strjoin("0X", num_str);
	else if (all->sharp && all->type == 'o' && !all->hex_o_zero)
		num_str = ft_strjoin("0", num_str);
	return (num_str);
}

char		*ft_precision(char *num_str, t_print *all)
{
	char	*str;
	int		i;

	str = NULL;
	if ((i = ft_strlen(num_str)) < all->precision && !(all->type == 's'))
	{
		if (!(str = (char*)malloc(sizeof(char) * (all->precision + 1))))
			return (str); //ft_error
		all->precision = all->precision - i;
		i = 0;
		while (i < all->precision)
			str[i++] = '0';
		str[i] = '\0';
		num_str = ft_strjoin(str, num_str);
	}
	if (all->type == 's' && all->precision)
	{
		str = ft_strdup(num_str);
		str[all->precision] = '\0';
		num_str = str;
		//strndup??
	}
	return (num_str);
}

void		ft_justify(char *num_str, t_print *all)
{
	if (all->precision)
		num_str = ft_precision(num_str, all);
	if (!all->minus && (all->plus || all->sharp || all->space) && !all->zero)
		num_str = ft_int_plus(num_str, all);
	if (all->width && !all->zero)
		num_str = ft_fill_width(num_str, all, ' ');
	else if (all->width && all->zero)
		num_str = ft_fill_width(num_str, all, '0');
	if ((all->minus || all->zero || all->prec_set || all->precision) && (!all->width || all->zero))
		num_str = ft_negative(num_str, all);
	if ((all->minus && (all->plus || all->sharp || all->space)) || all->zero)
		num_str = ft_int_plus(num_str, all);
	if (all->sign && !all->print_negative)
		num_str = ft_negative(num_str, all);
	if (all->type == 'c' && *num_str == '\0')
	{
		ft_putchar('\0');
		all->printed++;
	}
	else
		ft_putstr(num_str);
	all->printed = all->printed + ft_strlen(num_str);
}

void		ft_int(t_print *all, va_list ap)
{
	long long	num;
	char		*num_str;

	if (all->l)
		num = (long long)va_arg(ap, long);
	else if (all->ll)
		num = va_arg(ap, long long);
	else
		num = (long long)va_arg(ap, int);
	if (num < 0)
	{
		all->sign = 1;
		num = -num;
	}
	if (all->type == 'd' && !all->precision && all->prec_set && num == 0)
		num_str = ft_strdup("");
	else
		num_str = ft_itoa_mod(num);
		//ft_error
	ft_justify(num_str, all);
	free(num_str);
}

void		ft_unsigned(t_print *all, va_list ap)
{
	unsigned long long	num;
	char				*num_str;

	if (all->l)
		num = (unsigned long long)va_arg(ap, unsigned long);
	else if (all->ll)
		num = va_arg(ap, unsigned long long);
	else
		num = (unsigned long long)va_arg(ap, unsigned int);
	num_str = ft_itoa_unsigned(num);
		//ft_error
	ft_justify(num_str, all);
	free(num_str);
}

void		ft_int_octal(t_print *all, va_list ap)
{
	unsigned long long	num;
	char				*num_str;

	if (all->l)
		num = (unsigned long long)va_arg(ap, unsigned long);
	else if (all->ll)
		num = va_arg(ap, unsigned long long);
	else
		num = (unsigned long long)va_arg(ap, unsigned int);
	if (!all->hex_o_zero || all->sharp)
		num_str = ft_itoa_base(num, 8, all->type);
			//ft_error
	else
		num_str = ft_strdup("");
			//ft_error
	ft_justify(num_str, all);
	free(num_str);
}

void		ft_int_hex(t_print *all, va_list ap)
{
	unsigned long long	num;
	char				*num_str;

	if (all->l)
		num = (unsigned long long)va_arg(ap, unsigned long);
	else if (all->ll)
		num = va_arg(ap, unsigned long long);
	else
		num = (unsigned long long)va_arg(ap, unsigned int);
	if (num == 0)
		all->num_zero = 1;
	if (!all->hex_o_zero)
		num_str = ft_itoa_base(num, 16, all->type);
			//ft_error
	else
		num_str = ft_strdup("");
	ft_justify(num_str, all);
	free(num_str);
}

void		ft_number(t_print *all, va_list ap)
{
	if (all->type == 'i' || all->type == 'd')
		ft_int(all, ap);
	else if (all->type == 'u')
		ft_unsigned(all, ap);
	else if (all->type == 'o')
		ft_int_octal(all, ap);
	else if (all->type == 'x' || all->type == 'X')
		ft_int_hex(all, ap);
}

void		ft_pointer(t_print *all, va_list ap)
{
	unsigned long long	num;
	char				*num_str;

	num = (unsigned long long)va_arg(ap, void*);
	num_str = ft_itoa_base(num, 16, 'x');
		//ft_error
	num_str = ft_strjoin("0x", num_str);
	ft_justify(num_str, all);
	free(num_str);
}

void		ft_double(t_print *all, va_list ap)
{
	long double	num;
	char		*num_str;

	num = (long double)va_arg(ap, double);
	num_str = ft_itoa_double(num, all);
		//error
	num_str = ft_precision_float(num_str, all);
	ft_justify(num_str, all);
	free(num_str);
}

void		ft_float(t_print *all, va_list ap)
{
	float		num;
	long double long_num;
	char		*num_str;

	num = 0;
	long_num = 0;
	if (!all->long_float)
	{
		num = (float)va_arg(ap, double);
		num_str = ft_itoa_float(num, all);
			//error
		num_str = ft_precision_float(num_str, all);
		ft_justify(num_str, all);
		free(num_str);
	}
	else if (all->long_float)
	{
		long_num = (long double)va_arg(ap, double);
		num_str = ft_itoa_double(long_num, all);
			//error
		num_str = ft_precision_float(num_str, all);
		ft_justify(num_str, all);
		free(num_str);
	}
}

void		ft_long_double(t_print *all, va_list ap)
{
	long double	num;
	char		*num_str;

	num = 0;
	num = va_arg(ap, long double);
	num_str = ft_itoa_double(num, all);
		//error
	num_str = ft_precision_float(num_str, all);
	ft_justify(num_str, all);
	free(num_str);
}

void		ft_floating(t_print *all, va_list ap)
{
	if (all->l)
		ft_double(all, ap);
	else if (all->L)
		ft_long_double(all, ap);
	else if (!all->l && !all->L)
		ft_float(all, ap);
}

void		ft_print(t_print *all, va_list ap)
{
	if (all->type == 'i' || all->type == 'd' || all->type == 'u' ||
			all->type == 'o' || all->type == 'x' || all->type == 'X')
		ft_number(all, ap);
	else if (all->type == 's')
		ft_string(all, ap);
	else if (all->type == 'c')
		ft_char(all, ap);
	else if (all->type == '%')
		ft_char(all, ap);
	else if (all->type == 'f')
		ft_floating(all, ap);
	else if (all->type == 'p')
		ft_pointer(all, ap);
}
