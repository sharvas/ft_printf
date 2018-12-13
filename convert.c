/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaskeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 18:51:39 by svaskeli          #+#    #+#             */
/*   Updated: 2018/12/13 15:45:09 by svaskeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	// if (all->type == 'c')
	// {
	// 	while (*num_str && *num_str != '\0')
	// 	{
	// 		ft_putchar(*num_str);
	// 		num_str++;
	// 		all->printed++;
	// 	}
	// 	if (*num_str == '\0')
	// 	{
	// 		ft_putchar('\0');
	// 		all->printed++;
	// 	}
	// 	while (*num_str && *num_str != '\0')
	// 	{
	// 		ft_putchar(*num_str);
	// 		num_str++;
	// 		all->printed++;
	// 	}
	// }
	if (all->type == 'c' && *num_str == '\0')
	{
//		ft_putstr(num_str);
//		if (*num_str == '\0')
		ft_putchar('\0');
		all->printed++;
	}
	else
		ft_putstr(num_str);
	all->printed = all->printed + ft_strlen(num_str);
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
