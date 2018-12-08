/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 15:04:26 by dfinnis           #+#    #+#             */
/*   Updated: 2018/12/05 15:04:28 by dfinnis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_init(t_print *all)
{
	all->printed = 0;
	all->len = 0;
	all->form = 0;
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
	all->precision = -6;
	all->sign = 0;
}

int	ft_isflag(char c)
{
	if (c == '+' || c == '-' || c == ' ' || c == '0' || c == '#')
		return (1);
	return (0);
}

void	ft_update_flags(t_print *all)
{
	while (ft_isflag(all->form[all->len]))
	{
		if (all->form[all->len] == '+')
			all->plus = 1;
		if (all->form[all->len] == '-')
			all->minus = 1;
		if (all->form[all->len] == ' ')
			all->space = 1;
		if (all->form[all->len] == '0')
			all->zero = 1;
		if (all->form[all->len] == '#')
			all->sharp = 1;
		all->len++;
	}
}

void	ft_update_width(t_print *all)
{
	unsigned int	n;
	unsigned int	count;
	unsigned int	multi;

	multi = 1;
	n = all->len;
	while (ft_isdigit(all->form[n]))
		n++;
	count = n - all->len;
	while (n-- > all->len)
	{
		all->width = all->width + (all->form[n] - 48) * multi;
		multi *= 10;
	}
	all->len += count;
}

void	ft_parse(t_print *all)
{
	while (all->form[all->len] &&
		ft_strchr("+- 0#123456789.hlLjz", all->form[all->len]))
	{
		ft_update_flags(all);
		ft_update_width(all);
		ft_update_precision(all);
		ft_update_length(all);
	}
	ft_update_type(all);
}