/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 14:03:46 by dfinnis           #+#    #+#             */
/*   Updated: 2018/12/17 14:03:47 by dfinnis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_istype(char c)
{
	return (c == 'c' || c == 'd' || c == 'e' || c == 'f' || c == 'g' ||
		c == 'i' || c == 'o' || c == 'p' ||  c == 's' || c == 'u' ||
		c == 'x' || c == 'X' || c == '%');
}// S, C, R and Z??

void	ft_update_type(t_print *all)
{
	if (ft_istype(all->form[all->len]))
		all->type = all->form[all->len++];
}

void	ft_update_upcase(t_print *all)
{
	if (all->form[all->len] == 'D')
	{
		all->type = 'd';
		all->l = 1;
		all->len++;
	}
	if (all->form[all->len] == 'O')
	{
		all->type = 'o';
		all->l = 1;
		all->len++;
	}
	if (all->form[all->len] == 'U')
	{
		all->type = 'u';
		all->l = 1;
		all->len++;
	}
	if (all->form[all->len] == 'F')
	{
		all->type = 'f';
		all->len++;
	}
}

void	ft_update_conflicts(t_print *all)
{
	if (all->minus)
		all->zero = 0;
	if (all->type == '%' || all->type == 'c')
	{
		all->space = 0;
		all->precision = 0;
	}
	if (all->type == 's')
		all->space = 0;
	if ((all->type == 'x' || all->type == 'X' || all->type == 'o')
		&& all->prec_set && !all->precision)
		all->hex_o_zero = 1;
	if ((all->type == 'd' || all->type == 'i')
		&& all->prec_set && !all->wild_prec)
		all->zero = 0;
	if (all->type == 'f' && all->prec_set == 0)
		all->precision = 6;
	if (all->type == 'f' && all->precision > 7)
		all->long_float = 1;
	if (all->type == 'f' && all->precision > 15)
		all->float_multi = 15;
	else if (all->type == 'f' && all->precision < 16)
		all->float_multi = all->precision;
}
