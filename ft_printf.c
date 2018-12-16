/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 13:57:46 by dfinnis           #+#    #+#             */
/*   Updated: 2018/12/15 14:23:30 by svaskeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init(t_print *all)
{
	all->printed = 0;
	all->len = 0;
	all->form = NULL;
	ft_init_partial(all);
}

void	ft_init_partial(t_print *all)
{
	all->type = '0';
	all->hh = 0;
	all->h = 0;
	all->j = 0;
	all->ll = 0;
	all->l = 0;
	all->L = 0;
	all->z = 0;
	all->sharp = 0;
	all->zero = 0;
	all->minus = 0;
	all->plus = 0;
	all->space = 0;
	all->width = 0;
	all->precision = 0;
	all->prec_set = 0;
	all->float_multi = 0;
	all->sign = 0;
	all->long_float = 0;
	all->hex_o_zero = 0;
	all->num_zero = 0;
	all->char_zero = 0;
	all->print_negative = 0;
	all->print_plus = 0;
	all->wild_width = 0;
	all->wild_prec = 0;
}

int		ft_printf(char const *format, ...)
{
	va_list			ap;
	t_print			all;

	va_start(ap, format);
	ft_init(&all);
	all.form = ft_strdup(format);
	while (all.form[all.len] != '\0')
	{
		if (all.form[all.len] == '%')
		{
			all.len++;
			ft_parse(&all, ap);
			ft_print(&all, ap);
			ft_init_partial(&all);
		}
		else
		{
			ft_putchar(all.form[all.len]);
			all.printed++;
			all.len++;
		}
	}
	va_end(ap);
	return (all.printed);
}
