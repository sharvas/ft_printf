/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 15:04:26 by dfinnis           #+#    #+#             */
/*   Updated: 2018/12/08 15:06:04 by svaskeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_isflag(char c)
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

void	ft_update_precision(t_print *all)
{
	unsigned int	n;
	unsigned int	count;
	unsigned int	multi;

	multi = 1;
	if (all->form[all->len] == '.')
		all->len++;
	else
		return ;
	n = all->len;
	while (ft_isdigit(all->form[n]))
		n++;
	all->precision = 0;
	all->prec_set = 0;
	count = n - all->len;
	if (count)
		all->prec_set = 1;
	while (n-- > all->len)
	{
		all->precision = all->precision + (all->form[n] - 48) * multi;
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
	ft_update_conflicts(all);
}
