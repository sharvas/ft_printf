/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_types.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaskeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 12:44:59 by svaskeli          #+#    #+#             */
/*   Updated: 2018/12/17 17:45:18 by svaskeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_double(t_print *all, va_list ap)
{
	long double	num;
	char		*num_str;

	num = (long double)va_arg(ap, double);
	num_str = ft_itoa_double(num, all);
	num_str = ft_precision_float(num_str, all);
	ft_justify(num_str, all);
}

void		ft_float(t_print *all, va_list ap)
{
	float	num;
	double	long_num;
	char	*num_str;

	long_num = va_arg(ap, double);
	if ((intmax_t)long_num > 1000 || (intmax_t)long_num < -1000)
		all->long_float = 1;
	if (!all->long_float)
	{
		num = (float)long_num;
		num_str = ft_itoa_float(num, all);
		num_str = ft_precision_float(num_str, all);
		ft_justify(num_str, all);
	}
	else if (all->long_float)
	{
		num_str = ft_itoa_double(long_num, all);
		num_str = ft_precision_float(num_str, all);
		ft_justify(num_str, all);
	}
}

void		ft_long_double(t_print *all, va_list ap)
{
	long double	num;
	char		*num_str;

	num = va_arg(ap, long double);
	num_str = ft_itoa_double(num, all);
	num_str = ft_precision_float(num_str, all);
	ft_justify(num_str, all);
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
