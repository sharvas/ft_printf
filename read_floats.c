/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_floats.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 18:56:11 by dfinnis           #+#    #+#             */
/*   Updated: 2018/12/18 17:21:13 by svaskeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//#include <stdio.h>

void		ft_double(t_print *all, va_list ap)
{
	long double	num;
	char		*num_str;

	num = (long double)va_arg(ap, double);
//	printf("number = %.20Lf\n", num);
	num_str = ft_itoa_double(num, all);
//	printf("str = %s\n", num_str);
	num_str = ft_precision_float(num_str, all);
	ft_justify(num_str, all);
}

/*void		ft_float(t_print *all, va_list ap)
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
}*/

void		ft_long_double(t_print *all, va_list ap)
{
	long double	num;
	char		*num_str;

	num = va_arg(ap, long double);
	num_str = ft_itoa_double(num, all);
	num_str = ft_precision_float(num_str, all);
	ft_justify(num_str, all);
}

void		ft_float_type(t_print *all, va_list ap)
{
//	if (all->l)
//		ft_double(all, ap);
	if (all->L)
		ft_long_double(all, ap);
	else
		ft_double(all, ap);
}
