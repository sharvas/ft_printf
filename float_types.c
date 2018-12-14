/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_types.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaskeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 12:44:59 by svaskeli          #+#    #+#             */
/*   Updated: 2018/12/14 13:43:31 by svaskeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
//	float		num;
	long double long_num;
	char		*num_str;

	long_num = va_arg(ap, double);
/*	if (!all->long_float)
	{
		num = (float)long_num;
		num_str = ft_itoa_float(num, all);
			//error
		num_str = ft_precision_float(num_str, all);
		ft_justify(num_str, all);
		free(num_str);
	}
	else if (all->long_float)
	{*/
		num_str = ft_itoa_double(long_num, all);
			//error
		num_str = ft_precision_float(num_str, all);
		ft_justify(num_str, all);
		free(num_str);
//	}
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
