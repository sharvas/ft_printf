/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 15:04:26 by dfinnis           #+#    #+#             */
/*   Updated: 2018/12/13 17:57:46 by svaskeli         ###   ########.fr       */
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
	{
		all->len++;
		all->prec_set = 1;
	}
	else
		return ;
	n = all->len;
	while (ft_isdigit(all->form[n]))
		n++;
	count = n - all->len;
	while (n-- > all->len)
	{
		all->precision = all->precision + (all->form[n] - 48) * multi;
		multi *= 10;
	}
	all->len += count;
}

void	ft_update_DOUF(t_print *all)
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

void	ft_parse(t_print *all)
{
	while (all->form[all->len] &&
		ft_strchr("+- #0123456789.hlLjz", all->form[all->len]))
	{
		ft_update_flags(all);
		ft_update_width(all);
		ft_update_precision(all);
		ft_update_length(all);
	}
	ft_update_DOUF(all);
	ft_update_type(all);
	ft_update_conflicts(all);
}
