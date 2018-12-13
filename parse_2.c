/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 10:20:58 by dfinnis           #+#    #+#             */
/*   Updated: 2018/12/13 16:22:33 by svaskeli         ###   ########.fr       */
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
	if (all->minus && all->zero)
		all->zero = 0;
	if (all->type == 'f' && all->prec_set == 0)
		all->precision = 6;
	if (all->type == '%' && all->space == 1)
		all->space = 0;
	if (all->type == 'f' && all->precision > 7)
		all->long_float = 1;
	if ((all->type == 'x' || all->type == 'X' || all->type == 'o') && all->prec_set && !all->precision)
		all->hex_o_zero = 1;
	if (all->type == 'c')
	{
		all->space = 0;
		all->precision = 0;
	}
	if ((all->type == 'd' || all->type == 'i') && all->zero && all->prec_set)
		all->zero = 0;
	if (all->type == 's')
	{
		all->space = 0;
	}
	// if (ft_istype(all->type) && all->type != 'c' && all->type != 'C' &&
	// 	all->type != 's' && all->type != 'S' && all->type != 'f' &&
	// 	all->type != 'p' && all->precision != -6)
	// 	all->width = all->precision;
}

// void	ft_print_struct(t_print *all)//
// {//
// 	printf("\tprinted: %d\n", all->printed);
// 	printf("\tlen: %d\n", all->len);
// 	printf("\tform: %s\n", all->form);
// 	printf("\ttype: %c\n", all->type);
// 	printf("\thh: %d\n", all->hh);
// 	printf("\th: %d\n", all->h);
// 	printf("\tj: %d\n", all->j);
// 	printf("\tll: %d\n", all->ll);
// 	printf("\tl: %d\n", all->l);
// 	printf("\tL: %d\n", all->L);
// 	printf("\tz: %d\n", all->z);
// 	printf("\tsharp: %d\n", all->sharp);
// 	printf("\tzero: %d\n", all->zero);
// 	printf("\tminus: %d\n", all->minus);
// 	printf("\tplus: %d\n", all->plus);
// 	printf("\tspace: %d\n", all->space);
// 	printf("\twidth: %d\n", all->width);
// 	printf("\tprecision: %d\n", all->precision);
// 	printf("\tsign: %d\n", all->sign);
// }//

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
