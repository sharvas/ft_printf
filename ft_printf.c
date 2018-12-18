/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 13:57:46 by dfinnis           #+#    #+#             */
/*   Updated: 2018/12/17 12:57:55 by svaskeli         ###   ########.fr       */
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
	all->up_l = 0;
	all->z = 0;
	all->hash = 0;
	all->zero = 0;
	all->minus = 0;
	all->plus = 0;
	all->space = 0;
	all->width = 0;
	all->precision = 0;
	all->prec_set = 0;
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

void	ft_parse(t_print *all, va_list ap)
{
	while (all->form[all->len] &&
		ft_strchr("+- #0123456789.hlLjz*", all->form[all->len]))
	{
		ft_update_flags(all);
		ft_update_width(all, ap);
		ft_update_precision(all, ap);
		ft_update_length(all);
	}
	ft_update_type(all);
	ft_update_upcase(all);
	ft_update_conflicts(all);
}

void	ft_type_switch(t_print *all, va_list ap)
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
	else if (all->type == 'p')
		ft_pointer(all, ap);
	else if (all->type == 'f')
		ft_float_type(all, ap);
}

int		ft_printf(char const *format, ...)
{
	va_list			ap;
	t_print			all;

	va_start(ap, format);
	ft_init(&all);
	if (!(all.form = ft_strdup(format)))
		ft_error(NULL);
	while (all.form[all.len] != '\0')
	{
		if (all.form[all.len] == '%')
		{
			all.len++;
			ft_parse(&all, ap);
			ft_type_switch(&all, ap);
			ft_init_partial(&all);
		}
		else
		{
			ft_putchar(all.form[all.len++]);
			all.printed++;
		}
	}
	free(all.form);
	va_end(ap);
	return (all.printed);
}
