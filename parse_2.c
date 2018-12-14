/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 10:20:58 by dfinnis           #+#    #+#             */
/*   Updated: 2018/12/14 14:01:17 by svaskeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_islength(char c)
{
	if (c == 'h' || c == 'j' || c == 'l' || c == 'L' || c == 'z')
		return (1);
	return (0);
}

void	ft_update_length(t_print *all)
{
	if (ft_islength(all->form[all->len]))
	{
		if (all->form[all->len] == 'h')
		{
			if (all->form[all->len + 1] == 'h')
			{
				all->hh = 1;
				all->len++;
			}
			else
				all->h = 1;
		}
		if (all->form[all->len] == 'j')
			all->j = 1;
		if (all->form[all->len] == 'l')
		{
			if (all->form[all->len + 1] == 'l')
			{
				all->ll = 1;
				all->len++;
			}
			else
				all->l = 1;
		}
		if (all->form[all->len] == 'L')
			all->L = 1;
		if (all->form[all->len] == 'z')
			all->z = 1;
		all->len++;
	}
}

int		ft_istype(char c)
{
	if (c == 'c' || c == 'C' || c == 'd' || c == 'e' || c == 'f' ||
		c == 'g' || c == 'i' || c == 'o' || c == 'p' || c == 'S' ||
		c == 's' || c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}
// R and Z??

void	ft_update_type(t_print *all)
{
	if (ft_istype(all->form[all->len]))
		all->type = all->form[all->len++];
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
	if ((all->type == 'x' || all->type == 'X' || all->type == 'o') && all->prec_set && !all->precision)
		all->hex_o_zero = 1;
	if ((all->type == 'd' || all->type == 'i') && all->prec_set)
		all->zero = 0;
	if (all->type == 'f' && all->prec_set == 0)
		all->precision = 6;
	if (all->type == 'f' && all->precision > 7)
		all->long_float = 1;
	if (all->type == 'f' && all->precision > 15)
		all->float_multi = 15;
	else if (all->type == 'f' && all->precision < 16)
		all->float_multi = all->precision;

	// if (all->width)
	// 	all->wildcard = 0;
	// if (ft_istype(all->type) && all->type != 'c' && all->type != 'C' &&
	// 	all->type != 's' && all->type != 'S' && all->type != 'f' &&
	// 	all->type != 'p' && all->precision != -6)
	// 	all->width = all->precision;
}

/*int	main(void)
{
	char	*form;
	t_print	all;
	int		i;

	i = 0;
	form = "+5.7ld. string";
	ft_init(&all);
	all.form = form;
	all.len = i;
	printf("Before Parse:\n");
	ft_print_struct(&all);
	ft_parse(&all);
	printf("\nAfter Parse:\n");
	ft_print_struct(&all);
	return (0);
}*/
